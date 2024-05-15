#include "++operatorMatrix.hpp"

Matrix::Matrix(const int& sizeX, const int& sizeY) : m_sizeX(sizeX), m_sizeY(sizeY)
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
    }
    delete[] m_matrix;
}

void Matrix::fillMatrix()
{
    for (int i = 0; i < m_sizeX; ++i)
    {
        for (int j = 0; j < m_sizeY; ++j)
        {
            m_matrix[i][j] = 0;
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

Matrix::Matrix(const Matrix& matrix2)
{
    m_sizeX = matrix2.m_sizeX;
    m_sizeY = matrix2.m_sizeY;
    m_matrix = new int*[m_sizeX];
    for (int i = 0; i < m_sizeX; ++i)
    {
        m_matrix[i] = new int[m_sizeY];
        for (int j = 0; j < m_sizeY; ++j)
        {
            m_matrix[i][j] = matrix2.m_matrix[i][j];
        }
    }
}

Matrix& Matrix::operator=(const Matrix& matrix2)
{
    if (this != &matrix2)
    {
        for (int i = 0; i < m_sizeX; ++i)
        {
            delete[] m_matrix[i];
        }
        delete[] m_matrix;

        m_sizeX = matrix2.m_sizeX;
        m_sizeY = matrix2.m_sizeY;
        m_matrix = new int*[m_sizeX];

        for (int i = 0; i < m_sizeX; ++i)
        {
            m_matrix[i] = new int[m_sizeY];
            for (int j = 0; j < m_sizeY; ++j)
            {
                m_matrix[i][j] = matrix2.m_matrix[i][j];
            }
        }
    }
    return *this;
}

Matrix& Matrix::operator++()
{
    for (int i = 0; i < m_sizeX; ++i)
    {
        for (int j = 0; j < m_sizeY; ++j)
        {
            m_matrix[i][j] = m_matrix[i][j] + 3;
        }
    }
    return *this;
}

Matrix Matrix::operator++(int)
{
    Matrix temp(*this);
    ++(*this);
    return temp;
}