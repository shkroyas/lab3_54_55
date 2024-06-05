#include <iostream>
#include "Array.h"

using namespace std;

int main() {
    BinarySearchTree bst(10);
    cout << "Is tree empty? " << bst.isEmpty() << endl;
    // Testing the binary search tree
    bst.addBST(50);
    bst.addBST(30);
    bst.addBST(70);
    bst.addBST(20);
    bst.addBST(40);
    bst.addBST(60);
    bst.addBST(80);
    cout << "Is tree empty? " << bst.isEmpty() << endl;
    cout << "The BST in inorder traversal is: ";
    bst.inorderTraversal(0);
    cout << endl;
    bst.searchBST(30) ? cout << "Key found" << endl : cout << "Key not found" << endl;
    bst.searchBST(100)? cout << "Key found" << endl : cout << "Key not found" << endl;
    
    }
