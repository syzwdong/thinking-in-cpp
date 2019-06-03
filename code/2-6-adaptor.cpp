#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>
#include <cmath>
#include <string>
using namespace std;

bool isEven(int x){
    return x % 2 == 0;
}

int main()
{
    vector<int> data { 4, 17, 16, 3, 9, 36 };
    transform(data.begin(), data.end(), ostream_iterator<int>(cout, " "), bind2nd(plus<int>(),10));
    //=>14 27 26 13 19 46 
    cout << endl;

    cout << count_if(data.begin(), data.end(), bind1st(greater<int>(),20)) << endl;
    //=>5

    cout << count_if(data.begin(), data.end(), not1(bind2nd(equal_to<int>(), 17))) << endl;
    //=>5

    transform(data.begin(), data.end(), ostream_iterator<int>(cout, " "), ptr_fun(isEven));
    //=>1 0 1 0 0 1 
    cout << endl;

    transform(data.begin(), data.end(), ostream_iterator<int>(cout, " "), bind2nd(ptr_fun<double, int, double>(pow), 2));
    //=>16 289 256 9 81 1296 
    cout << endl;

    vector<string> str { "abc", "123", "hello" };
    transform(str.begin(), str.end(), ostream_iterator<int>(cout, " "), mem_fun_ref(&string::size));
    //=>3 3 5
    cout << endl;

    vector<string *> str2 { new string("abc"), new string("123"), new string("hello") };
    transform(str2.begin(), str2.end(), ostream_iterator<int>(cout, " "), mem_fun(&string::size));
    //=>3 3 5
    cout << endl;  

    return 0;
}