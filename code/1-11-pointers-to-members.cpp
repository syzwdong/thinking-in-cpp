#include <iostream>
using namespace std;

class A{
public:
    int x;
    A(){ x = 0; }
    void f(){ x++; }
    void g(){ x--; }
};

int main()
{
    //指向成员的指针
    A a, *pa = &a;
    int A::*px = &A::x;
    pa->*px = 1;
    cout << a.x << endl;
    void (A::*pf) () = &A::f;
    (a.*pf)(); 
    cout << a.x << endl;
    pf = &A::g;
    (pa->*pf)();
    cout << a.x << endl;

    return 0;
}