#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include <memory>

template <typename T>
struct TreeNode
{
    T value;
    std::unique_ptr<TreeNode<T>> left;
    std::unique_ptr<TreeNode<T>> right;

    explicit TreeNode(const T& val) : value(val), left(nullptr), right(nullptr) {}
};

template <typename T>
class BinaryTree
{
private:
    std::unique_ptr<TreeNode<T>> node;
    void preOrderRecursive(const TreeNode<T>* n) const;
    void inOrderRecursive(const TreeNode<T>* n) const;
    void postOrderRecursive(const TreeNode<T>* n) const;

public:
    BinaryTree() = default;
    BinaryTree(std::unique_ptr<TreeNode<T>> n);
    ~BinaryTree() = default;

    void preOrder() const;
    void inOrder() const;
    void postOrder() const;
};

template <typename T>
BinaryTree<T>::BinaryTree(std::unique_ptr<TreeNode<T>> n) : node(std::move(n)) {}

template <typename T>
void BinaryTree<T>::preOrderRecursive(const TreeNode<T>* n) const
{
    if (n == nullptr) {
        return;
    }
    std::cout << n->value << " ";
    preOrderRecursive(n->left.get());
    preOrderRecursive(n->right.get());
}

template <typename T>
void BinaryTree<T>::inOrderRecursive(const TreeNode<T>* n) const
{
    if (n == nullptr) {
        return;
    }
    inOrderRecursive(n->left.get());
    std::cout << n->value << " ";
    inOrderRecursive(n->right.get());
}

template <typename T>
void BinaryTree<T>::postOrderRecursive(const TreeNode<T>* n) const
{
    if (n == nullptr) {
        return;
    }

    postOrderRecursive(n->left.get());
    postOrderRecursive(n->right.get());
    std::cout << n->value << " ";
}

template <typename T>
void BinaryTree<T>::preOrder() const
{
    std::cout << "Preorder traversal: " ;
    preOrderRecursive(this->node.get());
    std::cout << std::endl;
}

template <typename T>
void BinaryTree<T>::inOrder() const
{
    std::cout << "Inorder traversal: ";
    inOrderRecursive(this->node.get());
    std::cout << std::endl;
}

template <typename T>
void BinaryTree<T>::postOrder() const
{
    std::cout << "Postorder traversal: ";
    postOrderRecursive(this->node.get());
    std::cout << std::endl;
}
#endif // BINARY_TREE_H