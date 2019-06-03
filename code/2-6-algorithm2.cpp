#include <iostream>
#include <vector>
#include <algorithm>
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
    vector<int>data(10);
    //填充
    fill(data.begin(), data.end(), 7);
    print(data);
    //=>7 7 7 7 7 7 7 7 7 7
    //填充前n个
    fill_n(data.begin(), 5, 3);
    print(data);
    //=>3 3 3 3 3 7 7 7 7 7

    //生成
    generate(data.begin(), data.end(), [](){ return rand() % 10; } );
    print(data);
    //=>3 6 7 5 3 5 6 2 9 1 
    //生成前n个
    generate_n(data.begin()+2, 5, [](){ return -1;});
    print(data);
    //=>3 6 -1 -1 -1 -1 -1 2 9 1

    return 0;
}