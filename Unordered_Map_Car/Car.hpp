#ifndef __UNORDERED__MAP__CAR__HPP__
#define __UNORDERED__MAP__CAR__HPP__

#include <string>

class Car
{
public:
    std::string m_mark;
    int m_year;

    Car(const std::string& mark , const int& year);

    bool operator==(const Car& other) const;
};

struct CarHash
{
    std::size_t operator()(const Car& car) const;
};

#endif //__UNORDERED__MAP__CAR__HPP__