#ifndef __MOVEANIMAL__
#define __MOVEANIMAL__

#include <string>

class Animal
{
protected:
    std::string m_name;
    int m_age;

public:
    Animal(const std::string& name , const int& age);

    virtual ~Animal() = default;

    virtual void print() const = 0;

    Animal(Animal&& other);

    Animal& operator=(Animal&& other);
};

class Dog : public Animal
{
public:
    Dog(const int& age);

    ~Dog() override;

    void print() const override;

    Dog(Dog&& other);

    Dog& operator=(Dog&& other);
};

class Cat : public Animal
{
public:
    Cat(const int& age);

    ~Cat() override;

    void print() const override;

    Cat(Cat&& other);

    Cat& operator=(Cat&& other);
};

#endif //__MOVEANIMAL__