#include <iostream>
#include <cstring>

class Car
{

private:
    std::string m_mark;
    int m_price = 0;
    std::string m_color;
    int m_hp = 0;
    int m_year = 0;
    std::string m_country;

public:
    Car(const std::string& mark , const int& price , const std::string& color , const int& hp , const int& year , const std::string& country) :
        m_mark(mark) , m_price(price) , m_color(color) , m_hp(hp) , m_year(year) , m_country(country) {}

    void printCar()
    {
        std::cout << "My car model is " << m_mark  << ": " << std::endl;
        std::cout << "Price of " << m_mark << " is " << m_price << ": " << std::endl;
        std::cout << m_mark << " is made at " << m_year << " in " << m_country  << ": " << std::endl;
        std::cout << "Color is " << m_color << ": " << std::endl;
        std::cout << m_mark << " Horse power is " << m_hp << ": " << std::endl;
    }

    ~Car()
    {

    }

};

class Parking
{
private:
    int m_size = 0;
    Car** m_cars;
    int m_freePlaces = 0;

public:
    Parking(const int& size) : m_size(size) 
    {
        m_cars = new Car*[size];
    }

    ~Parking()
    {
        delete[] m_cars;
        m_cars = nullptr;
    }

    Parking(const Parking& obj)
    {
        m_size = obj.m_size;
        m_cars = new Car*[m_size];

        for (int i = 0; i < m_size; ++i)
        {
            m_cars[i] = obj.m_cars[i];
        }
        
    }

    Parking operator = (const Parking& obj)
    {
        if (this != &obj)
        {
            if (m_size != obj.m_size)
            {
                m_size = obj.m_size;
                delete[] m_cars;
                m_cars = new Car*[m_size];

                for (int i = 0; i < m_size; ++i)
                {
                    m_cars[i] = obj.m_cars[i];
                }
                
            }
            
            return *this;
        }
        
    }

    void freePlaces(Car* car)
    {
        if (m_size != m_freePlaces)
        {
            m_cars[m_freePlaces] = car;
            std::cout << "You are successfuly parking here: " <<std::endl;
            std::cout << "Your parking place is " << m_freePlaces << std::endl;
            ++m_freePlaces;
        }
        else
        {
            std::cout << "Parking is full: " << std::endl;
            std::cout << "Wait a 5 minute maybe somone will leave: " << std::endl;
        }
            
    }

    void aboutYourCar(Car* car)
    {
        bool temp = false;

        for (int i = 0; i < m_size; ++i)
        {
            if (m_cars[i] == car)
            {
                temp = true;
                break;
            }
            
        }
        
        if (temp == true)
        {
            int k = 0;

            for (int i = 0; i < m_size; ++i)
            {

                if (m_cars[i] == car)
                {
                    k = i;
                    break;
                }
                
            }
            
            std::cout << "Tell about your car: Ticket: " << k  << ": "<< std::endl;
            car->printCar();
        }
        else
        {
            std::cout << "Your car is not parked here: " << std::endl;
        }
        
    }
    
};


int main()
{
    Parking market(3);
    Car car1("Mercedes" , 75000 , "Grey" , 750 , 2020 , "Germany");
    market.freePlaces(&car1);
    std::cout << std::endl;

    Car car2("Lamborgini" , 350000 , "Yellow" , 1050 , 2024 , "Italy");
    market.freePlaces(&car2);
    std::cout << std::endl;    

    Car car3("Opel" , 0 , "Grey" , 20 , 2000 , "Armenia");
    market.freePlaces(&car3);
    std::cout << std::endl;

    Car car4("Tesla" , 55000 , "White" , 450 , 2022 , "USA");
    market.freePlaces(&car4);
    std::cout << std::endl;

    market.aboutYourCar(&car1);
    std::cout << std::endl;

    market.aboutYourCar(&car2);
    std::cout << std::endl;

    market.aboutYourCar(&car3);
    std::cout << std::endl;

    market.aboutYourCar(&car4);
    std::cout << std::endl;

    return 0;
}