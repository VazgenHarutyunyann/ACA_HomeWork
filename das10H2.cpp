#include <iostream>
#include <cstdlib>

class Matrix
{
private:
    int _sizeX = 0;
    int _sizeY = 0;
    int* _matrix;

public:
    Matrix(const int& sizeX , const int& sizeY)
    {
        _sizeX = sizeX;
        _sizeY = sizeY;
        _matrix = new int[sizeX * sizeY];
    }

    ~Matrix()
    {
        delete[] _matrix;
        _matrix = nullptr;
    }

    Matrix& operator+(const Matrix& matrix2) const
    {
        std::cout << "operator + is called: " << std::endl;

        Matrix* matrix3 = new Matrix(_sizeX , _sizeY);

        if (_sizeX == matrix2._sizeX && _sizeY == matrix2._sizeY)
        {

            for (int i = 0; i < _sizeX * _sizeY; ++i)
            {
                matrix3->_matrix[i] = matrix2._matrix[i] + _matrix[i];
            }
            
        }

        return *matrix3;
        
    }

    void fillMatrix()
    {
        for (int i = 0; i < _sizeX * _sizeY; ++i)
        {
            _matrix[i] = rand() % 100;
        }
        
    }

    void printMatrix()
    {
        for (int i = 0; i < _sizeX * _sizeY; ++i)
        {
            std::cout << _matrix[i] << " ";

            if ((i + 1) % _sizeX == 0)
            {
                std::cout << std::endl;
            }
            
        }
        
    }



};


int main()
{
    int sizeX = 0;
    std::cout << "Write sizeX for matrix1 and matrix2: ";
    std::cin >> sizeX;

    int sizeY = 0;
    std::cout << "Write sizeY for matrix1 and matrix2: ";
    std::cin >> sizeY;

    Matrix matrix1(sizeX , sizeY);
    Matrix matrix2(sizeX , sizeY);

    std::cout << "First matrix: " << std::endl;
    matrix1.fillMatrix();
    matrix1.printMatrix();

    std::cout << "Second matrix: " << std::endl;
    matrix2.fillMatrix();
    matrix2.printMatrix();

    Matrix matrix3 = matrix1 + matrix2;
    std::cout << "matrix1 + matrix2: " <<std::endl;
    matrix3.printMatrix();

    delete &matrix3;

    return 0;
}