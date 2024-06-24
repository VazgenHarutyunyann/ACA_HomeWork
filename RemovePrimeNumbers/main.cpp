#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

void printVector(const auto& Vector)
{
    for (const auto& it : Vector)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> myVec{3 , 57 , 23 , 22 , 4 , 5 , 8 , 10 , 15};

    std::cout << "My vector with prime numbers: " << std::endl;
    printVector(myVec);

    auto isPrime = [](const int& value) { if(value <= 1){return false;} for (int i = 2; i <= sqrt(value); ++i){if(value % i == 0){return false;}}return true;};
    myVec.erase(std::remove_if(myVec.begin() , myVec.end() , isPrime) , myVec.end());

    std::cout << "My vector without prime numbers: " << std::endl;
    printVector(myVec);

    return 0;
}
