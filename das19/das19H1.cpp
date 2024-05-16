#include <iostream>

#include "moveMatrix.hpp"

int main()
{

    Matrix matrix1(3 , 4);
    matrix1.fillMatrix();
    Matrix matrix2(std::move(matrix1));

    std::cout << "Matrix 1: " << std::endl;
    matrix1.printMatrix();
    std::cout << "Matrix 2: " << std::endl;
    matrix2.printMatrix();

    Matrix matrix3(2, 2);
    matrix3.fillMatrix();
    Matrix matrix4(2, 2);
    matrix4 = std::move(matrix3);

    std::cout << "Matrix 3:" << std::endl;
    matrix3.printMatrix();
    std::cout << "Matrix 4:" << std::endl;
    matrix4.printMatrix();
    

    return 0;
}