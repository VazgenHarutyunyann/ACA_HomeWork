#include <iostream>

struct Tree
{
    int m_value;
    Tree* m_left;
    Tree* m_right;

    Tree(const int& value) : m_value(value) , m_left(nullptr) , m_right(nullptr) {}
};

void postorderTraversal(Tree* root)
{
    if(root == nullptr)
    {
        return;
    }

    postorderTraversal(root->m_right);

    postorderTraversal(root->m_left);

    std::cout << root->m_value << " ";

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
    
    std::cout << "Postorder traversal: ";
    postorderTraversal(root);
    
    delete root->m_right->m_right;
    delete root->m_right->m_left;
    delete root->m_left->m_left;
    delete root->m_left->m_right;
    delete root->m_left;
    delete root->m_right;
    delete root;

    return 0;
}