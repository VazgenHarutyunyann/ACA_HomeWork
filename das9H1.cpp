#include <iostream>
#include <cstdlib>

class TransposeMatrix
{
private:
    int* _matrix;
    int _size = 0;

public:
    TransposeMatrix(const int& size)
    {
        _size = size;
        _matrix = new int[size * size];

        for (int i = 0; i < size * size; ++i)
        {
            _matrix[i] = rand() % 100;
        }
        
    }

    ~TransposeMatrix()
    {
        delete[] _matrix;
        _matrix = nullptr;
    }

    void printMatrix()
    {
        for (int i = 0; i < _size * _size; ++i)
        {
            std::cout << _matrix[i] << " ";
            if ((i + 1) % _size == 0)
            {
                std::cout << std::endl;
            }
            
        }
                
    }
    void transposeMatrix()
    {
        for (int i = 0; i < _size; ++i)
        {
            for (int j = i + 1; j < _size; ++j)
            {
                std::swap(_matrix[i * _size + j], _matrix[j * _size + i]);
            }
        }

    }

};

int main()
{
    int size = 0;
    std::cout << "Write sizeX for matrix: ";
    std::cin >> size;

    TransposeMatrix matrix(size);

    std::cout << "Original matrix: " << std::endl;
    matrix.printMatrix();

    std::cout << "Traspose matrix: "<< std::endl;
    matrix.transposeMatrix();
    matrix.printMatrix();

    return 0;
}
