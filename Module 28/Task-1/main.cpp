#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <mutex>
#include <chrono>

std::vector <std::string> resultSwimmer;
std::mutex resultSwimmer_access;

void save (const std::string& nameSwimmer, int sec)
{
    resultSwimmer_access.lock();
    resultSwimmer.push_back("Name Swimmer: " + nameSwimmer + ", swim time: " + std::to_string(sec) + " second");
    resultSwimmer_access.unlock();
}

void time_Swimmer(int speedSwimmer, int distance, std::string nameSwimmer) {

    int sec = distance / speedSwimmer;
    std::this_thread::sleep_for(std::chrono::seconds(sec));
    std::cout << nameSwimmer << " Finish!" << std::endl;
    save(nameSwimmer, sec);
}

void print_result ()
{
    std::cout << "Finish results: " << std::endl;
    resultSwimmer_access.lock();
    for (int i = 0; i < resultSwimmer.size(); ++i)
    {
        std::cout << i + 1 << ". " << resultSwimmer[i] << std::endl;
    }
    resultSwimmer_access.unlock();
}

int main() {
    int distance = 100;
    std::vector <std::string> nameSwimmer;
    std::vector <int> speedSwimmer;
    std::string inputStr;
    int inputInt;

    for (int i = 0; i < 6; ++i)
    {
        std::cout << "Input name " << i + 1 << " Swimmer!" << std::endl;
        std::cin >> inputStr;
        nameSwimmer.push_back(inputStr);
        std::cout << "Input speed " << i + 1 << " Swimmer!" << std::endl;
        std::cin >> inputInt;
        speedSwimmer.push_back(inputInt);
    }

    std::cout << "Start!" << std::endl;

    for (int i = 0; i < nameSwimmer.size(); ++i)
    {
        inputInt = speedSwimmer[i];
        inputStr = nameSwimmer[i];
        std::thread swimmer(time_Swimmer, inputInt, distance, inputStr);
        if (swimmer.joinable()) swimmer.join();
    }

    print_result();

    return 0;
}
