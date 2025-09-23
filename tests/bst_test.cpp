#include "bst.h"

int main() {
    BST<int> int_tree;

    // Insert nodes
    int_tree.root = int_tree.insert(int_tree.root, 50);
    int_tree.insert(int_tree.root, 30);
    int_tree.insert(int_tree.root, 70);
    int_tree.insert(int_tree.root, 20);
    int_tree.insert(int_tree.root, 40);
    int_tree.insert(int_tree.root, 60);
    int_tree.insert(int_tree.root, 80);

    std::cout << "Inorder Traversal: ";
    int_tree.inorderTraversal(int_tree.root);
    std::cout << std::endl;

    std::cout << "Preorder Traversal: ";
    int_tree.preorderTraversal(int_tree.root);
    std::cout << std::endl;

    std::cout << "Postorder Traversal: ";
    int_tree.postorderTraversal(int_tree.root);
    std::cout << std::endl;

    std::cout << "Height: " << int_tree.height(int_tree.root) << std::endl;
    std::cout << "Node Count: " << int_tree.nodeCount(int_tree.root) << std::endl;
    std::cout << "Leaf Count: " << int_tree.leafCount(int_tree.root) << std::endl;

    std::cout << "Min Value: " << int_tree.minValue(int_tree.root) << std::endl;
    std::cout << "Max Value: " << int_tree.maxValue(int_tree.root) << std::endl;

    int searchVal = 40;
    std::cout << "Search " << searchVal << ": "
         << (int_tree.search(int_tree.root, searchVal) ? "Found" : "Not Found") << std::endl;

    return 0;
}
