#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;

template<typename T>
void print(list<T> l)
{
    cout << "list::size() : " << l.size()  << endl;
    copy(l.begin(), l.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main()
{
    list<int> l { 1, 1, 2, 5, 4, 4, 3 };
    l.sort();
    print(l);
    list<int> l2 { 0, 6 };
    l.merge(l2);
    print(l);
    print(l2);
    l.unique();
    print(l);
    l.reverse();
    print(l);
    l.remove_if([](int x){ return x > 3;});
    print(l);
    l.remove(0);
    print(l);

    return 0;
}

/****output*******
list::size() : 7
1 1 2 3 4 4 5 
list::size() : 9
0 1 1 2 3 4 4 5 6 
list::size() : 0

list::size() : 7
0 1 2 3 4 5 6 
list::size() : 7
6 5 4 3 2 1 0 
list::size() : 4
3 2 1 0 
list::size() : 3
3 2 1 
******************/