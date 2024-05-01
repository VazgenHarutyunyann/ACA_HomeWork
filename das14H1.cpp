#include <iostream>

class Animal
{
protected:
    int m_weight = 0;

public:
    Animal(const int& weight) :
        m_weight(weight) {}

    virtual ~Animal()
    {

    }

    virtual void voice() const = 0;
    virtual int getWeight() const 
    {
        return m_weight;
    } 

};

class Cat : public Animal
{
public:
    Cat(const int& weight) :
        Animal(weight) {}

    ~Cat()
    {

    }

    void voice() const override
    {
        std::cout << "I am Cat: " << std::endl;
        std::cout << "My weight is " << getWeight() << " kg: " << std::endl; 
    }
};

class Dog : public Animal
{
public:
    Dog(const int& weight) :
        Animal(weight) {}

    ~Dog()
    {

    }

    void voice() const override
    {
        std::cout << "I am Dog: " << std::endl;
        std::cout << "My weight is " << getWeight() << " kg: " << std::endl; 
    }
};

class Elephant : public Animal
{
public:
    Elephant(const int& weight) :
        Animal(weight) {}

    ~Elephant()
    {

    }

    void voice() const override
    {
        std::cout << "I am Elephant: " << std::endl;
        std::cout << "My weight is " << getWeight() << " kg: " << std::endl; 
    }
};

class Crocodile : public Animal
{
public:
    Crocodile(const int& weight) :
        Animal(weight) {}

    ~Crocodile()
    {

    }

    void voice() const override
    {
        std::cout << "I am Crocodile: " << std::endl;
        std::cout << "My weight is " << getWeight() << " kg: " << std::endl; 
    }
};

int main()
{
    const int size = 4;
    Animal* zoo[size] = 
    {
        new Dog(20),
        new Cat(15),
        new Elephant(750),
        new Crocodile(200),
    };

    for (int i = 0; i < size; ++i)
    {
        zoo[i]->voice();
    }
    
    for (int i = 0; i < size; ++i)
    {
        delete zoo[i];
        zoo[i] = nullptr;
    }
    


    return 0;
}