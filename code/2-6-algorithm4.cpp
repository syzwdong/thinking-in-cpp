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
    vector<int> data(5);
    int i = 1;
    generate_n(data.begin(), 4, [&i](){ return i++; });
    print(data);
    //=>1 2 3 4 0
    vector<int> data_copy(data);
    copy(data_copy.begin(), data_copy.end() - 1, data_copy.begin() + 1);
    print(data_copy);
    //=>1 1 2 3 4
    //why not 1 1 1 1 1 ?

    copy_backward(data.begin(), data.end() - 1, data.end());
    print(data);
    //=>1 1 2 3 4

    //在原序列倒置
    reverse(data.begin(), data.end());
    print(data);
    //=>4 3 2 1 1

    //倒置到其他序列，原序列不变
    vector<int> data_reverse(5);
    reverse_copy(data.begin(), data.end(), data_reverse.begin());
    print(data);
    print(data_reverse);
    //=>4 3 2 1 1 
    //  1 1 2 3 4

    //交换
    vector<string> str1 { "abc", "bcd" };
    vector<string> str2 { "123", "234" };
    swap_ranges(str1.begin(), str1.end(), str2.begin());
    print(str1);//=>123 234
    print(str2);//=>abc bcd

    //在序列中交换元素
    //[first,mid) 与[mid, end)交换
    rotate(str1.begin(),str1.begin()+1, str1.end());
    print(str1);//=>234 123

    //原序列不变，生成在目的序列中
    rotate_copy(str1.begin(),str1.begin()+1, str1.end(), str2.begin());
    print(str1);//=>234 123
    print(str2);//=>123 234

    //排列
    string s("abc");
    cout << s << " ";
    while(next_permutation(s.begin(), s.end())){
        cout << s << " ";
    }
    cout << endl;
    //=>abc acb bac bca cab cba 
    string s2("caa");
    cout << s2 << " ";
    while(prev_permutation(s2.begin(), s2.end())){
        cout << s2 << " ";
    }
    cout << endl;
    //=>caa aca aac

    //随机排列
    string s3("abcd");
    for(int i = 0; i < 4; i++){
        random_shuffle(s3.begin(), s3.end());
        cout << s3 << " ";
    }
    cout << endl;
    //=>adbc adbc bcda bcda

    //划分
    vector<int> num { 10, 5, 7, 13, 6, 24, 5};
    vector<int> num_copy(num);
    auto iter = partition(num.begin(), num.end(), [](int x){ return x % 2 != 0; } );
    print(num);//=>5 5 7 13 6 24 10
    cout << *iter << endl;//=>6
    stable_partition(num_copy.begin(), num_copy.end(), [](int x){ return x % 2 != 0; } );
    print(num_copy);//=>5 7 13 5 10 6 24 

    return 0;
}