#include <iostream>
#include <vector>
#include <iterator>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
    pair<string,int> a = make_pair(string("Hello"), 12);
    cout << a.first << " " << a.second << endl;
    //=>Hello 12

    vector<int> b(10);
    list<int> c(15);
    cout << distance(b.end(), b.begin()) << endl; //=>-10
    cout << distance(c.begin(), c.end()) << endl; //=>15

    vector<int> d { 1, 2, 3 };
    list<int> e;
    copy(d.begin(),d.end(), back_inserter(e));
    copy(e.begin(), e.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    //=>1 2 3
    copy(d.begin(),d.end(), front_inserter(e));
    copy(e.begin(), e.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    //=>3 2 1 1 2 3 
    auto iter = e.begin();
    advance(iter, 2);
    copy(d.begin(),d.end(), inserter(e, iter));
    copy(e.begin(), e.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    //=>3 2 1 2 3 1 1 2 3 

    string s1("abc"), s2("bc");
    cout << min(s1, s2, [](string x, string y){ return x.size() < y.size();}) << endl;
    //=>bc
    cout << max(s1, s2, [](string x, string y){ return x.at(0) < y.at(0);}) << endl;
    //=>bc

    swap(s1, s2);
    cout << s1 << " " << s2 << endl;
    //=>bc abc

    vector<int> data{ 0, 1};
    auto it1 = data.begin();
    auto it2 = data.begin() + 1;
    cout << distance(it1, it2) << endl;
    //=>1
    iter_swap(it1, it2);
    cout << *it1 << " " << *it2 << endl;
    //=>1 0
    cout << distance(it1, it2) << endl;
    //=>1
    
    return 0;
}