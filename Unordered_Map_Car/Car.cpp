#include <iostream>
#include <string>
#include <functional>


#include "Car.hpp"

Car::Car(const std::string& mark , const int& year) : m_mark(mark) , m_year(year) {}

bool Car::operator==(const Car& other) const
{
    return m_mark == other.m_mark && m_year == other.m_year;
}

std::size_t CarHash::operator()(const Car& car) const
{
    std::size_t h1 = std::hash<std::string>()(car.m_mark);
    std::size_t h2 = std::hash<int>()(car.m_year);

    std::size_t prime = 37;
    std::size_t Hash = h1;
    Hash = Hash * prime + h2;

    return Hash;
}