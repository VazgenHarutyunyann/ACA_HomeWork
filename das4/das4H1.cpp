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

void matrixSwapRow(int** matrix , const int& sizeY ,const int& swap1 ,const int& swap2)
{
    for (int i = 0; i < sizeY; ++i)
    {
        int temp = matrix[swap1][i];
        matrix[swap1][i] = matrix[swap2][i];
        matrix[swap2][i] = temp;
    }
    
}

void fillMatrix(int** matrix ,const int& sizeX ,const int& sizeY)
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

void deleteMatrix(int** matrix, const int& sizeX)
{
    for (int i = 0; i < sizeX; ++i)
    {
        delete[] matrix[i];
        matrix[i] = nullptr;
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

    if (sizeX < 1 || sizeY < 1)
    {
        std::cout << "Your sizeX or sizeY smaller than 1: " << std::endl;
        return 1;
    }
    

    int** matrix = createMatrix(sizeX , sizeY);

    std::cout << "Fill your matrix: " << std::endl;
    fillMatrix(matrix , sizeX , sizeY);

    int swap1 = 0;
    std::cout << "Write which row you are going to swap: ";
    std::cin >> swap1;

    int swap2 = 0;
    std::cout << "Write another row you are going to swap: ";
    std::cin >> swap2;

    if (swap1 >= sizeX || swap2 >= sizeX)
    {
        std::cout << "sizeX is smaller than your swap number: " << std::endl;
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
    
    

    std::cout << "Matrix before swapping: " << std::endl;
    printMatrix(matrix , sizeX , sizeY);

    std::cout << "Matrix after swapping: " << std::endl;
    matrixSwapRow(matrix , sizeY , swap1 , swap2);
    printMatrix(matrix , sizeX , sizeY);

    deleteMatrix(matrix , sizeX);




    return 0;
}