#include <iostream>
#include <random>
#include <thread>
#include <mutex>
#include <queue>
#include <vector>

int genRandom(int min, int max) {
    static thread_local std::random_device rd;
    std::uniform_int_distribution<int> uid(min, max);
    return uid(rd);
}

enum MENU
        {
    pizza = 1,
    soup,
    steak,
    salad,
    sushi,
        };

std::queue <int> orders;
std::queue<int> cooked;
std::mutex work_lock;
std::mutex console_access;
int count = 0;
int max = 10;
bool cooking = false;

std::string menuRestaurant  (int cmdMenu)
{
    switch (cmdMenu)
    {
        case MENU::pizza:
            return "Pizza";
        case MENU::soup:
            return "Soup";
        case MENU::steak:
            return "Steak";
        case MENU::salad:
            return  "Salad";
        case MENU::sushi:
            return "Sushi";
        default:
            return "unk";
    }
}

void orderDelivery () //доставка заказа
{
    while (count < max) {
        std::this_thread::sleep_for(std::chrono::seconds(30));
        std::lock_guard<std::mutex> lock{ console_access };
        if (cooked.empty())
            continue;
        auto first = cooked.front();
        std::cout << "Courier picked up " << menuRestaurant(first) << std::endl;
        cooked.pop();
        count++;
    }
}

void orderPreparation ()  // приготовление заказа
{
    while (count < max) {
        int cookingTime = genRandom(5, 15);
        std::this_thread::sleep_for(std::chrono::seconds(cookingTime));
        std::lock_guard<std::mutex> lock{ work_lock };
        if (orders.empty() || cooking) continue;
        cooking = true;
        auto first = orders.front();
        console_access.unlock();
        std::cout << "Order preparation: " << menuRestaurant(first) << "! Through " << cookingTime << " seconds!"
                  << std::endl;
        console_access.lock();
        cooked.push(first);
        orders.pop();
        cooking = false;
    }
}

void order () // заказ
{
    while (count < max) {
        std::this_thread::sleep_for(std::chrono::seconds(genRandom(5, 10)));
        std::lock_guard<std::mutex> lock{work_lock};
        int numOrder = genRandom(1, 5);
        console_access.unlock();
        std::cout << "The order is expected to arrive!" << std::endl;
        console_access.lock();
        orders.push(numOrder);
    }
}

int main() {
    std::thread expectation (order);
    std::thread preparation (orderPreparation);
    std::thread delivery (orderDelivery);
    expectation.join();
    preparation.join();
    delivery.join();
    return 0;
}
