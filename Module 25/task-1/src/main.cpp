#include "operation.h"
#include <iostream>

int main()
{
    std::string command;

    while (command != "scalpel")
    {
        std::cout << "Enter command: " << std::endl;
        std::cin >> command;
        if (command == "scalpel")
        {
            std::cout << scalpel(command) << std::endl;
        }
    }

    while(command != "suture")
    {
        std::cout << "Enter command: " << std::endl;
        std::cin >> command;

        if (command == "hemostat")
        {
            std::cout << hemostat(command) << std::endl;
        }
        if (command == "tweezers")
        {
            std::cout << tweezers(command) << std::endl;
        }
        if (command == "suture")
        {
            std::cout << suture(command) << std::endl;
        }
    }
    return 0;
}
