#ifndef __OPERATORMATRIX__
#define __OPERATORMATRIX__

#include <iostream>

class Matrix
{
private:
    int** m_matrix;
    int m_sizeX;
    int m_sizeY;

public:
    Matrix(const int& sizeX, const int& sizeY);

    ~Matrix();

    void fillMatrix();

    void printMatrix() const;

    Matrix(const Matrix& matrix2);

    Matrix& operator=(const Matrix& matrix2);

    Matrix& operator++();

    Matrix operator++(int);
};

#endif // __OPERATORMATRIX__