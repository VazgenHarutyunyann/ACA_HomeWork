#include <iostream>
#include <cstring>

class Car
{
protected:
    std::string m_mark;
    std::string m_model;
    int m_year = 0;
    int m_price = 0;

public:
    Car(const std::string& mark , const std::string& model , const int& year , const int& price) :
        m_mark(mark) , m_model(model) , m_year(year) , m_price(price) {}

    void printCar()
    {
        std::cout << "HI your car mark is " << m_mark << ": " << std::endl;
        std::cout << "Your car model is " << m_model << ": " << std::endl;
        std::cout << "Price of car is " << m_price << ": " << std::endl;
        std::cout << m_mark << " " << m_model << " made on " << m_year << ": " <<std::endl; 
    }

};

class Jeep : public Car
{
protected:
    int m_numSit = 0;
    double m_height = 0;

public:
    Jeep(const std::string& mark , const std::string& model , const int& year , const int& price , const int& numSit , const double& height) :
        Car(mark , model , year , price) , m_numSit(numSit) , m_height(height) {}

    void printJeep()
    {
        printCar();
        std::cout << "Sits number of your jeep is " << m_numSit << ": " << std::endl;
        std::cout << "Height of your jeep is " << m_height << ": " << std::endl;
    }
};

class ElectricCar : public Car
{
protected:
    int m_numSit = 0;
    double m_battery = 0;

public:
    ElectricCar(const std::string& mark , const std::string& model , const int& year , const int& price , const int& numSit , const double& battery) :
        Car(mark , model , year , price) , m_numSit(numSit) , m_battery(battery) {}

    void printElectricCar()
    {
        printCar();
        std::cout << "Sits number of your jeep is " << m_numSit << ": " << std::endl;
        std::cout << "battery of your jeep is " << m_battery << ": " << std::endl;
    }
};

class SportCar : public Car
{
protected:
    int m_numSit = 0;
    int m_hp  = 0;

public:
    SportCar(const std::string& mark , const std::string& model , const int& year , const int& price , const int& numSit , const double& hp) :
        Car(mark , model , year , price) , m_numSit(numSit) , m_hp(hp) {}

    void printSportCar()
    {
        printCar();
        std::cout << "Sits number of your jeep is " << m_numSit << ": " << std::endl;
        std::cout << "Horse poewr of your jeep is " << m_hp << ": " << std::endl;
    }
};



int main()
{

    Jeep jeep("Jeep", "Wrangler", 2022, 30000, 4, 1.8);
    ElectricCar electricCar("Tesla", "Model S", 2023, 80000, 5, 100);
    SportCar sportCar("Ferrari", "458 Italia", 2024, 250000, 2, 570);

    std::cout << "Information about your Jeep:" << std::endl;
    jeep.printJeep();
    std::cout << std::endl;

    std::cout << "Information about your Electric Car:" << std::endl;
    electricCar.printElectricCar();
    std::cout << std::endl;

    std::cout << "Information about your Sport Car:" << std::endl;
    sportCar.printSportCar();
    std::cout << std::endl;

    return 0;
}