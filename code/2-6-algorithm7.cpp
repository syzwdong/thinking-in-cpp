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
    vector<int> data { 1, 1, -1, 0, 1, 2};
    auto iter = remove(data.begin(), data.end(), -1);
    print(data);
    //=>1 1 0 1 2 2
    data.erase(iter);
    print(data);
    //=>1 1 0 1 2

    data.erase(unique(data.begin(), data.end()), data.end());
    print(data);
    //=>1 0 1 2 

    sort(data.begin(), data.end());
    data.erase(unique(data.begin(), data.end()), data.end());
    print(data);
    //=>0 1 2  
    
    return 0;
}