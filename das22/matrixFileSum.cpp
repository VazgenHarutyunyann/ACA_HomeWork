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
        int value;
        while (temp >> value)
        {
            ++sizeY;
        }
        
    }

    file.close();
    return sizeY;
    
}

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

Matrix::Matrix(const Matrix& other) : m_sizeX(other.m_sizeX) , m_sizeY(other.m_sizeY)
    {
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

Matrix::Matrix(Matrix&& other) : m_sizeX(other.m_sizeX) , m_sizeY(other.m_sizeY) , m_matrix(other.m_matrix)
    {
        other.m_sizeX = 0;
        other.m_sizeY = 0;
        other.m_matrix = nullptr;
    }

Matrix& Matrix::operator=(Matrix&& other)
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

void Matrix::printMatrix()
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

int** Matrix::getMatrix() const
{
    return m_matrix;
}

int Matrix::getSizeX() const
{
    return m_sizeX;
}

int Matrix::getSizeY() const
{
    return m_sizeY;
}

void Matrix::readFile(const std::string& fileName)
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

void Matrix::fillFile(const std::string& fileName)
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

Matrix operator+(const Matrix& matrix1 , const Matrix& matrix2)
{
    if (matrix1.getSizeX() != matrix2.getSizeX() || matrix1.getSizeY() != matrix2.getSizeY())
    {
        std::cout << "Your sizeX or sizeY is not equal: " << std::endl;
        return Matrix(0 , 0);
    }

    Matrix result(matrix1.getSizeX() , matrix1.getSizeY());

    for (int i = 0; i < matrix1.getSizeX(); ++i)
    {
        for (int j = 0; j < matrix1.getSizeY(); ++j)
        {
            result.getMatrix()[i][j] = matrix1.getMatrix()[i][j] + matrix2.getMatrix()[i][j];
        }

    }

    return result;
}