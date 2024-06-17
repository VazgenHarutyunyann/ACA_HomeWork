#include <iostream>
#include <queue>

struct Tree
{
    int m_value;
    Tree* m_left;
    Tree* m_right;

    Tree(const int& value) : m_value(value) , m_left(nullptr) , m_right(nullptr) {}
};

void LayerByLayerTraversal(Tree* root)
{
    if(root == nullptr)
    {
        return;
    }

    std::queue<Tree*> temp;
    temp.push(root);

    while (!temp.empty()) 
    {
        Tree* current = temp.front();
        temp.pop();

        std::cout << current->m_value << " ";

        if (current->m_left) 
        {
            temp.push(current->m_left);
        }
        if (current->m_right) 
        {
            temp.push(current->m_right);
        }
    }

}

int main()
{
    Tree* root = new Tree(1);
    root->m_left = new Tree(2);
    root->m_right = new Tree(3);
    root->m_left->m_left = new Tree(4);
    root->m_left->m_right = new Tree(5);
    root->m_right->m_left = new Tree(6);
    root->m_right->m_right = new Tree(7);
    
    std::cout << "Layer by layer traversal: ";
    LayerByLayerTraversal(root);
    
    delete root->m_right->m_right;
    delete root->m_right->m_left;
    delete root->m_left->m_left;
    delete root->m_left->m_right;
    delete root->m_left;
    delete root->m_right;
    delete root;

    return 0;
}