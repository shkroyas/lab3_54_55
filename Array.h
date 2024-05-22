#include "BST.h"

class BinarySearchTree {
private:
    int** treeArray; // Array of pointers to simulate the tree structure
    int capacity;    // Total capacity of the array
    int size;        // Current size 
public:
    // Constructor
    BinarySearchTree(int capacity);

    // Destructor
    ~BinarySearchTree();

    // Method to check if the tree is empty
    bool isEmpty();

    // Method to add a key to the tree
    void addBST(int key);

    // Method to search for a key in the tree
    bool searchBST(int targetKey);

    // Method to remove a key from the tree
    void removeBST(int keyToDelete);
};

