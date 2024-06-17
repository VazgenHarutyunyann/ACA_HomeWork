#ifndef __MAKEPAIR__TPP__
#define __MAKEPAIR__TPP__

#include <iostream>

template <typename T1, typename T2>
Pair<T1, T2>::Pair() : m_first(T1()), m_second(T2()) {}

template <typename T1, typename T2>
Pair<T1, T2>::Pair(const T1& first, const T2& second) : m_first(first), m_second(second) {}

template <typename T1, typename T2>
Pair<T1, T2>::Pair(T1&& first, T2&& second) : m_first(static_cast<T1&&>(first)), m_second(static_cast<T2&&>(second)) {}

template <typename T1, typename T2>
Pair<T1, T2> make_my_pair(T1&& first, T2&& second) 
{
    return Pair<T1, T2>(static_cast<T1&&>(first), static_cast<T2&&>(second));
}

template <typename T1, typename T2>
void Pair<T1, T2>::print() const 
{
    std::cout << m_first << " , " << m_second << std::endl;
}

template struct Pair<int, double>;
template struct Pair<std::string, int>;
template struct Pair<std::string, double>;

#endif // __MAKEPAIR__TPP__