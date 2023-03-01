#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <mutex>

std::vector <std::string> resultSwimmer;
std::mutex resultSwimmer_access;

void time_Swimmer(int speedSwimmer, int distance, std::string nameSwimmer)
{
    int sec = distance / speedSwimmer;
    std::this_thread::sleep_for(std::chrono::seconds(sec));
    resultSwimmer_access.lock();
    resultSwimmer.push_back("Name Swimmer: " + nameSwimmer + ", swim time: " + std::to_string(sec) + " second");
    resultSwimmer_access.unlock();
}


void print_result ()
{
    std::cout << "Result: " << std::endl;
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
    std::string inputStr;
    int inputInt;
    std::vector <int> speedSwimmer;


    for (int i = 0; i < 6; ++i)
    {
        std::cout << "Input name " << i + 1 << " Swimmer!" << std::endl;
        std::cin >> inputStr;
        nameSwimmer.push_back(inputStr);
        std::cout << "Input speed " << i + 1 << " Swimmer!" << std::endl;
        std::cin >> inputInt;
        speedSwimmer.push_back(inputInt);
    }

    for (int i = 0; i < nameSwimmer.size(); ++i)
    {
        inputInt = speedSwimmer[i];
        inputStr = nameSwimmer[i];
        std::thread swimmer(time_Swimmer, inputInt, distance, inputStr);
        swimmer.join();
    }


    print_result();

    return 0;
}
