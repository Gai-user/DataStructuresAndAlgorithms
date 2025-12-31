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
    void remove(const T& data); // 只适用于没有重复值的二叉搜索树

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

template <typename T>
void BinarySearchTree<T>::remove(const T& data)
{
    if (this->node == nullptr) {
        return;
    }
    TreeNode<T>* DNode = this->node.get(); // 需要删除的节点
    TreeNode<T>* FNode = nullptr; // 删除节点的父节点

    // 找到需要删除的节点
    while (DNode != nullptr && DNode->value != data) {
        FNode = DNode;
        if (DNode->value > data) {
            DNode = DNode->left.get();
        } else {
            DNode = DNode->right.get();
        }
    }
    if (!DNode) {
        return;
    }

    if (DNode->left && DNode->right) {
        // 寻找右子树的最小节点
        TreeNode<T>* minNode = DNode;
        TreeNode<T>* FminNode = nullptr;
        while (minNode->left)
        {
            FminNode = minNode;
            minNode = minNode->left.get();
        }
        // 将当前删除节点替换为minNode
        DNode->value = minNode->value;
        // 现在需要删除的节点为右子树的最小节点
        DNode = minNode;
        FNode = FminNode;
        
    }

    std::unique_ptr<TreeNode<T>> NextNode;
    if (DNode->left) {
        NextNode = std::move(DNode->left);
    } else if (DNode->right) {
        NextNode = std::move(DNode->right);
    } 
    if (!FNode) {
        this->node = std::move(NextNode);
        return;
    }
    if (FNode->left.get() == DNode) {
        FNode->left = std::move(NextNode);
    } else {
        FNode->right = std::move(NextNode);
    }

}
#endif // BIANRY_SEARCH_TREE_H