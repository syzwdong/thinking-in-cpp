#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template<typename T>
void print(vector<T>& data){
    for(auto x: data){
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> data { 1, 2, 3, 4, 5 };
    for_each(data.begin(), data.end(), [](int x){ cout << x << " ";});
    cout << endl;
    //=>1 2 3 4 5 
    for_each(data.begin(), data.end(), [](int x){ return 0;});
    print(data);
    //=>1 2 3 4 5

    vector<int> data2(5);
    transform(data.begin(), data.end(), data2.begin(), [](int x){ return x + 1; });
    print(data2);
    //=>2 3 4 5 6
    vector<int> data3(5);
    transform(data.begin(), data.end(), data2.begin(), data3.begin(), [](int x, int y){ return x * y; });
    print(data3);
    //=>2 6 12 20 30

    return 0;
}