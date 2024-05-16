#include <iostream>
#include <string>

#include "moveAnimal.hpp"

Animal::Animal(const std::string& name , const int& age) : m_name(name) , m_age(age) {}

void Animal::print() const 
{
    std::cout << "My name is " << m_name << ". My age is " << m_age << std::endl;
}

Animal::Animal(Animal&& other) : m_name(other.m_name) , m_age(other.m_age)
{
    other.m_name = " ";
    other.m_age = 0;
}

Animal& Animal::operator=(Animal&& other)
{
    if (this != &other)
    {
        m_name = other.m_name;
        m_age = other.m_age;
        other.m_name = " ";
        other.m_age = 0;
    }

    return *this;
    
}

Dog::Dog(const int& age) : Animal("Dog" , age) {}

Dog::~Dog() {}

Dog::Dog(Dog&& other) : Animal(std::move(other)) {}

Dog& Dog::operator=(Dog&& other) 
{
    Animal::operator=(std::move(other));
    return *this;
}

void Dog::print() const
{
    std::cout << "My name is " << m_name << ". My age is " << m_age << std::endl;
}

Cat::Cat(const int& age) : Animal("Cat" , age) {}

Cat::~Cat() {}

Cat::Cat(Cat&& other) : Animal(std::move(other)) {}

Cat& Cat::operator=(Cat&& other) 
{
    Animal::operator=(std::move(other));
    return *this;
}

void Cat::print() const
{
    std::cout << "My name is " << m_name << ". My age is " << m_age << std::endl;
}
