#include <algorithm>
#include <iostream>
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
    vector<int> data {14,5,13,26,4,18,47,26};

    //创建小顶堆
    make_heap(data.begin(), data.end(), greater<>());
    print(data);
    //=>4 5 13 26 14 18 47 26 

    //创建大顶堆
    make_heap(data.begin(), data.end());
    print(data);
    //=>47 26 18 26 14 4 13 5 

    //添加
    data.push_back(37);
    push_heap(data.begin(), data.end());
    print(data);
    //=>47 37 18 26 14 4 13 5 26

    //删除
    pop_heap(begin(data), end(data));
    data.pop_back();
    print(data);
    //=>37 26 18 26 14 4 13 5

    //判断是否依旧为堆
    cout << is_heap(begin(data), end(data)) << endl;
    //=>1

    //排序
    if(is_heap(begin(data), end(data)))
        sort_heap(begin(data), end(data));
    print(data);
    //=>4 5 13 14 18 26 26 37
    
    return 0;
}