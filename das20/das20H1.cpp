#include <iostream>

#include "animal.hpp"

int main()
{
    Dog d1("Rex" , 3);
    Dog d2("Jonny" , 4);
    Dog d3("Hippy" , 1);

    Cat c1("Leo" , 2);
    Cat c2("Geo" , 1);
    Cat c3("Kate" , 3);

    std::cout << "Oldest Dog: " << std::endl;
    if(d1 > d2 && d1 > d3)
    {
        d1.print();
    }
    else if(d2 > d1 && d2 > d3)
    {
        d2.print();
    }
    else
    {
        d3.print();
    }

    std::cout << "Oldest Cat: " << std::endl;
    if(c1 > c2 && c1 > c3)
    {
        c1.print();
    }
    else if(c2 > c1 && c2 > c3)
    {
        c2.print();
    }
    else
    {
        c3.print();
    }
    
    return 0;
}