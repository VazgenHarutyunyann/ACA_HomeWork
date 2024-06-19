#include <iostream>
#include <string>
#include <unordered_map>

#include "Car.hpp"

int main()
{
    std::unordered_map<Car , int , CarHash> carMap;

    carMap[Car("Porche" , 2022)] = 200000;
    carMap[Car("Mercedes" , 2024)] = 550000;
    carMap[Car("BMW" , 2020)] = 100000;
    carMap[Car("Opel" , 2000)] = 1000;

    for (auto it : carMap)
    {
        std::cout << "Mark: " << it.first.m_mark << std::endl;
        std::cout << "Year: " << it.first.m_year << std::endl;
        std::cout << "Value: " << it.second << "$ " << std::endl;
        std::cout << std::endl;
    }
    
    
    

    return 0;
}