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

int primeNumbers(int** matrix , const int& sizeX , const int& sizeY)
{
    int primeNumber = 0;

    for (int i = 0; i < sizeX; ++i)
    {
        for (int j = 0; j < sizeY; ++j)
        {
            if (matrix[i][j] % 2 == 1)
            {
                ++primeNumber;
            }
            
        }
        
    }

    return primeNumber;
    
}

void fillMatrix(int** matrix , const int& sizeX , const int& sizeY)
{
    for (int i = 0; i < sizeX; ++i)
    {
        for (int j = 0; j < sizeY; ++j)
        {
            std::cout << j + 1 << ")";
            std::cin >> matrix[i][j];
        }

        std::cout << std::endl;
        
    }
    
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

void printArray(int* arr , const int& size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
}

void deleteMatrix(int** matrix , const int& sizeX)
{
    for (int i = 0; i < sizeX; ++i)
    {
        delete[] matrix[i];
        matrix[i] = nullptr;
    }
    
    delete matrix;
}

void primeArray(int* arr , int** matrix , const int& sizeX , const int& sizeY)
{
    int temp = 0;

    for (int i = 0; i < sizeX; ++i)
    {
        for (int j = 0; j < sizeY; ++j)
        {
            if (matrix[i][j] % 2 == 1)
            {
                arr[temp] = matrix[i][j];
                ++temp;
            }
            
        }
        
    }
    
}



int main()
{
    int sizeX = 0;
    std::cout << "Write sizeX for array: ";
    std::cin >> sizeX;
    if (sizeX < 1)
    {
        std::cout << "Your sizeX smaller than 1: " << std::endl;
        return 1;
    }
    

    int sizeY = 0;
    std::cout << "Write sizeY for array: ";
    std::cin >> sizeY;
    if (sizeY < 1)
    {
        std::cout << "Your sizeY smaller than 1: " << std::endl;
        return 1;
    }
    

    int** matrix = createMatrix(sizeX , sizeY);

    std::cout << "Fill matrix: " << std::endl;
    fillMatrix(matrix , sizeX , sizeY);

    int prime = primeNumbers(matrix , sizeX , sizeY);
    int* primeArr = (int*)malloc(prime * sizeof(int));

    if (primeArr == nullptr)
    {
        std::cout << "Your array equal to nullptr: " << std::endl;
        return 1;
    }

    primeArray(primeArr , matrix , sizeX , sizeY);
    
    std::cout << "Matrix: " << std::endl;
    printMatrix(matrix , sizeX , sizeY);

    std::cout << std::endl;

    std::cout << "Prime array: " << std::endl;
    printArray(primeArr , prime);

    deleteMatrix(matrix , sizeX);
    free(primeArr);
    primeArr = nullptr;
    

    return 0;
}