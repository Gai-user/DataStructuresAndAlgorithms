#include <memory>
#include <cassert>
#include "BinaryTree.h"
#include "BinarySearchTree.h"

void test_binary_tree() {
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
}

void test_binary_search_tree() {
    BinarySearchTree<int> search_tree;
    search_tree.insert(9);
    search_tree.insert(8);
    search_tree.insert(10);
    search_tree.insert(7);
    search_tree.insert(11);

    search_tree.inOrder();
    auto result = search_tree.find(5);
    auto result2 = search_tree.find(10);
    assert(result == nullptr);
    assert(result2->value == 10);
}

int main() {
    
    test_binary_search_tree();
    
    return 0;
}