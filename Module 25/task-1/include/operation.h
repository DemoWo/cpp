#pragma once
#include <iostream>

double x,y;

std::string scalpel(std::string word1)
{
    std::cout << "Enter the coordinates of the section:" << std::endl;
    std::cin >> x;
    std::cin >> y;
    return word1 = "A cut was made between the coordinates " + std::to_string(x) + " - " + std::to_string(y);
}

std::string hemostat(std::string word2)
{
    double z;
    std::cout << "Enter the point where you want to install the clamp:" << std::endl;
    std::cin >> z;
    if (z >= x && z <= y)
    {
        return word2 = "The clamp is made at the point " + std::to_string(z);
    }
    else {
        std::cerr << "Error input!" << std::endl;
        return hemostat(word2);
    }

}

std::string tweezers (std::string word3)
{
    double c;
    std::cout << "Enter the point where you want to use the tweezers: " << std::endl;
    std::cin >> c;
    if (c >= x && y <= y)
    {
        return word3 = "Tweezers are used at the point " + std::to_string(c);
    }
    else
    {
        std::cerr << "Error input!" << std::endl;
        return tweezers(word3);
    }

}

std:: string suture (std::string word4)
{
    return word4 = "The needle made a seam between the points " + std::to_string(x) + " - " + std::to_string(y);
}
