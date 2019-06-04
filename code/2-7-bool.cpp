#include <vector>
#include <iostream>
using namespace std;

void print(vector<bool> vb)
{
    for(auto x:vb)
    {
        cout << x;
    }
    cout << endl;
}

int main()
{
    vector<bool> vb(10,true);
    print(vb);
    //=>1111111111
    vb.push_back(false);
    print(vb);
    //=>11111111110
    vb.flip();
    print(vb);
    //=>00000000001
    vb[3] = 1;
    print(vb);
    //=>00010000001

    return 0;
}