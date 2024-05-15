#include <iostream>
#include "++operator.hpp"

int main()
{
    Number x;

    std::cout << "Initial count: " << x.getCount() << std::endl;

    ++x;
    std::cout << "After prefix increment: " << x.getCount() << std::endl;

    x++;
    std::cout << "After postfix increment: " << x.getCount() << std::endl;

    return 0;
}