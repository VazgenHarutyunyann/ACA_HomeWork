#include <iostream>
#include <string>

#include "animal.hpp"

Animal::Animal(const std::string& name , const int& age) : m_name(name) , m_age(age) {}

void Animal::print() const
{
    std::cout << "Name: " << m_name << std::endl;
    std::cout << "Age: " << m_age << std::endl;
}

Animal::Animal(Animal&& other) noexcept : m_name(other.m_name) , m_age(other.m_age)
{
    other.m_name = " ";
    other.m_age = 0;
}

Animal& Animal::operator=(Animal&& other) noexcept
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

Animal::Animal(const Animal& other) : m_name(other.m_name) , m_age(other.m_age) {}

Animal& Animal::operator=(const Animal& other)
{
    if (this != &other)
    {
        m_name = other.m_name;
        m_age = other.m_age;
    }

    return *this;
}

bool Animal::operator==(const Animal& other) const
{
    if (m_age == other.m_age)
    {
        return true;
    }

    return false;
}

bool Animal::operator>(const Animal& other) const
{
    if (m_age > other.m_age)
    {
        return true;
    }
    
    return false;
}

bool Animal::operator<(const Animal& other) const
{
    if (m_age < other.m_age)
    {
        return true;
    }
    
    return false;
}

Dog::Dog(const std::string& name , const int& age) : Animal(name , age) {}

void Dog::print() const
{
    std::cout << "This is a dog: " << std::endl;
    Animal::print();
}

Dog::Dog(const Dog& other) : Animal(other) {}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        Animal::operator=(other);
    }

    return *this;
}

Dog::Dog(Dog&& other) noexcept : Animal(std::move(other)) {}

Dog& Dog::operator=(Dog&& other) noexcept
{
    if (this != &other) 
    {
        Animal::operator=(std::move(other));
    }
    
    return *this;
}

Cat::Cat(const std::string& name , const int& age) : Animal(name , age) {}

void Cat::print() const
{
    std::cout << "This is a Cat: " << std::endl;
    Animal::print();
}

Cat::Cat(const Cat& other) : Animal(other) {}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
    {
        Animal::operator=(other);
    }

    return *this;
}

Cat::Cat(Cat&& other) noexcept : Animal(std::move(other)) {}

Cat& Cat::operator=(Cat&& other) noexcept
{
    if (this != &other) 
    {
        Animal::operator=(std::move(other));
    }
    
    return *this;
}