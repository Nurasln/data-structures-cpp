#include "bst.h"

int main() {
    BST tree;

    // Insert nodes
    tree.root = tree.insert(tree.root, 50);
    tree.insert(tree.root, 30);
    tree.insert(tree.root, 70);
    tree.insert(tree.root, 20);
    tree.insert(tree.root, 40);
    tree.insert(tree.root, 60);
    tree.insert(tree.root, 80);

    cout << "Inorder Traversal: ";
    tree.inorderTraversal(tree.root);
    cout << endl;

    cout << "Preorder Traversal: ";
    tree.preorderTraversal(tree.root);
    cout << endl;

    cout << "Postorder Traversal: ";
    tree.postorderTraversal(tree.root);
    cout << endl;

    cout << "Height: " << tree.height(tree.root) << endl;
    cout << "Node Count: " << tree.nodeCount(tree.root) << endl;
    cout << "Leaf Count: " << tree.leafCount(tree.root) << endl;

    cout << "Min Value: " << tree.minValue(tree.root) << endl;
    cout << "Max Value: " << tree.maxValue(tree.root) << endl;

    int searchVal = 40;
    cout << "Search " << searchVal << ": "
         << (tree.search(tree.root, searchVal) ? "Found" : "Not Found") << endl;

    return 0;
}
