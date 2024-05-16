#include <iostream>

#include "moveMatrix.hpp"

Matrix::Matrix(const int& sizeX , const int& sizeY) : m_sizeX(sizeX) , m_sizeY(sizeY)
{
    m_matrix = new int*[m_sizeX];
    for (int i = 0; i < m_sizeX; ++i)
    {
        m_matrix[i] = new int[m_sizeY];
    }
}

Matrix::~Matrix()
{
    for (int i = 0; i < m_sizeX; ++i)
    {
        delete[] m_matrix[i];
        m_matrix[i] = nullptr;
    }
    delete[] m_matrix;
}

void Matrix::fillMatrix()
{
    for (int i = 0; i < m_sizeX; ++i)
    {
        for (int j = 0; j < m_sizeY; ++j)
        {
            m_matrix[i][j] = 5; 
        }
        
    }
    
}

void Matrix::printMatrix() const
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

Matrix::Matrix(const Matrix& other)
{
    m_sizeX = other.m_sizeX;
    m_sizeY = other.m_sizeY;
    m_matrix = new int*[m_sizeX];
    for (int i = 0; i < m_sizeX; ++i)
    {
        m_matrix[i] = new int[m_sizeY];
        for (int j = 0; j < m_sizeY; ++j)
        {
            m_matrix[i][j] = other.m_matrix[i][j];
        }
        
    }

}

Matrix& Matrix::operator=(const Matrix& other)
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
        m_matrix = new int*[m_sizeX];
        for (int i = 0; i < m_sizeX; ++i)
        {
            m_matrix[i] = new int[m_sizeY];
            for (int j = 0; j < m_sizeY; ++j)
            {
                m_matrix[i][j] = other.m_matrix[i][j];
            }   
        }
        
    }

    return *this;
    
}

Matrix::Matrix(Matrix&& other) : m_matrix(other.m_matrix) , m_sizeX(other.m_sizeX) , m_sizeY(other.m_sizeY)
{
    other.m_matrix = nullptr;
    other.m_sizeX = 0;
    other.m_sizeY = 0;
}

Matrix& Matrix::operator=(Matrix&& other)
{
    if (this != &other)
    {
        if (m_matrix != nullptr)
        {
            for (int i = 0; i < m_sizeX; ++i)
            {
                delete[] m_matrix[i];
            }

            delete[] m_matrix;
        }

        m_matrix = other.m_matrix;
        m_sizeX = other.m_sizeX;
        m_sizeY = other.m_sizeY;

        other.m_matrix = nullptr;
        other.m_sizeX = 0;
        other.m_sizeY = 0;

    }

    return *this;
    
}