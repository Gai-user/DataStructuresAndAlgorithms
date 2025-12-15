#ifndef NODE_H
#define NODE_H

template <typename T>
struct TreeNode
{
    T value;
    std::unique_ptr<TreeNode<T>> left;
    std::unique_ptr<TreeNode<T>> right;

    explicit TreeNode(const T& val) : value(val), left(nullptr), right(nullptr) {}
};

#endif // NODE_H