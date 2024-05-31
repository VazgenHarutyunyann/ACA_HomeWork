#ifndef __VECTOR__
#define __VECTOR__

#include <iostream>

template <typename T>
class Vector
{
private:
    int m_size;
    int m_capacity;
    T* m_data;

public:
    Vector();
    Vector(const int& size);
    ~Vector();

    Vector(const Vector& other);
    Vector& operator=(const Vector& other);

    Vector(Vector&& other);
    Vector& operator=(Vector&& other);
    
    void resize(int newCapacity);
    void push_back(const T& value);

    int getSize() const;
    T& operator[](const int& index) const;

    template<typename... Args>
    Vector(Args&&... args);

    void print() const;
};

template <typename T>
Vector<T>::Vector() : m_size(0), m_capacity(0), m_data(nullptr) {}

template <typename T>
Vector<T>::Vector(const int& size) : m_size(size), m_capacity(2 * size)
{
    m_data = new T[m_capacity];
}

template <typename T>
Vector<T>::~Vector()
{
    delete[] m_data;
    m_data = nullptr;
}

template <typename T>
Vector<T>::Vector(const Vector& other) : m_size(other.m_size), m_capacity(other.m_capacity)
{
    m_data = new T[m_capacity];
    for (int i = 0; i < m_size; ++i)
    {
        m_data[i] = other.m_data[i];
    }
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& other)
{
    if (this != &other)
    {
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        
        delete[] m_data;
        m_data = new T[m_capacity];

        for (int i = 0; i < m_size; ++i)
        {
            m_data[i] = other.m_data[i];
        }
    }
    
    return *this;
}

template <typename T>
Vector<T>::Vector(Vector&& other) : m_size(other.m_size), m_capacity(other.m_capacity), m_data(other.m_data)
{
    other.m_size = 0;
    other.m_capacity = 0;
    other.m_data = nullptr;
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector&& other)
{
    if (this != &other)
    {
        delete[] m_data;

        m_size = other.m_size;
        m_capacity = other.m_capacity;
        m_data = other.m_data;

        other.m_size = 0;
        other.m_capacity = 0;
        other.m_data = nullptr;
    }

    return *this;
}

template <typename T>
void Vector<T>::resize(int newCapacity)
{
    T* newData = new T[newCapacity];

    for (int i = 0; i < m_size; ++i)
    {
        newData[i] = m_data[i];
    }

    delete[] m_data;
    m_data = newData;
    m_capacity = newCapacity;
}

template <typename T>
void Vector<T>::push_back(const T& value)
{
    if (m_size >= m_capacity)
    {
        int newCapacity = 1;
        if (m_capacity != 0)
        {
            newCapacity = m_capacity * 2;
        }
        resize(newCapacity);
    }

    m_data[m_size++] = value;
}

template <typename T>
int Vector<T>::getSize() const
{
    return m_size;
}

template <typename T>
T& Vector<T>::operator[](const int& index) const
{
    return m_data[index];
}

template <typename T>
template <typename... Args>
Vector<T>::Vector(Args&&... args) : m_size(sizeof...(args)) , m_capacity(2 * m_size)
{
    m_data = new T[m_capacity];
    int index = 0;
    ((m_data[index++] = std::forward<Args>(args)), ...);
}

template <typename T>
void Vector<T>::print() const
{
    for (int i = 0; i < m_size; ++i)
    {
        std::cout << m_data[i] << " ";
    }

    std::cout << std::endl;
}

#endif // __VECTOR__