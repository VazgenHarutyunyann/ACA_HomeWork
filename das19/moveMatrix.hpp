#ifndef __MOVEMATRIX__
#define __MOVEMATRIX__

class Matrix
{
private:
    int** m_matrix;
    int m_sizeX;
    int m_sizeY;

public:
    Matrix(const int& sizeX , const int& sizeY);

    ~Matrix();

    void fillMatrix();

    void printMatrix() const;

    Matrix(const Matrix& other);

    Matrix& operator=(const Matrix& other);

    Matrix(Matrix&& other);

    Matrix& operator=(Matrix&& other);
};


#endif //__MOVEMATRIX__