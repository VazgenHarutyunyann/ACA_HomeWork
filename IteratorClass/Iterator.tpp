#ifndef __ITERATOR__TPP__
#define __ITERATOR__TPP__

#include "Iterator.hpp"

template <typename T>
Iterator<T>::Iterator(T* ptr) : m_current(ptr) {}

template <typename T>
Iterator<T>& Iterator<T>::operator++()
{
    ++m_current;
    return *this;
}

template <typename T>
Iterator<T> Iterator<T>::operator++(int)
{
    Iterator temp = *this;
    ++m_current;
    return temp;
}

template <typename T>
T& Iterator<T>::operator*() const
{
    return *m_current;
}

template <typename T>
T* Iterator<T>::operator->() const 
{
    return m_current;
}

template <typename T>
bool Iterator<T>::operator==(const Iterator& other) const 
{
    if (m_current == other.m_current)
    {
        return true;
    }
    
    return false;
}

template <typename T>
bool Iterator<T>::operator!=(const Iterator& other) const 
{
    if (m_current != other.m_current)
    {
        return true;
    }
    
    return false;
}

#endif //__ITERATOR__TPP__