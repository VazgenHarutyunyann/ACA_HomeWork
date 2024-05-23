#ifndef __MATRIXFILESUM__
#define __MATRIXFILESUM__

int findSizeX(const std::string& fileName);

int findSizeY(const std::string& fileName);

class Matrix
{
private:
    int m_sizeX;
    int m_sizeY;
    int** m_matrix;

public:
    Matrix(const int& sizeX , const int& sizeY);

    ~Matrix();

    Matrix(const Matrix& other);

    Matrix& operator=(const Matrix& other);

    Matrix(Matrix&& other);

    Matrix& operator=(Matrix&& other);

    void printMatrix();

    int** getMatrix() const;

    int getSizeX() const;

    int getSizeY() const;

    void readFile(const std::string& fileName);

    void fillFile(const std::string& fileName);

};

Matrix operator+(const Matrix& matrix1 , const Matrix& matrix2);

#endif //__MATRIXFILESUM__