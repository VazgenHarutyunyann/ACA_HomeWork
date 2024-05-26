#ifndef __MATRIXFILESUM__
#define __MATRIXFILESUM__

#include <string>

int findSizeX(const std::string& fileName);

template <typename T>
int findSizeY(const std::string& fileName);

template <typename T>
class Matrix
{
private:
    int m_sizeX;
    int m_sizeY;
    T** m_matrix;

public:
    Matrix(const int& sizeX , const int& sizeY);
    ~Matrix();

    Matrix(const Matrix& other);
    Matrix& operator=(const Matrix& other);

    Matrix(Matrix&& other);
    Matrix& operator=(Matrix&& other);

    void printMatrix();

    T** getMatrix() const;
    int getSizeX() const;
    int getSizeY() const;

    void readFile(const std::string& fileName);
    void fillFile(const std::string& fileName);

};

template <typename T>
Matrix<T> operator+(const Matrix<T>& matrix1 , const Matrix<T>& matrix2);

#endif //__MATRIXFILESUM__