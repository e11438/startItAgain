#include <iostream>

using namespace std;

class LinkedList
{

    private:
        class Node 
        {
            public:
            const int val;
            Node *next;
            public:
            Node():val(0),next(NULL){}
            Node(int v):val(v),next(NULL){}

        };    
        unsigned int size;
        Node * head;

        Node* insert(int v, Node* n)
        {
            if(!n) 
            {
                n = new Node(v);
                size++;
            }
            else    n->next = insert(v, n->next);

            return n;
        }


    public:
        LinkedList():size(0), head(NULL){}
        LinkedList(int v):size(1),head(new Node(v)){}

        void insert(int v)
        {
            head = insert(v, head);
        }

        void remove(int val)
        {
            Node * tmp = head;
            Node * prev = NULL;
            while(tmp)
            {
                if(tmp->val == val)
                {
                    Node * nextNode = tmp->next;

                    if(prev) prev->next = nextNode;
                    else head = nextNode;

                    delete tmp;  
                    size--;         
                    tmp = nextNode;     
                }
                else{
                    prev = tmp;
                    tmp = tmp->next;
                }
                
            }
            cout << endl;

        }

        const int* at(int pos)
        {
            if(pos < 0) return NULL;
            if(pos >= size) return NULL;
            Node * tmp = head;
            const int * res = NULL;
            int count = 0;
            while(tmp)
            {
                if(count == pos)
                {
                    res = &(tmp->val);
                    break;
                }
                count ++;
                tmp = tmp->next;
            }
            return res;
        } 

        void print()
        {
            Node * tmp = head;
            while(tmp)
            {
                cout << tmp->val << " ";
                tmp = tmp->next;
            }
            cout << endl;
        }
};

int main()
{
    LinkedList l;

    l.insert(10);
    l.insert(2);
    l.insert(4);
    l.insert(5);
    l.insert(8);
    l.insert(2);
    l.insert(3);
    l.insert(1);

    l.print();

    int * check = (int *)l.at(2); //breaking the promise now element can be modified
    if(check)
    {
        cout << "Element at 2 "<<*check << endl;
        *check = 25;
        l.print();
    }


    l.remove(10);

    l.remove(4);
    
    l.remove(2);
    l.print();

    

    return 0;
}