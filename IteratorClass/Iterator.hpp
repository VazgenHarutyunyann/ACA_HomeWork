#ifndef __ITERATOR__HPP__
#define __ITERATOR__HPP__

template <typename T>
class Iterator
{
private:
    T* m_current;
public:
    Iterator(T* ptr);

    Iterator& operator++();
    Iterator operator++(int);

    T& operator*() const;
    T* operator->() const;

    bool operator==(const Iterator& other) const;
    bool operator!=(const Iterator& other) const;
};

#include "Iterator.tpp"

#endif //__ITERATOR__HPP__