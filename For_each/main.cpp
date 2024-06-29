#include <iostream>
#include <vector>

template <typename T , typename Iterator>
T my_for_each(const Iterator& begin , const Iterator& end , T func)
{
    for (auto i = begin; i != end; ++i)
    {
        func(*i);
    }
    
    return func;
}

template <typename T>
void print(const T& num)
{
    std::cout << num << " ";
}

int main()
{
    std::vector<int> myVec{3 , 6 , -7 , 5 , 9};
    std::cout << "Vector elements: " << std::endl;
    my_for_each(myVec.begin() , myVec.end() , print<int>);

    return 0;
}