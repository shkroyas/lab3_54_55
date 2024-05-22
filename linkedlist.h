#include"BST.h"

class Node{
    public:
        int info;
        Node* leftChild;
        Node* rightChild;

        Node(){};
        Node(int data) : info(data), leftChild(nullptr), rightChild(nullptr) {}
        Node(int data, Node* left, Node* right) : info(data), leftChild(left), rightChild(right) {}
};

class LLBST : public BST{
    private:
        Node* root;
    public:
        LLBST(){ root = nullptr; }
        ~LLBST(){}

        bool isEmpty();
        void addBST(int key);
        void removeBST(int keyToDelete);
        bool searchBST(int tagetKey);
};