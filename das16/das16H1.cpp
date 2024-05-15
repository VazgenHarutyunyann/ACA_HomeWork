#include <iostream>
#include <string>

class Animal
{
private:
    int m_age = 0;
    std::string m_name;
    int m_weight = 0;
    int m_height = 0;

public:

    static int count;

    Animal(const int& age , const std::string& name , const int& weight , const int& height) :
        m_age(age) , m_name(name) , m_weight(weight) , m_height(height) 
        {
            ++count;
        }

    virtual ~Animal()
    {

    }

};

int Animal::count = 0;

class Dog : public Animal
{
public:
    Dog(const int& age , const int& weight , const int& height) :
        Animal(age , "Dog" , weight , height) {}

    ~Dog()
    {

    }
};

class Cat : public Animal
{
public:
    Cat(const int& age , const int& weight , const int& height) :
        Animal(age , "Cat" , weight , height) {}

    ~Cat()
    {
        
    }
};

int main()
{
    Animal crocodile(5 , "Crocodile" , 120 , 150);
    Animal elephant(13 , "Elephant" , 1000 , 340);
    Cat cat(1 , 10 , 20);
    Dog dog(2 , 13 , 20);

    std::cout << "There are " << Animal::count << " animals: " << std::endl;


    return 0;
}