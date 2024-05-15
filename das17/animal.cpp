#include "animal.hpp"
#include <iostream>

Animal::Animal(const std::string& name, int age) : m_name(name), m_age(age) {}

Animal::~Animal() {}

Dog::Dog(int age) : Animal("Dog", age) {}

Dog::~Dog() {}

void Dog::sound() const
{
    std::cout << "I am Dog: " << std::endl;
}

Cat::Cat(int age) : Animal("Cat", age) {}

Cat::~Cat() {}

void Cat::sound() const
{
    std::cout << "I am Cat: " << std::endl;
}

Lion::Lion(int age) : Animal("Lion", age) {}

Lion::~Lion() {}

void Lion::sound() const
{
    std::cout << "I am Lion: " << std::endl;
}

Monkey::Monkey(int age) : Animal("Monkey", age) {}

Monkey::~Monkey() {}

void Monkey::sound() const
{
    std::cout << "I am Monkey: " << std::endl;
}