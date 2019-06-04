#include <iostream>
#include <vector>
#include <numeric>
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
    cout << accumulate(data.begin(), data.end(), 0)  << endl;
    //=>15
    cout << accumulate(data.begin(), data.end(), 0, [](int x, int y){ return x + y * y; })  << endl;
    //=>55

    //内积
    vector<int> data2(data);
    cout << inner_product(data.begin(), data.end(), data2.begin(), 0) << endl;
    //=>55
    //自定义op+ op*
    cout << inner_product(data.begin(), data.end(), data2.begin(), 0, 
            [](int x, int y){ return x + y;},
            [](int x, int y){ return x * y;}
            ) << endl;
    //=>55

    vector<int> data3(5);
    partial_sum(data.begin(), data.end(), data3.begin());
    print(data3);
    //=>1 3 6 10 15 
    partial_sum(data.begin(), data.end(), data3.begin(), multiplies<int>());
    print(data3);
    //=>1 2 6 24 120

    adjacent_difference(data.begin(), data.end(), data3.begin());
    print(data3);
    //=>1 1 1 1 1
    adjacent_difference(data.begin(), data.end(), data3.begin(), multiplies<int>());
    print(data3);
    //=>1 2 6 24 120

    return 0;
}