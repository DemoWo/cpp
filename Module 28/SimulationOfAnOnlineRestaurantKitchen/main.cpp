#include <iostream>
#include <random>

enum MENU
        {
    pizza = 1,
    soup,
    steak,
    salad,
    sushi,
        };

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
    }
    return nullptr;
}

int main() {

    int i;
    int count = 0;
while (count != 10 )
{
    i = std::rand() % 5 +1;
    std::cout << menuRestaurant(i) << std::endl;
    count ++;
}



    return 0;
}
