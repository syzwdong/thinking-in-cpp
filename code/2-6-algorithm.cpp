#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

template<typename T>
void print(vector<T>& data){
    for(auto x: data){
        cout << x << " ";
    }
    cout << endl;
}

bool less3(int x){
    return x < 3;
}

int main()
{
    vector<int> data{1, 2, 3, 4, 5};
    print(data);
    //=>1 2 3 4 5

    vector<int> data2(5);
    //确保data2有足够的空间保存data
    copy(data.begin(), data.end(), data2.begin());
    print(data2);
    //=>1 2 3 4 5

    vector<int> data3;
    //以插入方式替代元素，自动扩大容量
    copy(data.begin(), data.end(), back_inserter(data3));
    print(data3);
    //=>1 2 3 4 5

    vector<int>data4;
    //less3(x)为真，则忽略x
    remove_copy_if(data.begin(), data.end(), back_inserter(data4), less3);
    print(data4);
    //=>3 4 5

    vector<int>data5;
    //less3(x)为真，则用默认值-1替代
    replace_copy_if(data.begin(), data.end(), back_inserter(data5), less3, -1);
    print(data5);
    //=>-1 -1 3 4 5

    //在原始序列中改变内容
    replace_if(data.begin(), data.end(), less3, -1);
    print(data);
    //=>-1 -1 3 4 5

    //流迭代器打印
    copy(data.begin(), data.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    //=>-1 -1 3 4 5

    return 0;
}