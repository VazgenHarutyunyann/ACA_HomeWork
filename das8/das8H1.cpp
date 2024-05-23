//Not full

#include <iostream>
#include <cstdlib>

int** createMatrix(const int& size)
{
    int** matrix = new int*[size];
    for (int i = 0; i < size; ++i)
    {
        matrix[i] = new int[size];
    }

    return matrix;
    
}

void printMatrix(int** matrix , const int& size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            std::cout << matrix[i][j] << " ";
        }
        
        std::cout << std::endl;
    }
    
}

void deleteMatrix(int** matrix , const int& size)
{
    for (int i = 0; i < size; ++i)
    {
        delete matrix[i];
        matrix[i] = nullptr;
    }

    delete matrix;
    
}

void randomMatrix(int** matrix , const int& size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            matrix[i][j] = rand() % 100;
        }
        
    }
    
}

void transposeMatrix(int** matrix , const int& size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            int temp = matrix[i][j];
            //matrix[j];
        }
        
    }
     
}

int main()
{
    int size = 0;
    std::cout << "Write size for matrix: ";
    std::cin >> size;
    if (size < 1)
    {
        std::cout << "Your size is smaller than 1: " << std::endl;
        return 1;
    }

    int** matrix = createMatrix(size);
    randomMatrix(matrix , size);

    std::cout << "Normal matrix: " << std::endl;
    printMatrix(matrix , size);

    std::cout << std::endl;

    transposeMatrix(matrix , size);
    std::cout << "Transpose matrix: " << std::endl;
    printMatrix(matrix , size);

    deleteMatrix(matrix , size);

    return 0;
}