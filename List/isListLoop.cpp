#include <iostream>

template <typename T>
struct List
{
    int m_value;
    List* m_next;
    List(const T& value) : m_value(value), m_next(nullptr) {}
};

template <typename T>
bool hasLoop(List<T>* head)
{
    List<T>* fast = head;
    List<T>* slow = head;

    while (fast != nullptr && fast->m_next != nullptr)
    {
        slow = slow->m_next;
        fast = fast->m_next->m_next;
        
        if (fast == slow)
        {
            return true;
        }
        
    }

    return false;
    
}

int main() {
    List<int> *head = new List<int>(1);
    head->m_next = new List<int>(2);
    head->m_next->m_next = new List<int>(3);
    head->m_next->m_next->m_next = new List<int>(4);
    head->m_next->m_next->m_next->m_next = head->m_next;
    
    if (hasLoop(head) == true) 
    {
        std::cout << "We found loop! " << std::endl;
    } 
    else 
    {
        std::cout << "No loop found! " << std::endl;
    }
    
    delete head->m_next->m_next->m_next->m_next;
    delete head->m_next->m_next->m_next;
    delete head->m_next->m_next;
    delete head->m_next;
    delete head;
    
    return 0;
}