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
    //线性查找
    vector<int> data { 1, 1, 2, -1, 5};
    auto iter = find(data.begin(), data.end(), -1);
    if(iter != data.end())
        cout << *iter << endl;
    //=>-1

    iter = find_if(data.begin(), data.end(), [](int x){ return x > 2; });
     if(iter != data.end())
        cout << *iter << endl;
    //=>5

    iter = adjacent_find(data.begin(), data.end());
    if(iter != data.end())
        cout << *iter << endl;
    //=>1

    iter = adjacent_find(data.begin(), data.end(), [](int x, int y){ return x+y > 3; });
    if(iter != data.end())
        cout << *iter << endl;
    //=>-1

    vector<string> str1 { "eee", "bcd" };
    vector<string> str2 { "bcd", "cde" };
    auto iter2 = find_first_of(str1.begin(), str1.end(), str2.begin(), str2.end());
    if(iter2 != str1.end())
        cout << *iter2 << endl;
    //=>bcd

    iter2 = find_first_of(str1.begin(), str1.end(), str2.begin(), str2.end(), 
                              [](string x, string y){ return x > y; });
    if(iter2 != str1.end())
        cout << *iter2 << endl;
    //=>eee

    //search find_end 查找序列2是否在序列1中出现

    iter2 = search(str1.begin(), str1.end(), str2.begin(), str2.begin());
    if(iter2 != str1.end())
        cout << *iter2 << endl;
    //=>eee

    iter2 = search(str1.begin(), str1.end(), str2.begin(), str2.begin()+1);
    if(iter2 != str1.end())
        cout << *iter2 << endl;
    //=>bcd

    iter2 = search(str1.begin(), str1.end(), str2.begin(), str2.end());
    if(iter2 != str1.end())
        cout << *iter2 << endl;
    //null

    iter2 = find_end(str1.begin(), str1.end(), str2.begin(), str2.begin()+1);
    if(iter2 != str1.end())
        cout << *iter2 << endl;
    //=>bcd

    vector<bool> b{ 0, 1, 1, 0, 0, 0};
    auto iter3 = search_n(b.begin(), b.end(), 2, true);
    if(iter3 != b.end())
        cout << *iter3 << endl;//=>1
    iter3 = search_n(b.begin(), b.end(), 3, false);
    if(iter3 != b.end())
        cout << *iter3 << endl;//=>0
    
    string s("defabc");
    auto iter4 = min_element(s.begin(), s.end());
    cout << *iter4 << endl;//=>a
    iter4 = max_element(s.begin(), s.end());
    cout << *iter4 << endl;//=>f

    return 0;
}