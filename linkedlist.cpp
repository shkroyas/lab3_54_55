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
        while(temp != nullptr){
            if(key > temp->info)
                temp = temp->rightChild;
            else if(key < temp->info)
                temp = temp->leftChild;
            else
                std::cout<<"Key cannot be same.";
        }
        temp = new Node; 
    }
}

void LLBST::removeBST(int keyToDelete){
    
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