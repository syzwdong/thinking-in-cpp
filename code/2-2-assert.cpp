#include <iostream>
#include <cassert>
using namespace std;

#define NDEBUG
#include <cassert>


int main()
{
    assert(1 >= 0);
    bool b = false;
    assert(b);

    cout << " --- end main --- " << endl;
    return 0;
}