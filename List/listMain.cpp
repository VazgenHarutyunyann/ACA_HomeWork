#include <iostream>

#include "list.hpp"

int main()
{
    List<int> myList;

    myList.push_front(10);
    myList.print();
    myList.push_front(20);
    myList.print();
    myList.push_front(30);
    myList.print();

    myList.insert(40);
    myList.print();
    myList.insert(50);
    myList.print();

    myList.pop_front();
    myList.print();
    myList.pop_front();
    myList.print();
    
    return 0;
}