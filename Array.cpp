#include <iostream>
#include "Array.h"

using namespace std;

BinarySearchTree::BinarySearchTree(int capacity) : capacity(capacity), size(0) {
    // Allocate memory for the array of pointers
    treeArray = new int*[capacity];
    // Initialize all pointers to nullptr
    for (int i = 0; i < capacity; ++i) {
        treeArray[i] = nullptr;
    }
}

BinarySearchTree::~BinarySearchTree(){
    //deallocate memory for the array of pointers
    delete[] treeArray; 
}

bool BinarySearchTree:: isEmpty(){
    return size == 0;
}

void BinarySearchTree::addBST(int key){
    //Start adding from the root
    int index = 0;
    // Traversing the tree to find the appropriate position
    while (index < capacity && treeArray[index] != nullptr) {
        if (key < *treeArray[index]) {
            index = 2 * index + 1; // Move to the left child
        } else if (key > *treeArray[index]) {
            index = 2 * index + 2; // Move to the right child
        } else {
            // Key already exists, do not insert again
            return;
        }
    }
    // Allocate memory for the new key and insert it
    treeArray[index] = new int(key);
    ++size;

}

bool BinarySearchTree::searchBST(int targetKey){
    // Start searching from the root
    int index = 0;
    // Traverse the tree
    while (index < capacity && treeArray[index] != nullptr) {
        if (targetKey < *treeArray[index]) {
            index = 2 * index + 1; // Move to the left child
        } else if (targetKey > *treeArray[index]) {
            index = 2 * index + 2; // Move to the right child
        } else {
            // Key found
            return true;
        }
    }
    // Key not found
    return false;
}

void BinarySearchTree::removeBST(int keyToDelete){
    // Start searching from the root
    int index = 0;
    while (index < capacity && treeArray[index] != nullptr) {
        if (keyToDelete < *treeArray[index]) {
            index = 2 * index + 1; // Move to the left child
        } else if (keyToDelete > *treeArray[index]) {
            index = 2 * index + 2; // Move to the right child
        } else {
            // Key found, delete
            delete treeArray[index];
            treeArray[index] = nullptr;
            --size;
            return;
        }
    }
    // Key not found
    cout << "Key to delete not found." << endl;
}
