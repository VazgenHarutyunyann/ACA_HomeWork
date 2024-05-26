#include <iostream>
#include <string>

#include "matrixFileSum.hpp"

int main()
{

    std::string fileName1 = "das22/testMatrix1.txt";
    std::string fileName2 = "das22/testMatrix2.txt";
    std::string fileName3 = "das22/testMatrix3.txt";

    int M1sizeX = findSizeX(fileName1);
    int M1sizeY = findSizeY<double>(fileName1);
    int M2sizeX = findSizeX(fileName2);
    int M2sizeY = findSizeY<double>(fileName2);

    Matrix<double> matrix1(M1sizeX , M1sizeY);
    Matrix<double> matrix2(M2sizeX , M2sizeY);

    matrix1.readFile(fileName1);
    std::cout << "Matrix1: " << std::endl;
    matrix1.printMatrix();

    matrix2.readFile(fileName2);
    std::cout << "Matrix2: " << std::endl;
    matrix2.printMatrix();

    Matrix<double> matrix3 = matrix1 + matrix2;
    std::cout << "Matrix3: " << std::endl;
    matrix3.printMatrix();
    matrix3.fillFile(fileName3);

    return 0;
}