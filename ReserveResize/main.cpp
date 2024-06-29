#include <iostream>

#include "vector.hpp"

int main() 
{
    Vector<int> vec;
    vec.push_back(4);
    vec.push_back(6);
    vec.push_back(66);

    vec.reserve(10);
    std::cout << "Vector capacity after reserve 10: " << vec.getCapacity() << std::endl;
    std::cout << "Vector size after reserve 10: " << vec.getSize() << std::endl;

    vec.resize(5, 0);
    std::cout << "Vector capacity after resize : 5 : 0 : " << vec.getCapacity() << std::endl;
    std::cout << "Vector size after resize : 5 : 0 : " << vec.getSize() << std::endl;

    vec.print();

    return 0;
}