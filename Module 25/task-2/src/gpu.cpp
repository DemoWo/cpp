#include "gpu.h"
#include "ram.h"
#include <iostream>

void display () {
    for (int i = 0; i < 8; i++) {
        std::cout << read(i) ;
    }
    std::cout <<std::endl;
}