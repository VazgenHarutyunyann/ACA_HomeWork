#include <iostream>
#include <vector>
#include <cmath>

bool isPrime(auto& number)
{
    if (number <= 1)
    {
        return false;
    }
    
    for (int i = 2; i <= std::sqrt(number); ++i)
    {
        if (number % i == 0)
        {
            return false;
        }
        
    }

    return true;
}

void printArray(auto& arr)
{
    for (auto it = arr.begin(); it != arr.end(); ++it)
    {
        std::cout << *it << " ";
    }

    std::cout << std::endl;
}

void deleteSimpleRot(auto& vector)
{
    for (auto it = vector.begin(); it != vector.end(); )
    {
        if (isPrime(*it))
        {
            it = vector.erase(it);
        }
        else
        {
            ++it;
        }
        
    }
}

int main()
{
    std::vector<int> myVec{3 , 5 , 6 , 10 , 22};

    std::cout << "Vector before: " << std::endl;
    printArray(myVec);

    deleteSimpleRot(myVec);

    std::cout << "Vector after: " << std::endl;
    printArray(myVec);

    return 0;
}