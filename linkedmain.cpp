#include<iostream>
#include"linkedlist.h"

int main(){
    BST *tree = new LLBST();
    LLBST *BST = dynamic_cast<LLBST *>(tree);

    if(BST->isEmpty())
        std::cout<<"BST is empty\n";
    else
        std::cout<<"BST is not empty\n";

    std::cout<<"Adding some numbers in the BST\n";
    BST->addBST(6);
    BST->addBST(2);
    BST->addBST(12);
    BST->addBST(3);
    BST->addBST(8);
    BST->addBST(14);
    BST->addBST(5);

    std::cout<<"The BST is:\n";
    BST->inOrder(BST->getRoot());

    std::cout<<"\nRemoving root\n";
    BST->removeBST(BST->getRoot()->info);

    std::cout<<"Removing 2\n";
    BST->removeBST(2);

    std::cout<<"Removing 14\n";
    BST->removeBST(14);

    std::cout<<"The BST is:\n";
    BST->inOrder(BST->getRoot());

    std::cout<<"\nChecking for 2:\n";
    if(BST->searchBST(2))
        std::cout<<"It is in the BST\n";
    else
        std::cout<<"It is not in the BST\n";

    std::cout<<"Checking for 8:\n";
    if(BST->searchBST(8))
        std::cout<<"It is in the BST\n";
    else
        std::cout<<"It is not in the BST\n";
}