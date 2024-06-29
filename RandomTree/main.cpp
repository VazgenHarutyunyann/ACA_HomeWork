#include <iostream>
#include <ctime>

#include "Tree.hpp"

int main()
{
    srand(static_cast<unsigned>(time(0)));

    int max = randomNumber<int>(0, 10);
    TreeNode<int>* root = createRandomTree<int>(0, max);

    std::cout << "Tree layer by layer: ";
    traverseTree<int>(root);
    std::cout << std::endl;

    return 0;
}