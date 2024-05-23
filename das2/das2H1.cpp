#include <iostream>

void fillArray(int* arr , int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << i + 1 << ") ";
        std::cin >> arr[i];
    }
    
}

void printArray(int* arr , int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    
}

int main(){

    int size = 0;
    std::cout << "Write size for array: ";
    std::cin >> size;

    int* arr = new int[size];

    std::cout << "Fill array: " << std::endl;
    fillArray(arr , size);

    printArray(arr , size);

    delete[] arr;
    arr = nullptr;


    return 0;
}