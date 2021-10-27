#include<iostream>
#include<vector>

using namespace std;

static int copy_count = 0;


class Check{
    public:
        float x;

        Check(float in):x(in)   //parameterized constructor
        {

        }

        Check( const Check & ch):x(ch.x)    //copy constructor
        {
            copy_count++;
        }
};

int main()
{

    vector<Check> ch_vec;

    ch_vec.reserve(3);

    ch_vec.push_back(Check(1));
    ch_vec.emplace_back(2);
    ch_vec.push_back(Check(3));

    
    for(Check ch : ch_vec)
    {
        cout << ch.x << endl;
    }  

    cout << "copy count " <<  copy_count << endl;

    return 0;
}