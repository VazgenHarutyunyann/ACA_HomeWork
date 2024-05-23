#include <iostream>
#include <cstdlib>

int** createMatrix(int sizeX , int sizeY)
{
    int** matrix = new int*[sizeX];
    for (int i = 0; i < sizeX; ++i)
    {
        matrix[i] = new int[sizeY];
    }
        
    return matrix;
}

void randomMatrix(int** matrix , int sizeX , int sizeY)
{
    for (int i = 0; i < sizeX; ++i)
    {
        for (int j = 0; j < sizeY; ++j)
        {
            matrix[i][j] = rand() % 100;
        }
        
    }
    
}

void printMatrix(int** matrix , int sizeX , int sizeY)
{
    for (int i = 0; i < sizeX; ++i)
    {
        for (int j = 0; j < sizeY; ++j)
        {
            std::cout << j + 1 << ")" << matrix[i][j] << " ";
        }
        
        std::cout << std::endl;
    }
    
}

void deleteMatrix(int** matrix , int sizeX)
{
    for (int i = 0; i < sizeX; ++i)
    {
        delete[] matrix[i];
    }
        
    delete matrix;
}


int main()
{
    int sizeX = 0;
    std::cout << "Write sizeX for matrix: ";
    std::cin >> sizeX;

    int sizeY = 0;
    std::cout << "Write sizeY for matrix: ";
    std::cin >> sizeY;

    int** matrix = createMatrix(sizeX , sizeY);

    randomMatrix(matrix , sizeX , sizeY);

    std::cout << "Matrix after random generetion: " << std::endl;
    printMatrix(matrix , sizeX , sizeY);

    deleteMatrix(matrix , sizeX);
    matrix = nullptr;



    return 0;
}