#ifndef __HASHTABLE__HPP__
#define __HASHTABKE__HPP__

#include <vector>
#include <list>

template <typename T>
class HashTable
{
private:
    int m_line;
    std::vector<std::list<T>> m_table;

    int HashFunction(const int& key);

public:
    HashTable(const int& temp);
    void insert(const T& key);
    void pop(const T& key);
    void print() const;
};

#include "HashTable.tpp"

#endif//__HASHTABLE__HPP__