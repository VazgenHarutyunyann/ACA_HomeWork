#include <iostream>

#include "vector.hpp"

int main() {
    Vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);

    try 
    {
        std::cout << "Value at index 1: " << vec.at(1) << std::endl;
        std::cout << "Value at index 2: " << vec.at(2) << std::endl;
    }
    catch (const std::out_of_range& exeption) 
    {
        std::cout << "Caught exception in main: " << exeption.what() << std::endl;
    }

    return 0;
}