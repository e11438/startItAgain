#include<iostream>
#include<vector>

using namespace std;

class Check{
    public:
        float x;

        Check(float in):x(in)   //parameterized constructor
        {

        }

        Check( const Check & ch):x(ch.x)    //copy constructor
        {
            cout << "coping Check.." << endl;
        }
};

int main()
{

    vector<Check> ch_vec;

    ch_vec.reserve(2);

    ch_vec.push_back(Check(1));

    ch_vec.emplace_back(2);
    cout << "Done intserting "<< endl;
    for(Check ch : ch_vec)
    {
        cout << ch.x << endl;
    }  

    return 0;
}