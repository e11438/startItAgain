#include<iostream>

using namespace std;

class Node{
    public:
        int val;
        int height;
        int bf;
        Node * left;
        Node * right;

        Node(int val):val(val),left(NULL),right(NULL), height(0), bf(0) { }

};

class Tree
{
        Node * root;
        int size;
        bool insertSuccess;

        Node * rightRotation(Node * n)
        {
            Node * root = n->left;
            n->left = root->right;
            root->right = n;

            update(root->right);
            update(root);
            
            return root;
        }

        Node * leftRotation(Node * n)
        {
            Node * root = n->right;
            n->right = root->left;
            root->left = n;

            update(root->left);
            update(root);
            return root;
        }

        Node* leftLeftCase(Node* n)
        {
            return rightRotation(n);
        }
        Node* leftRightCase(Node* n)
        {
            n->left = leftRotation(n->left);
            return rightRotation(n);
        }
        Node* rightRightCase(Node* n)
        {
            return leftRotation(n);
        }
        Node* rightLeftCase(Node* n)
        {
            n->right = rightRotation(n->right);
            return leftRotation(n);
        }

        void update(Node * n)
        {
            int hl = -1;
            int hr = -1;

            if(n->left) hl = n->left->height;
            if(n->right) hr = n->right->height;

            n->height = max(hl, hr) + 1;
            n->bf = hr - hl;
        }
        Node* balance(Node* n)
        {
            if(n->bf < -1) //left heavy
            {
                if(n->left->bf < 0)
                    return leftLeftCase(n);
                else
                    return leftRightCase(n); 
            }
            else if(n->bf > 1)  //right heavy
            {
                if(n->right->bf > 0)
                    return rightRightCase(n);
                else
                    return rightLeftCase(n);
            }
            return n;
        }

        Node * insert(int v, Node * n)
        {
            //cout << ""<< endl;
            if(!n )
            {
                n = new Node(v);
                insertSuccess = true;
                size++;
                return n;
            }

            if(v < n->val)
            {
                n->left = insert(v, n->left);
            } 
            else if(v > n->val) 
            {
                n->right = insert(v, n->right);
            }

            //update bf and height of node after inserting
            update(n);
            n = balance(n);

            return n;
        }

        void preOrder(Node * n)
        {
            if(!n) return;
            if(n->left) preOrder(n->left);
            cout << n->val << " " << endl;
            if(n->right)    preOrder(n->right);
        }
    public:
        Tree():root(NULL), size(0),insertSuccess(false){};
        Tree(int val):root(new Node(val) ), size(1) {};
        int insert(int val)
        {
            insertSuccess = false;
            root = insert(val, root);
            return insertSuccess;
        }

        void preOrder()
        {
            preOrder(root);
        }
        int getSize(){return size;}

        int getHeight() {return root->height;}

};



int main()
{
    //Node n(3);
    //cout << n.val<< endl;

    Tree t;
    t.insert(5);
    t.insert(3);
    t.insert(6);
    t.insert(7);
    t.insert(8);
    t.insert(9);
    cout << "tree size - " << t.getSize() << " and height is " << t.getHeight() << endl;
    t.preOrder();

    return 0;
}