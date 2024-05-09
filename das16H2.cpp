#include <iostream>

class Array
{
private:
    int m_size = 0;
    int* m_arr;

public:
    Array(const int& size) : m_size(size) 
    {
        m_arr = new int[size];
    }

    virtual ~Array()
    {
        delete[] m_arr;
        m_arr = nullptr;
    }

    Array(const Array& other)
    {
        delete[] m_arr;
        m_size = other.m_size;
        m_arr = new int[m_size];
        for (int i = 0; i < m_size; ++i)
        {
            m_arr[i] = other.m_arr[i];
        }
        
    }

    Array& operator=(const Array& other)
    {
        if (this != &other)
        {
            delete[] m_arr;
            m_size = other.m_size;
            m_arr = new int[m_size];
            for (int i = 0; i < m_size; ++i)
            {
                m_arr[i] = other.m_arr[i];
            }
            
        }

        return *this;
        
    }

    int& operator[](int index)
    {
        if(index >= m_size || index < 0)
        {
            std::cout << "Your index is bigger than size array or smaller than 0: " << std::endl;
        }

        return m_arr[index];
    }

    friend std::ostream& operator<<(std::ostream& os, const Array& arr) 
    {
        for (size_t i = 0; i < arr.m_size; ++i) 
        {
            os << arr.m_arr[i] << " ";
        }

        return os;
    }

};

int main()
{
    const int size = 5;
    Array arr(size);

    for (int i = 0; i < size; i++)
    {
        arr[i] = (i + 2) * 3;
    }

    std::cout << "Array: " << arr << std::endl;
    

    return 0;
}