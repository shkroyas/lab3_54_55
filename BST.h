
class BST{
    public:
        //Constructor
        BST();
        //Destructor
        ~BST();
        //all the virtual functions for teh Binary Tree
        virtual bool isEmpty() = 0;
        virtual void addBST(int key) = 0;
        virtual void removeBST(int keyToDelete) = 0;
        virtual bool searchBST(int targetkey) = 0;

};