#include "++operatorMatrix.hpp"

int main()
{
    Matrix x(3, 3);
    x.fillMatrix();

    std::cout << "Matrix before: " << std::endl;
    x.printMatrix();

    ++x;
    std::cout << "Matrix after prefix increment: " << std::endl;
    x.printMatrix();

    x++;
    std::cout << "Matrix after postfix increment: " << std::endl;
    x.printMatrix();

    return 0;
}