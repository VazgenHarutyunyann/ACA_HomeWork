#ifndef __ANIMAL__
#define __ANIMAL__

#include <string>

class Animal
{
private:
    std::string m_name;
    int m_age;

public:
    Animal(const std::string& name, int age = 0);

    virtual ~Animal();

    virtual void sound() const = 0;
};

class Dog : public Animal
{
public:
    Dog(int age);

    ~Dog();

    void sound() const override;
};

class Cat : public Animal
{
public:
    Cat(int age);

    ~Cat();

    void sound() const override;
};

class Lion : public Animal
{
public:
    Lion(int age);

    ~Lion();

    void sound() const override;
};

class Monkey : public Animal
{
public:
    Monkey(int age);

    ~Monkey();

    void sound() const override;
};

#endif // __ANIMAL__