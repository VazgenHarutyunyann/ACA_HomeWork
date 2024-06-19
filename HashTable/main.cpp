#include <iostream>

#include "HashTable.hpp"

int main()
{
    HashTable<int> myHashTable(7);

    myHashTable.insert(2);
    myHashTable.insert(12);
    myHashTable.insert(45);
    myHashTable.insert(22);
    myHashTable.insert(11);
    myHashTable.insert(76);
    myHashTable.insert(19);
    myHashTable.insert(1);
    myHashTable.insert(2);
    myHashTable.insert(3);
    
    std::cout << "My Hash Table befor pop: " << std::endl;
    myHashTable.print();

    myHashTable.pop(2);
    myHashTable.pop(19);

    std::cout << "My Hash Table after pop: " << std::endl;
    myHashTable.print();

    return 0;
}