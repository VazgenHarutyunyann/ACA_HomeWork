#include <iostream>
#include "animal.hpp"

int main()
{
    Animal* dog = new Dog(3);
    Animal* cat = new Cat(4);
    Animal* lion = new Lion(5);
    Animal* monkey = new Monkey(6);

    if (dog) dog->sound();
    if (cat) cat->sound();
    if (lion) lion->sound();
    if (monkey) monkey->sound();

    delete dog;
    delete cat;
    delete lion;
    delete monkey;

    return 0;
}