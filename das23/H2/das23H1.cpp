#include <iostream>

#include "vector.hpp"

int main()
{
    Vector<int> vec;

    vec.push_back(1);
    vec.push_back(5);
    vec.push_back(6);

    std::cout << "Vector elements: ";
    for (int i = 0; i < vec.getSize(); ++i)
    {
        std::cout << vec[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}