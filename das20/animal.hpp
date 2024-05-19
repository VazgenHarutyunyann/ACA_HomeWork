#ifndef __ANIMAL__
#define __ANIMAL__

#include <string>

class Animal
{
protected:
    std::string m_name;
    int m_age = 0;

public:
    Animal(const std::string& name , const int& age);

    virtual ~Animal() = default;

    virtual void print() const;

    Animal(Animal&& other) noexcept;

    Animal& operator=(Animal&& other) noexcept;

    Animal(const Animal& other);

    Animal& operator=(const Animal& other);

    bool operator==(const Animal& other) const;

    bool operator>(const Animal& other) const;

    bool operator<(const Animal& other) const;
};

class Dog : public Animal
{
public:
    Dog(const std::string& name , const int& age);

    ~Dog() override = default;

    void print() const override;

    Dog(Dog&& other) noexcept;

    Dog& operator=(Dog&& other) noexcept;

    Dog(const Dog& other);

    Dog& operator=(const Dog& other);
};

class Cat : public Animal
{
public:
    Cat(const std::string& name , const int& age);

    ~Cat() override = default;

    void print() const override;

    Cat(Cat&& other) noexcept;

    Cat& operator=(Cat&& other) noexcept;

    Cat(const Cat& other);

    Cat& operator=(const Cat& other);
};

#endif //__ANIMAL__