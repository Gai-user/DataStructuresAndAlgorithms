#include <memory>
#include "BinaryTree.h"

int main() {
    
    auto root = std::make_unique<TreeNode<char>>('A');
    root->left = std::make_unique<TreeNode<char>>('B');
    root->right = std::make_unique<TreeNode<char>>('C');
    root->left->left = std::make_unique<TreeNode<char>>('D');
    root->right->left = std::make_unique<TreeNode<char>>('E');
    root->right->right = std::make_unique<TreeNode<char>>('F');

    BinaryTree<char> tree(std::move(root));
    tree.preOrder();
    tree.inOrder();
    tree.postOrder();
    return 0;
}