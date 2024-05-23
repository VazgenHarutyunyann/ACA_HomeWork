#include <iostream>

int** createMatrix(const int& sizeX , const int& sizeY)
{
    int** matrix = new int*[sizeX];

    for (int i = 0; i < sizeX; ++i)
    {
        matrix[i] = new int[sizeY];
    }
    
    return matrix;
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

void deleteMatrix(int** matrix , const int& sizeX)
{
    for (int i = 0; i < sizeX; ++i)
    {
        delete[] matrix[i];
        matrix[i] = nullptr;
    }
    
    delete matrix;
}

void matrixColumnSwap(int** matrix , const int& sizeX ,const int& swap1 ,const int& swap2)
{
    for (int i = 0; i < sizeX; ++i)
    {
        int temp = matrix[i][swap1];
        matrix[i][swap1] = matrix[i][swap2];
        matrix[i][swap2] = temp;
    }
    
}

int main()
{
    int sizeX = 0;
    std::cout << "Write sizeX for matrix: ";
    std::cin >> sizeX;

    int sizeY = 0;
    std::cout << "Write sizeY for matrix: ";
    std::cin >> sizeY;

    if (sizeX < 1 || sizeY < 1)
    {
        std::cout << "Your sizeX or sizeY smaller than 1: " << std::endl;
        return 1;
    }
    
    int** matrix = createMatrix(sizeX , sizeY);

    std::cout << "Fill your matrix: " << std::endl;
    fillMatrix(matrix , sizeX , sizeY);

    int swap1 = 0;
    std::cout << "Write first column for swap: ";
    std::cin >> swap1;

    int swap2 = 0;
    std::cout << "Write another column for swap: ";
    std::cin >> swap2;

    if (swap1 >= sizeY || swap2 >= sizeY)
    {
        std::cout << "Your swap number is bigger than sizeX: " << std::endl;
        deleteMatrix(matrix , sizeX);
        return 1;
    }

    if (swap1 < 0 || swap2 < 0)
    {
        std::cout << "Your swap number is smaller than 0: " << std::endl;
        deleteMatrix(matrix , sizeX);
        return 1;
    }
    
    if (swap1 == swap2)
    {
        std::cout << "swap1 = swap2: " << std::endl;
        deleteMatrix(matrix , sizeX);
        return 1;
    }

    std::cout << "Matrix before column swapping: " << std::endl;
    printMatrix(matrix , sizeX , sizeY);

    matrixColumnSwap(matrix , sizeX , swap1 , swap2);

    std::cout << "Matrix after column swapping: " << std::endl;
    printMatrix(matrix , sizeX , sizeY);

    deleteMatrix(matrix , sizeX);
    


    return 0;
}