#pragma once
#include <iostream>
#include <stdexcept>
#include <algorithm>

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val) : data(val), left(nullptr), right(nullptr) {}
};

template <typename T>
class BST
{
public:
    TreeNode<T> *root;

    BST() : root(nullptr) {}

    ~BST()
    {
        clear(root);
    }

    TreeNode<T> *insert(TreeNode<T> *node, T val);
    TreeNode<T> *deleteNode(TreeNode<T> *node, T val);
    TreeNode<T> *minValueNode(TreeNode<T> *node);

    void inorderTraversal(TreeNode<T> *node);
    void preorderTraversal(TreeNode<T> *node);
    void postorderTraversal(TreeNode<T> *node);

    bool search(TreeNode<T> *node, T val);

    int height(TreeNode<T> *node);
    int nodeCount(TreeNode<T> *node);
    int leafCount(TreeNode<T> *node);

    T minValue(TreeNode<T> *node);
    T maxValue(TreeNode<T> *node);

private:
    void clear(TreeNode<T> *node);
};

// Methods

// Clear the tree
template <typename T>
void BST<T>::clear(TreeNode<T> *node)
{
    if (node == nullptr)
        return;
    clear(node->left);
    clear(node->right);
    delete node;
}

// Insert a new node
template <typename T>
TreeNode<T> *BST<T>::insert(TreeNode<T> *node, T val)
{
    if (node == nullptr)
    {
        return new TreeNode<T>(val);
    }

    if (val < node->data)
    {
        node->left = insert(node->left, val);
    }
    else if (val > node->data)
    {
        node->right = insert(node->right, val);
    }
    return node;
}

// Delete a node
template <typename T>
TreeNode<T> *BST<T>::deleteNode(TreeNode<T> *node, T val)
{
    if (node == nullptr)
    {
        return node;
    }
    if (val < node->data)
    {
        node->left = deleteNode(node->left, val);
    }
    else if (val > node->data)
    {
        node->right = deleteNode(node->right, val);
    }
    else
    {
        if (node->left == nullptr)
        {
            TreeNode<T> *temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr)
        {
            TreeNode<T> *temp = node->left;
            delete node;
            return temp;
        }
        TreeNode<T> *temp = minValueNode(node->right);
        node->data = temp->data;
        node->right = deleteNode(node->right, temp->data);
    }
    return node;
}

// Find the node with minimum value
template <typename T>
TreeNode<T> *BST<T>::minValueNode(TreeNode<T> *node)
{
    TreeNode<T> *current = node;
    while (current && current->left != nullptr)
    {
        current = current->left;
    }
    return current;
}

// Inorder Traversal
template <typename T>
void BST<T>::inorderTraversal(TreeNode<T> *node)
{
    if (node == nullptr)
        return;
    inorderTraversal(node->left);
    std::cout << node->data << " ";
    inorderTraversal(node->right);
}

// Preorder Traversal
template <typename T>
void BST<T>::preorderTraversal(TreeNode<T> *node)
{
    if (node == nullptr)
        return;
    std::cout << node->data << " ";
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

// Postorder Traversal
template <typename T>
void BST<T>::postorderTraversal(TreeNode<T> *node)
{
    if (node == nullptr)
        return;
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    std::cout << node->data << " ";
}

// Search for a value
template <typename T>
bool BST<T>::search(TreeNode<T> *node, T val)
{
    if (node == nullptr)
        return false;
    if (val == node->data)
        return true;
    else if (val < node->data)
        return search(node->left, val);
    else
        return search(node->right, val);
}

// Calculate height of the tree
template <typename T>
int BST<T>::height(TreeNode<T> *node)
{
    if (node == nullptr)
        return 0;
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return std::max(leftHeight, rightHeight) + 1;
}

// Count total nodes
template <typename T>
int BST<T>::nodeCount(TreeNode<T> *node)
{
    if (node == nullptr)
        return 0;

    return 1 + nodeCount(node->left) + nodeCount(node->right);
}

// Returns the smallest value by traversing to the leftmost node.
template <typename T>
T BST<T>::minValue(TreeNode<T> *node)
{
    if (node == nullptr)
        throw std::runtime_error("Tree is empty!");
    TreeNode<T> *current = node;
    while (current->left != nullptr)
    {
        current = current->left;
    }
    return current->data;
}

// Returns the largest value by traversing to the rightmost node.
template <typename T>
T BST<T>::maxValue(TreeNode<T> *node)
{
    if (node == nullptr)
        throw std::runtime_error("Tree is empty!");
    TreeNode<T> *current = node;
    while (current->right != nullptr)
    {
        current = current->right;
    }
    return current->data;
}
