#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <mutex>

std::vector <std::string> resultSwimmer;
std::mutex resultSwimmer_access;

void time_Swimmer(int speedSwimmer, int distance, std::string nameSwimmer)
{
    resultSwimmer_access.lock();
    int sec = distance / speedSwimmer;
    std::this_thread::sleep_for(std::chrono::seconds(sec));
    //std::cout << nameSwimmer << " completed the swim" << std::endl;
    resultSwimmer.push_back("Name Swimmer: " + nameSwimmer + ", swim time: " + std::to_string(sec) + " second");
    resultSwimmer_access.unlock();

}


void print_result ()
{
    resultSwimmer_access.lock();
    for (int i = 0; i <= resultSwimmer.size(); ++i)
    {
        std::cout << i + 1 << ". " << resultSwimmer[i] << std::endl;
    }
    resultSwimmer_access.unlock();
}

int main() {
    int distance = 100;
    std::string nameSwimmer;
    int speedSwimmer;

    for (int i = 0; i < 6; ++i)
    {
        std::cout << "Input name " << i + 1 << " Swimmer!" << std::endl;
        std::cin >> nameSwimmer;
        std::cout << "Input speed " << i + 1 << " Swimmer!" << std::endl;
        std::cin >> speedSwimmer;
        std::thread swimmer(time_Swimmer, speedSwimmer, distance, nameSwimmer);
        swimmer.detach();
    }
    
    std::cout << "Result: " << std::endl;
    std::thread print(print_result);
    print.detach();

    return 0;
}
