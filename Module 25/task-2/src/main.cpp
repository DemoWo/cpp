#include "cpu.h"
#include "disk.h"
#include "gpu.h"
#include "kbd.h"
#include <iostream>

int main() {

    std::string command;

    while (command != "exit") {
        std::cout << "Enter the command(sum/save/load/input/display/exit): " << std::endl;
        std::cin >> command;

        if (command == "input") {
            input();
        } else if (command == "sum") {
            sum();
        } else if (command == "save") {
            save();
        } else if (command == "load") {
            load();
        } else if (command == "display"){
            display();
        } else if (command != "exit"){
            std::cerr << "Error input!" << std::endl;
        }

    }
    std::cout << "You have exited the program!" << std::endl;
    return 0;
}