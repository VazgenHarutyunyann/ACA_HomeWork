#ifndef __LIST__
#define __LIST__

#include <iostream>

template <typename T>
class List
{
private:
    struct Node
    {
        T m_data;
        Node* m_next;
        Node(T data) : m_data(data) , m_next(nullptr) {}
    };

    Node* m_head;

public:
    List();

    void insert(const T& value);
    void push_front(const T& value);
    T pop_front();
    void print() const;
    ~List();
};

template <typename T>
List<T>::List() : m_head(nullptr) {}

template <typename T>
void List<T>::insert(const T& value)
{
    Node* newNode = new Node(value);
    if (m_head == nullptr)
    {
        m_head = newNode;
    }
    else
    {
        Node* temp = m_head;
        while(temp->m_next)
        {
            temp = temp->m_next;
        }

        temp->m_next = newNode;
    }
        
}

template <typename T>
void List<T>::push_front(const T& value)
{
    Node* newNode = new Node(value);
    newNode->m_next = m_head;
    m_head = newNode;
}

template <typename T>
T List<T>::pop_front()
{
    if (m_head == nullptr)
    {
        std::cout << "Empty List" << std::endl;
        return T();
    }
    else
    {
        Node* temp = m_head;
        T popedValue = temp->m_data;
        m_head = m_head->m_next;
        delete temp;
        return popedValue;
    }
    
}

template <typename T>
void List<T>::print() const
{
    Node* temp = m_head;
    while(temp != nullptr)
    {
        std::cout << temp->m_data  << " -> ";
        temp = temp->m_next;
    }
    std::cout << "nullptr " << std::endl;
}

template <typename T>
List<T>::~List()
{
    while (m_head != nullptr)
    {
        Node* temp = m_head;
        m_head = m_head->m_next;
        delete temp;
    }
}

#endif //__LIST__