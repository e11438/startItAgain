#include<iostream>
#include<vector>

using namespace std;

static int copy_count = 0;

class Dash{
    int len;
    public:
        Dash(int i): len(i) //parameterized constructor
        {

        }

        Dash(const Dash & d): len(d.len)  //copy constructor
        {
            copy_count++;
        }

};


int main()
{

    vector<Dash> d_vec;

    d_vec.push_back(Dash(1));
    d_vec.push_back(Dash(2));
    cout << "copy count " <<  copy_count << endl;
    return 0;
}