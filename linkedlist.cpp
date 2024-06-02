#include"linkedlist.h"
#include<iostream>

bool LLBST::isEmpty(){
    if(root == nullptr)
        return true;
    else
        return false;
}

void LLBST::addBST(int key){
    if(isEmpty()){
        root = new Node(key);
    }
    else{
        Node* temp = root;
        while(true){
            if(key > temp->info){
                if(temp->rightChild == nullptr){
                    temp->rightChild = new Node(key);
                    return;
                }
                temp = temp->rightChild;             
            }
            else if(key < temp->info){
                if(temp->leftChild == nullptr){
                    temp->leftChild = new Node(key);
                    return;
                }
                temp = temp->leftChild;
            }
            else
                std::cout<<"Key cannot be same.";
        }
    }
}

void LLBST::removeBST(int keyToDelete){
    if(isEmpty()){
        std::cout<<"BST empty";
        return;
    }
    else{
        Node* temp = root;
        Node* parent = nullptr;
        //Locating the node
        while(temp != nullptr && temp->info != keyToDelete){
            parent = temp;
            if(keyToDelete > temp->info)
                temp = temp->rightChild;
            else
                temp = temp->leftChild;
        }
        //If key is not in BST
        if(temp == nullptr){
            std::cout<<"List empty";
            return;
        }
        //If key is in BST
        if(temp->rightChild == nullptr && temp->leftChild == nullptr){ //Case I: If node has no children
            if(temp == root)
                root = nullptr;
            else if(temp == parent->rightChild)
                parent->rightChild = nullptr;
            else
                parent->leftChild = nullptr;
            delete temp;
        }
        else if(temp->rightChild == nullptr){ //Case II a: If node has a left child
            if(temp == root)
                root = temp->leftChild;
            else if(temp == parent->rightChild)
                parent->rightChild = temp->leftChild;
            else
                parent->leftChild = temp->leftChild;
            delete temp;
        }
        else if(temp->leftChild == nullptr){ //Case II b: If node has a right child
            if(temp == root)
                root = temp->rightChild;
            else if(temp == parent->rightChild)
                parent->rightChild = temp->rightChild;
            else
                parent->leftChild = temp->rightChild;
            delete temp;
        }
        else{//Case III: If node has two children
            //Searching for maximum of left subtree
            Node* succ = temp->leftChild;
            while(succ->rightChild!=nullptr){
                succ = succ->rightChild;
            }
            int buffer = succ->info;
            removeBST(succ->info);
            temp->info = buffer;
        }
    }
}

bool LLBST::searchBST(int targetKey){
    if(isEmpty())
        std::cout<<"Tree is empty";
    else{
        Node* temp = root;

        while(temp != nullptr){
            if(targetKey == temp->info)
                return true;
            else if(targetKey > temp->info)
                temp = temp->rightChild;
            else
                temp = temp->leftChild;
        }
    }
    return false;
}

void LLBST::inOrder(Node* temp){
    if(temp != nullptr){
        inOrder(temp->leftChild);
        std::cout<<temp->info<<"\t";
        inOrder(temp->rightChild);
    }
}