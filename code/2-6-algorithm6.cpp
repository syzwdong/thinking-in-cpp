#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> a{ 1, 2, 3, 4};
    vector<int> b{ 0, 1, 2, 3};
    cout << equal(a.begin(), a.end(), b.begin()) << endl;
    //=>0
    cout << equal(a.begin(), a.end() - 1, b.begin() + 1) << endl;
    //=>1

    string s1("abcd");
    string s2("abce");
    cout << lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end()) << endl;
    //=>1
    cout << lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end() -1) << endl;
    //=>0
    
    vector<int> c{ 1, 2, 3};
    vector<int> d{ 1, 3, 4 };
    auto iter_pair = mismatch(c.begin(), c.end(), d.begin());
    if(iter_pair.first != c.end() && iter_pair.second != d.end())
        cout << *iter_pair.first << " " << *iter_pair.second << endl;
    //=>2 3

    return 0;
}