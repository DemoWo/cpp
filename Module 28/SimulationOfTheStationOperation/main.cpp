#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>

struct Train
{
    char nameTrain;
    int time;
};

std::vector <Train> allTrain;
std::vector <Train> station;
std::mutex allTrain_access;

void Station (char name)
{
    allTrain_access.lock();
    station.push_back({name});
    allTrain_access.unlock();
}

void print ()
{
    for (int i = 0; i < station.size(); ++i)
    {
        std::cout << i + 1 << ". a train came to the station under the name: " << station[i].nameTrain << std::endl;
    }
}

void TravelTrain (char name, int time)
{
    std::string cmd;
    int timeTravel = 0;

    while (timeTravel < time)
    {
        timeTravel++;
        allTrain_access.lock();
        std::cout << "Train : " << name << " on the way " << timeTravel << " seconds." << std::endl;
        allTrain_access.unlock();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    allTrain_access.lock();
    std::cout << "Train : " << name << " arrived at the station!" << std::endl;
    allTrain_access.unlock();
    Station(name);
    std::lock_guard<std::mutex> m{ allTrain_access };
    std::cout << "Wait for you command for deport train " << name << std::endl;
    while (cmd != "deport") {
        std::cin >> cmd;
    }
}

int main() {
    int numTrain = 3;
    int travelTime;
    bool endStation = false;

    for (int i = 0; i < numTrain; ++i)
    {
        std::cout << "Enter the travel time " << i + 1 << " train:" << std::endl;
        std::cin >> travelTime;
        allTrain.push_back({static_cast<char>(65 + i), travelTime});
    }

    std::thread train[numTrain];

    for (int i = 0; i < numTrain; ++i)
    {
        train[i] = std::thread (TravelTrain, allTrain[i].nameTrain , allTrain[i].time);
    }

    for (int i = 0; i < numTrain; ++i)
    {
        train[i].join();
    }

    print();

    return 0;
}
