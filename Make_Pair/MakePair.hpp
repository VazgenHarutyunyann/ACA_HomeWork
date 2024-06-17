#ifndef __MAKEPAIR__HPP__
#define __MAKEPAIR__HPP__

template <typename T1, typename T2>
struct Pair {
    T1 m_first;
    T2 m_second;

    Pair();
    Pair(const T1& first, const T2& second);
    Pair(T1&& first, T2&& second);
    void print() const;
};

template <typename T1, typename T2>
Pair<T1, T2> make_my_pair(T1&& first, T2&& second);

#include "MakePair.tpp"

#endif // __MAKEPAIR__HPP__