#include <iostream>
using namespace std;

#define TRACE(ARG) cout << #ARG << endl; ARG
#define D(a) cout << #a "=[" << a << "]" << endl;

int main()
{
    int a = 1, b = 2;
    TRACE(
        if(a < b) cout << a << endl;
        else cout << b << endl;
    )
    
    D(a+b);

    cout << " --- end main --- " << endl;
    return 0;
}