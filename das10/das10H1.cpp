#include <iostream>

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


    Matrix(const Matrix& matrix2)
    {
        std::cout << "Copy constructor is called: " << std::endl;
        _sizeX = matrix2._sizeX;
        _sizeY = matrix2._sizeY;
        _matrix = new int[_sizeX * _sizeY];

        for (int i = 0; i < _sizeX * _sizeY; ++i)
        {
            _matrix[i] = matrix2._matrix[i];
        }
        
    }

    Matrix& operator=(const Matrix& matrix2)
    {
        std::cout << "operator = is called: " << std::endl;

        if (this != &matrix2)
        {
            _sizeX = matrix2._sizeX;
            _sizeY = matrix2._sizeY;
            _matrix = new int[_sizeX * _sizeY];

            for (int i = 0; i < _sizeX * _sizeY; ++i)
            {
                _matrix[i] = matrix2._matrix[i];
            }
            
        }
        
        return *this;
    }

};


int main()
{
    Matrix matrix1(3 , 3);

    Matrix matrix2 = matrix1;

    Matrix matrix3(2 , 2);
    matrix3 = matrix1;


    return 0;
}