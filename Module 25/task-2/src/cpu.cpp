#include "cpu.h"
#include "ram.h"
#include <iostream>

int sum (){
    int sum = 0;
    for (int i = 0; i < 8; i++)
        sum += read(i);
    std::cout << sum <<std::endl;
    return 0;
}