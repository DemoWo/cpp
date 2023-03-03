#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <mutex>
#include <chrono>

struct SwimResult{
    std::string name;
    int time;
};

std::vector <SwimResult> resultSwimmer;
std::mutex resultSwimmer_access;

void save (const std::string &nameSwimmer, int time)
{
    resultSwimmer_access.lock();
    resultSwimmer.push_back({nameSwimmer, time});
    resultSwimmer_access.unlock();
}

void time_Swimmer(int speedSwimmer, int distance, std::string nameSwimmer) {
    int cur_distance = 0;
    int cur_time = 0;
    while(cur_distance < distance) {
        cur_distance += speedSwimmer;
        cur_time++;
        resultSwimmer_access.lock();
        std::cout << "Swimmer " << nameSwimmer << " swam " << cur_distance << " meters\n";
        resultSwimmer_access.unlock();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::cout << nameSwimmer << " Finish!" << std::endl;
    save(nameSwimmer, cur_time);
}

void print_result ()
{
    std::cout << "Finish results: " << std::endl;
    resultSwimmer_access.lock();
    for (int i = 0; i < resultSwimmer.size(); ++i)
    {
            std::cout << i + 1 << ". Name: " << resultSwimmer[i].name << ". Time: " << resultSwimmer[i].time << std::endl;
    }
    resultSwimmer_access.unlock();
}

int main() {
    int distance = 100;
    int numberOfSwimmers = 6;
    std::vector <std::string> nameSwimmer;
    std::vector <int> speedSwimmer;
    std::string inputStr;
    int inputInt;
    std::thread swimmers[numberOfSwimmers];

    for (int i = 0; i < numberOfSwimmers; ++i)
    {
        std::cout << "Input name " << i + 1 << " Swimmer!" << std::endl;
        std::cin >> inputStr;
        nameSwimmer.push_back(inputStr);
        std::cout << "Input speed " << i + 1 << " Swimmer!" << std::endl;
        std::cin >> inputInt;
        speedSwimmer.push_back(inputInt);
    }

    std::cout << "Start!" << std::endl;


    for (int i = 0; i < numberOfSwimmers; ++i)
    {
        inputInt = speedSwimmer[i];
        inputStr = nameSwimmer[i];
        swimmers[i] = std::thread (time_Swimmer, inputInt, distance, inputStr);

    }

    for (auto & swimmer : swimmers){
        swimmer.join();
    }

    print_result();

    return 0;
}
