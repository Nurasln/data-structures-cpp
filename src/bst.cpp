#include "bst.h"

TreeNode::TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}

BST::BST() : root(nullptr) {}

void BST::clear(TreeNode* node) {
    if (node == nullptr) return;
    clear(node->left);
    clear(node->right);
    delete node;
}

TreeNode *BST::insert(TreeNode *node, int val)
{
    if (node == nullptr)
    {
        return new TreeNode(val);
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

TreeNode *BST::deleteNode(TreeNode *node, int val)
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
            TreeNode *temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr)
        {
            TreeNode *temp = node->left;
            delete node;
            return temp;
        }
        TreeNode *temp = minValueNode(node->right);
        node->data = temp->data;
        node->right = deleteNode(node->right, temp->data);
    }
    return node;
}

TreeNode *BST::minValueNode(TreeNode *node)
{
    TreeNode *current = node;
    while (current && current->left != nullptr)
    {
        current = current->left;
    }
    return current;
}

// Inorder Traversal
void BST::inorderTraversal(TreeNode *node)
{
    if (node == nullptr)
        return;
    inorderTraversal(node->left);
    cout << node->data << " ";
    inorderTraversal(node->right);
}

// Preorder Traversal
void BST::preorderTraversal(TreeNode *node)
{
    if (node == nullptr)
        return;
    cout << node->data << " ";
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

// Postorder Traversal
void BST::postorderTraversal(TreeNode *node)
{
    if (node == nullptr)
        return;
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    cout << node->data << " ";
}

bool BST::search(TreeNode *node, int val)
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

int BST::height(TreeNode *node)
{
    if (node == nullptr)
        return 0;
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return max(leftHeight, rightHeight) + 1;
}

int BST::nodeCount(TreeNode *node)
{
    if (node == nullptr)
        return 0;

    return 1 + nodeCount(node->left) + nodeCount(node->right);
}

int BST::minValue(TreeNode *node)
{
    if (node == nullptr)
        throw runtime_error("Tree is empty!");
    TreeNode *current = node;
    while (current->left != nullptr)
    {
        current = current->left;
    }
    return current->data;
}

int BST::maxValue(TreeNode *node)
{
    if (node == nullptr)
        throw runtime_error("Tree is empty!");
    TreeNode *current = node;
    while (current->right != nullptr)
    {
        current = current->right;
    }
    return current->data;
}
