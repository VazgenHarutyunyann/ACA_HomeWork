#include <iostream>

#include "vector.hpp"

int main()
{
    Vector<int> vec(1, 2, 3, 4, 5);
    vec.print();

    vec.push_back(10);
    vec.push_back(20);
    vec.print();

    return 0;

}