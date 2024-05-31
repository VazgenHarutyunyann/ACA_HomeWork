#include <iostream>

void print()
{
    std::cout << std::endl;
}

template <typename T , typename... Args>
void print(const T& word , const Args&... args)
{
    std::cout << word;
    if (sizeof...(args) > 0)
    {
        std::cout << ",";
    }
    print(args...);
    
}

int main()
{
    print(4 , "Hello World" , 3.6);
    print();
    print(3 , "Hi");
    return 0;
}