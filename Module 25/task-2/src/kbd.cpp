#include "kbd.h"
#include "ram.h"
#include <iostream>
#include <limits>

void input (){
    std::cout <<"Enter 8 numbers: "<< std::endl;
    int x;
    for (int i = 0; i < 8; i++) {
        std::cin >> x;
        write(i, x);
    }
}