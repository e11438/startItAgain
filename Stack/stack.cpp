#include <iostream>

using namespace std;

class Stack
{
    private:
    class Node 
    {
        public:
         int val;
         Node * next;

         Node(int v):val(v),next(NULL){}

    };

    Node* head;
    int size;

    public:
        Stack():size(0), head(NULL){}
        void push(int val)
        {
            if(!head)
            {
                head = new Node(val);
            }
            else{
                Node * newNode = new Node(val);
                newNode->next = head;
                head = newNode;
            }
            size++;
        }

        int top()
        {
            if(!head)   return -1;
            else return head->val;
        }

        int pop()
        {
            if(!head)   return -1;

            Node *tmp = head;
            head = tmp->next;
            size--;
            return tmp->val;
        }

        int getSize()
        {
            return size;
        }



};

int main()
{

    Stack s;

    s.push(4);
    s.push(1);
    s.push(6);
    s.push(3);
    s.push(4);
    s.push(9);
    s.push(7);

    while(s.getSize())
        cout << s.pop() << " ";
    cout << endl;

    return 0;
}