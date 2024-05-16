#include <iostream>

#include "moveAnimal.hpp"

int main() {
    Dog dog1(5);
    Cat cat1(3);

    std::cout << "Dog1: " << std::endl;
    dog1.print();
    std::cout << "Cat1: " << std::endl;
    cat1.print();

    Dog dog2 = std::move(dog1);
    Cat cat2 = std::move(cat1);

    std::cout << "Dog2: " << std::endl;
    dog2.print();
    std::cout << "Cat2: " << std::endl;
    cat2.print();

    std::cout << "Dog1: " << std::endl;
    dog1.print();
    std::cout << "Cat1: " << std::endl;
    cat1.print();


    return 0;
}