#ifndef __TREE__HPP__
#define __TREE__HPP__

#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <ctime>

template <typename T>
struct TreeNode 
{
    T m_value;
    std::vector<TreeNode*> m_leaf;
    TreeNode(const T& value) : m_value(value) {}
};

template <typename T>
T randomNumber(const int& min, const int& max) 
{
    return min + rand() % (max - min + 1);
}

template <typename T>
TreeNode<T>* createRandomTree(const int& current, const int& max) 
{
    if (current > max) 
    {
        return nullptr;
    }
    
    TreeNode<T>* root = new TreeNode<T>(randomNumber<int>(0, 100)); 
    int numberLeaf = randomNumber<int>(0, 3);  

    for (int i = 0; i < numberLeaf; ++i) 
    {
        TreeNode<T>* child = createRandomTree<T>(current + 1, max);
        if (child) 
        {
            root->m_leaf.push_back(child);
        }
    }

    return root;
}

template <typename T>
void traverseTree(TreeNode<T>* root) 
{
    if (root == nullptr) 
    {
        return;
    }

    std::queue<TreeNode<T>*> temp;
    temp.push(root);

    while (!temp.empty()) 
    {
        TreeNode<T>* current = temp.front();
        temp.pop();

        std::cout << current->m_value << " ";

        for (TreeNode<T>* child : current->m_leaf)
        {
            temp.push(child);
        }
    }
}

#endif //__TREE__HPP__