#pragma once
#include <iostream>
#include <stdexcept>

using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val);
};

class BST
{
public:
    TreeNode *root;

    BST();

    ~BST()
    {
        clear(root);
    }

    TreeNode *insert(TreeNode *node, int val);
    TreeNode *deleteNode(TreeNode *node, int val);
    TreeNode *minValueNode(TreeNode *node);

    void inorderTraversal(TreeNode *node);
    void preorderTraversal(TreeNode *node);
    void postorderTraversal(TreeNode *node);

    bool search(TreeNode *node, int val);

    int height(TreeNode *node);
    int nodeCount(TreeNode *node);
    int leafCount(TreeNode *node);

    int minValue(TreeNode *node);
    int maxValue(TreeNode *node);

private:
    void clear(TreeNode *node);
};
