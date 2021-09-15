#include<iostream>

using namespace std;


class BSTree
{
    class Node{
    public:
        int val;
        int height;
        Node * left;
        Node * right;

        Node(int val):val(val),left(NULL),right(NULL), height(0){ }

};

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

        void update(Node * n)
        {
            int hl = -1;
            int hr = -1;

            if(n->left) hl = n->left->height;
            if(n->right) hr = n->right->height;

            n->height = max(hl, hr) + 1;
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
            update(n);
            return n;
        }

        Node * getMin(Node * n)
        {

            while(n->left)
            {
                n = n->left;
            }
            return n;
            
        }
        
        Node* remove(int val, Node * n)
        {
            if(!n)  return n;
            if(n->val < val) // if value is lager remove in right subtree
            {
                n->right = remove(val, n->right);
            }
            else if(n->val > val) // if value is smaller remove in left sub tree
            {
                n->left = remove(val, n->left);
            }
            else    // if value matches
            {
                if(!(n->left) && !(n->right))   // leaf node
                {
                    delete n;
                    return NULL;
                }
                else if(!(n->left)) // only right subtree exist
                {
                    Node* node = n->right;
                    delete n;
                    return node;

                }
                else if(!(n->right)) // only left subtree exist
                {
                    Node* node = n->left;
                    delete n;
                    return node;
                }
                else{   // both subtrees exist
                    int min = getMin(n->right)->val;
                    n->val = min;
                    n->right = remove(min, n->right);
                    
                }
            }

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
        BSTree():root(NULL), size(0),insertSuccess(false){};
        BSTree(int val):root(new Node(val) ), size(1) {};
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

        void remove(int val)
        {
            root = remove(val, root);
        }

};



int main()
{
    //Node n(3);
    //cout << n.val<< endl;

    BSTree t;
    t.insert(5);
    t.insert(3);
    t.insert(6);
    t.insert(7);
    t.insert(8);
    t.insert(9);
    cout << "tree size - " << t.getSize() << " and height is " << t.getHeight() << endl;
    t.preOrder();

    t.remove(5);
    cout << "after removing 5" << endl;

    t.preOrder(); 

    return 0;
}