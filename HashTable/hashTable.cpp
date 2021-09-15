#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Node
{
    public:
    int val;
    Node * next;

    Node(int val):val(val), next(NULL) {}
};

class HashMap
{
    private:
        int contanerSize;
        vector<vector<int>> * const table;

    public:
        HashMap(int size):contanerSize(size), table(new vector<vector<int> > (size, vector<int>()) ){

        }

        void insert(int val)
        {
            int pos = val % contanerSize;
            (*table)[pos].push_back(val);
            //vector<int> vec = (*table)[pos];
            //vec.push_back();
        }

        bool find(int val)
        {
            int pos = val % contanerSize;
            vector<int> vec = (*table)[pos];
            return std::find(vec.begin(), vec.end(), val) != vec.end();
             
        }

        void print()
        {
            for(int i = 0; i < contanerSize; i++ )
            {
                vector<int> vec = (*table)[i];
                cout << i <<" => ";
                for(int d : vec)
                    cout << d<< " ";
                cout <<endl;
            }
        }

        
};

int main()
{
    HashMap h(20);
    h.insert(3);
    h.insert(23);
    h.insert(4);

    cout << h.find(2) << endl;
    cout << h.find(23) << endl;

    h.print();

    return 0;
}