#include <iostream>
#include  <cstring>

class Car
{
private:
    std::string _mark;
    int _price = 0;
    int _year = 0;
    std::string _country;
    std::string _color;
    int _hp = 0;

public:
    Car(const std::string& mark , const int& price , const int& year , const std::string& country , const std::string& color , const int& hp)
    {
        _mark = mark;
        _price = price;
        _year = year;
        _country = country;
        _color = color;
        _hp = hp; 
    }

    void printCar()
    {
        std::cout << "Your car model is " << _mark  << ": " << std::endl;
        std::cout << "Price of " << _mark << " is " << _price << ": " << std::endl;
        std::cout << _mark << " is made at " << _year << " in " << _country  << ": " << std::endl;
        std::cout << "Color is " << _color << ": " << std::endl;
        std::cout << _mark << " Horse power is " << _hp << ": " << std::endl;
    }

};

int main()
{
    Car mercedes("Mercedes 63 S" , 75000000 , 2023 , "Germany" , "Black" , 750);
    mercedes.printCar();

    return 0;
}