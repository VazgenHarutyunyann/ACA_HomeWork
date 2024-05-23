#include <iostream>
#include <cstdlib>

int** createMatrix(const int& sizeX , const int& sizeY)
{
    int** matrix = new int*[sizeX];
    for (int i = 0; i < sizeX; ++i)
    {
        matrix[i] = new int[sizeY];
    }

    return matrix;
    
}

void printMatrix(int** matrix , const int& sizeX , const int& sizeY)
{
    for (int i = 0; i < sizeX; ++i)
    {
        for (int j = 0; j < sizeY; ++j)
        {
            std::cout << matrix[i][j] << " ";
        }

        std::cout << std::endl;
        
    }
    
}

void deleteMatrix(int** matrix , const int& sizeX)
{
    for (int i = 0; i < sizeX; ++i)
    {
        delete matrix[i];
        matrix[i] = nullptr;
    }

    delete matrix;
    
}

void randomMatrix(int** matrix , const int& sizeX , const int& sizeY)
{
    for (int i = 0; i < sizeX; ++i)
    {
        for (int j = 0; j < sizeY; ++j)
        {
            matrix[i][j] = rand() % 100;
        }

    }
        
}

void convertedMatrix(int** matrix1 , int** matrix2 , const int& sizeX , const int& sizeY)
{
    for (int i = 0; i < sizeX; ++i)
    {
        for (int j = 0; j < sizeY; ++j)
        {
            matrix2[i][j] = matrix1[j][i];
        }
        
    }
    
}
    

int main()
{
    int sizeX = 0;
    std::cout << "Write sizeX for matrix: ";
    std::cin >> sizeX;
    if (sizeX < 1)
    {
        std::cout << "Your sizeX is smaller than 1: " << std::endl;
        return 1;
    }
    
    int sizeY = 0;
    std::cout << "Write sizeY for matrix: ";
    std::cin >> sizeY;
    if (sizeY < 1)
    {
        std::cout << "Your sizeY is smaller than 1: " << std::endl;
        return 1;
    }

    int** matrix = createMatrix(sizeX , sizeY);
    randomMatrix(matrix ,sizeX , sizeY);

    std::cout << "Normal matrix: " << std::endl;
    printMatrix(matrix , sizeX , sizeY);

    int** convMatrix = createMatrix(sizeY , sizeX);
    convertedMatrix(matrix , convMatrix , sizeY , sizeX);

    std::cout << std::endl;

    std::cout << "Converted matrix: " << std::endl;
    printMatrix(convMatrix , sizeY , sizeX);

    deleteMatrix(matrix , sizeX);
    deleteMatrix(convMatrix , sizeY);

    return 0;
}