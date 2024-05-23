#include <iostream>
#include <cstdlib>


int main() {

    int i = 0;
    std::cout << "Write the value of i: ";
    std::cin >> i;

    int j = 0;
    std::cout << "Write the value of j: ";
    std::cin >> j;

    int **array = (int **)malloc(i * sizeof(int *));
    for (int row = 0; row < i; row++) {
        array[row] = (int *)malloc(j * sizeof(int));
    }

    std::cout << "Enter values for the array:" << std::endl;
    for (int row = 0; row < i; row++) {
        for (int col = 0; col < j; col++) {
            std::cout << "Enter value for array[" << row << "][" << col << "]: ";
            std::cin >> array[row][col];
        }
    }

    // Print the array
    std::cout << "Array elements:" << std::endl;
    for (int row = 0; row < i; row++) {
        for (int col = 0; col < j; col++) {
            std::cout << array[row][col] << " ";
        }
        std::cout << std::endl;
    }

    // Free memory
    for (int row = 0; row < i; row++) {
        free(array[row]);
    }
    free(array);

    return 0;
}