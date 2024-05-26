#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <sstream>

#include "matrixFileSum.hpp"

int findSizeX(const std::string& fileName)
{
    std::ifstream file(fileName);
    int sizeX = 0;

    if (!file.is_open())
    {
        std::cout << "File is not openned: " << std::endl;
        return 0;
    }
    
    std::string line;
    while (std::getline(file , line))
    {
        if (!line.empty())
        {
            ++sizeX;
        }
        
    }
    
    file.close();
    return sizeX;
}

template <typename T>
int findSizeY(const std::string& fileName)
{
    std::ifstream file(fileName);
    int sizeY = 0;

    if (!file.is_open())
    {
        std::cout << "File is not openned: " << std::endl;
        return 0;
    }

    std::string line;

    if (std::getline(file , line))
    {
        std::istringstream temp(line);
        T value;
        while (temp >> value)
        {
            ++sizeY;
        }
        
    }

    file.close();
    return sizeY;
    
}

template <typename T>
Matrix<T>::Matrix(const int& sizeX , const int& sizeY) : m_sizeX(sizeX) , m_sizeY(sizeY)
    {
        m_matrix = new T*[m_sizeX];
        for (int i = 0; i < m_sizeX; ++i)
        {
            m_matrix[i] = new T[m_sizeY];
        }
        
    }

template <typename T>
Matrix<T>::~Matrix()
    {
        for (int i = 0; i < m_sizeX; ++i)
        {
            delete[] m_matrix[i];
            m_matrix[i] = nullptr;
        }

        delete[] m_matrix;
    }

template <typename T>
Matrix<T>::Matrix(const Matrix& other) : m_sizeX(other.m_sizeX) , m_sizeY(other.m_sizeY)
    {
        m_matrix = new T*[m_sizeX];
        for (int i = 0; i < m_sizeX; ++i)
        {
            m_matrix[i] = new T[m_sizeY];
            for (int j = 0; j < m_sizeY; ++j)
            {
                m_matrix[i][j] = other.m_matrix[i][j];
            }   
        }
    }

template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix& other)
    {
        if (this != &other)
        {
            for (int i = 0; i < m_sizeX; ++i)
            {
                delete[] m_matrix[i];
            }
            delete[] m_matrix;

            m_sizeX = other.m_sizeX;
            m_sizeY = other.m_sizeY;

            m_matrix = new T*[m_sizeX];
            for (int i = 0; i < m_sizeX; ++i)
            {
                m_matrix[i] = new T[m_sizeY];
                for (int j = 0; j < m_sizeY; ++j)
                {
                    m_matrix[i][j] = other.m_matrix[i][j];
                }   
            }
        }
        
        return *this;
    }

template <typename T>
Matrix<T>::Matrix(Matrix&& other) : m_sizeX(other.m_sizeX) , m_sizeY(other.m_sizeY) , m_matrix(other.m_matrix)
    {
        other.m_sizeX = 0;
        other.m_sizeY = 0;
        other.m_matrix = nullptr;
    }

template <typename T>
Matrix<T>& Matrix<T>::operator=(Matrix&& other)
    {
        if(this != &other)
        {
            if (m_matrix != nullptr)
            {
                for (int i = 0; i < m_sizeX; ++i)
                {
                    delete[] m_matrix[i];
                }
                delete[] m_matrix;

                m_sizeX = other.m_sizeX;
                m_sizeY = other.m_sizeY;
                m_matrix = other.m_matrix;
                
                other.m_sizeX = 0;
                other.m_sizeY = 0;
                other.m_matrix = nullptr;
            }
            
        }

        return *this;
    }

template <typename T>
void Matrix<T>::printMatrix()
{
    for (int i = 0; i < m_sizeX; ++i)
    {
        for (int j = 0; j < m_sizeY; ++j)
        {
            std::cout << m_matrix[i][j] << " ";
        }
        
        std::cout << std::endl;
    }
        
}

template <typename T>
T** Matrix<T>::getMatrix() const
{
    return m_matrix;
}

template <typename T>
int Matrix<T>::getSizeX() const
{
    return m_sizeX;
}

template <typename T>
int Matrix<T>::getSizeY() const
{
    return m_sizeY;
}

template <typename T>
void Matrix<T>::readFile(const std::string& fileName)
{
    std::ifstream file(fileName);

    if(!file.is_open())
    {
        std::cout << "File is not openned! " << std::endl;
        return;
    }

    for (int i = 0; i < m_sizeX; ++i)
    {
        for (int j = 0; j < m_sizeY; ++j)
        {
            if (!(file >> m_matrix[i][j]))
            {
                std::cout << "Cant read file: " << std::endl;
                return;
            }
            
        }
        
    }
    
    file.close();
}

template <typename T>
void Matrix<T>::fillFile(const std::string& fileName)
{
    std::ofstream file(fileName);

    if (!file.is_open())
    {
        std::cout << "File is not openned: " << std::endl;
        return;
    }
        
    for (int i = 0; i < m_sizeX; ++i)
    {
        for (int j = 0; j < m_sizeY; ++j)
        {
            file << m_matrix[i][j] << " ";
        }

        file << std::endl;
    }
        

    file.close();
}

template <typename T>
Matrix<T> operator+(const Matrix<T>& matrix1 , const Matrix<T>& matrix2)
{
    if (matrix1.getSizeX() != matrix2.getSizeX() || matrix1.getSizeY() != matrix2.getSizeY())
    {
        std::cout << "Your sizeX or sizeY is not equal: " << std::endl;
        return Matrix<T>(0 , 0);
    }

    Matrix<T> result(matrix1.getSizeX() , matrix1.getSizeY());

    for (int i = 0; i < matrix1.getSizeX(); ++i)
    {
        for (int j = 0; j < matrix1.getSizeY(); ++j)
        {
            result.getMatrix()[i][j] = matrix1.getMatrix()[i][j] + matrix2.getMatrix()[i][j];
        }

    }

    return result;
}

template class Matrix<double>;
template Matrix<double> operator+(const Matrix<double>&, const Matrix<double>&);
template int findSizeY<double>(const std::string& fileName);