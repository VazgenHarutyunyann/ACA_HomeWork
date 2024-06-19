template<typename T>
int HashTable<T>::HashFunction(const int& key) 
{
    return key % m_line;
}

template<typename T>
HashTable<T>::HashTable(const int& temp) : m_line(temp) 
{
    m_table.resize(m_line);
}

template<typename T>
void HashTable<T>::insert(const T& key) 
{
    int index = HashFunction(key);
    m_table[index].push_back(key);
}

template<typename T>
void HashTable<T>::pop(const T& key) 
{
    int index = HashFunction(key);

    for (auto it = m_table[index].begin(); it != m_table[index].end(); ++it) 
    {
        if (*it == key) 
        {
            m_table[index].erase(it);
            break;
        }
    }
}

template<typename T>
void HashTable<T>::print() const 
{
    for (int i = 0; i < m_line; ++i) 
    {
        std::cout << i;
        for (const auto& it : m_table[i]) 
        {
            std::cout << "-->" << it;
        }
        std::cout << std::endl;
    }
}