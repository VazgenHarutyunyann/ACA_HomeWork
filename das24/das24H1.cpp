#include <iostream>

template <int T>
struct Fibonacci
{
    static const int value = Fibonacci<T - 1>::value + Fibonacci<T - 2>::value;
};

template <>
struct Fibonacci<0>
{
    static const int value = 0;
};

template <>
struct Fibonacci<1>
{
    static const int value = 1;
};


int main()
{

    std::cout << Fibonacci<1>::value << " "; 
    std::cout << Fibonacci<2>::value << " ";    
    std::cout << Fibonacci<3>::value << " "; 
    std::cout << Fibonacci<4>::value << " "; 
    std::cout << Fibonacci<5>::value << " "; 
    std::cout << Fibonacci<6>::value << " "; 
    std::cout << Fibonacci<7>::value << " "; 
    std::cout << Fibonacci<8>::value << " "; 
    std::cout << Fibonacci<9>::value << " "; 

    return 0;
}