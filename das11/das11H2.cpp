#include <iostream>
#include <cstring>

class Info
{
private:
    std::string m_mark;
    std::string m_country;
    int m_price = 0;
    std::string m_color;
    int m_year = 0;

public:
    Info(const std::string& mark , const std::string& country , const int& price , const std::string& color , const int& year) :
        m_mark(mark) , m_country(country) , m_price(price) , m_color(color) , m_year(year) {}

    ~Info()
    {

    }

    void printInfo()
    {
        std::cout << "Your car model is " << m_mark  << ": " << std::endl;
        std::cout << "Price of " << m_mark << " is " << m_price << ": " << std::endl;
        std::cout << m_mark << " is made at " << m_year << " in " << m_country  << ": " << std::endl;
        std::cout << "Color is " << m_color << ": " << std::endl;      
    }
};

class Engine
{
private:
    int m_hp = 0;
    std::string m_metal;

public:
    Engine(const int& hp , const std::string& metal) : 
        m_hp(hp) , m_metal(metal) {}

    ~Engine()
    {

    }

    void printEngine()
    {
        std::cout << "Your cars hp is " << m_hp << ": " << std::endl;
        std::cout << "Your cars Engine made by " << m_metal << ": " << std::endl;
    }
};

class Car
{
private:
    Info m_information;
    Engine m_carEngine;

public:
    Car(const Info& information , const Engine& carEngine) : 
        m_information(information) , m_carEngine(carEngine) {}

    ~Car()
    {

    }

    void printCar()
    {
        m_information.printInfo();
        m_carEngine.printEngine();
    }

};

int main()
{

    Info carInfo("Mercedes", "Germany", 75000, "Grey", 2020);
    Engine carEngine(750, "German Engineering");
    Car myCar(carInfo, carEngine);

    myCar.printCar();


    return 0;
}