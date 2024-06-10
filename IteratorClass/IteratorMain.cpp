#include <iostream>

#include "Iterator.hpp"

int main() 
{
    int arr[] = {5, 2, 10, 4, 7};

    Iterator<int> begin(arr);
    Iterator<int> end(arr + sizeof(arr) / sizeof(arr[0]));

    std::cout << "Array elements: " << std::endl;
    for (Iterator<int> it = begin; it != end; ++it) 
    {
        std::cout << *it << " ";
    }

    return 0;
}