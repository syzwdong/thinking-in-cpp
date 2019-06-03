#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int data[8] = {0, 1, 2, 3, 3, 4, 4, 5 };
    cout << count(data, data + 8, 3) << endl;
    //=>2
    cout << count_if(data, data + 8, [](int x){ return x < 3; }) << endl;
    //=>3

    return 0;
}