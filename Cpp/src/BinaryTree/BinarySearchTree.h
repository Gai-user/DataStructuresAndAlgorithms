#ifndef BIANRY_SEARCH_TREE_H
#define BIANRY_SEARCH_TREE_H

#include <iostream>
#include <memory>
#include "../../utils/Node.h"
#include "BinaryTree.h"

// 二叉搜索树
// 节点的值比左子树的任一节点的值大
// 比右子树任一节点的值小

template <typename T>
class BinarySearchTree : public BinaryTree<T>
{
private:
    void insertHelper(std::unique_ptr<TreeNode<T>>& n, const T& value);
    TreeNode<T>* findHelper(std::unique_ptr<TreeNode<T>>& n, const T& value);
public:
    BinarySearchTree() = default;
    void insert(T value);
    TreeNode<T>* find(const T& value);

};

template <typename T>
void BinarySearchTree<T>::insertHelper(std::unique_ptr<TreeNode<T>>& n, const T& value) 
{
    if (n == nullptr) {
        n = std::make_unique<TreeNode<T>>(value);
        return;
    }
    if (value > n->value) {
        insertHelper(n->right, value);
    } else {
        insertHelper(n->left, value);
    }
}

template <typename T>
TreeNode<T>* BinarySearchTree<T>::findHelper(std::unique_ptr<TreeNode<T>>& n, const T& value)
{
    if (n == nullptr) {
        return n.get();
    }
    if (value > n->value) {
        return findHelper(n->right, value);
    } else if (value < n->value) {
        return findHelper(n->left, value);
    } else {
        return n.get();
    }
}

template <typename T>
void BinarySearchTree<T>::insert(T value) {
    insertHelper(this->node, value);
}

template <typename T>
TreeNode<T>* BinarySearchTree<T>::find(const T& value)
{
    return findHelper(this->node, value);
}
#endif // BIANRY_SEARCH_TREE_H