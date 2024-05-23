#include <iostream>
#include <cstdlib>

void randomArray(int* arr , int size)
{
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 100;
    }
    
}

void printArray(int* arr , int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    
}

int oddInArray(int* arr , int size)
{
    int odd = 0;

    for (int i = 0; i < size; ++i)
    {
        if (arr[i] % 2 == 1)
        {
            ++odd;
        }
        
    }

    return odd;   
}

int* newArray(int* arr , int size , int odd)
{
    int* arr2 = new int[odd];
    int temp = 0;

    for (int i = 0; i < size; ++i)
    {
        if (arr[i] % 2 == 1)
        {
            arr2[temp] = arr[i];
            ++temp;
        }
        
    }

    return arr2;
    
}

int main(){

    int size = 0;
    std::cout << "Write size for array: ";
    std::cin >> size;

    if(size < 20)
    {
        std::cout << "Your size is smaller than 20: " << std::endl;
        return 1;
    }

    int* arr = new int[size];

    randomArray(arr , size);

    int odd = oddInArray(arr , size);
    int* arr2 = newArray(arr , size , odd);

    std::cout << "Array number 1: " << std::endl;
    printArray(arr , size);

    std::cout << std::endl;

    std::cout << "Array number 2: " << std::endl;
    printArray(arr2 , odd);

    delete[] arr;
    arr = nullptr;

    delete[] arr2;
    arr2 = nullptr;


    return 0;
}