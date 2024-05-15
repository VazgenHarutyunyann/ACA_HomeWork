#include "++operator.hpp"

Number::Number() {}

Number::~Number() {}

//++i
Number& Number::operator++()
{
    ++m_count;
    return *this;
}

//i++
Number Number::operator++(int)
{
    Number temp = *this;
    ++m_count;
    return temp;
}

int Number::getCount() const
{
    return m_count;
}

int Number::m_count = 5;