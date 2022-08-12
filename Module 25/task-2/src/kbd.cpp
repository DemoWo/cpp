#include "kbd.h"
#include <iostream>
#include <limits>

std::vector<int> input() {
    using namespace std;
    std::vector<int> vec(8);
    std::cout << "input:" << std::endl;
    for ( int i = 0; i < vec.size(); ++i ) {
        if ( !(std::cin >> vec[i]) ) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Error!" << std::endl;
            continue;
        }
    }
    return vec;
}