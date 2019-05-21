#include <iostream>
using namespace std;

class A{
    public: virtual void f() { cout << "A::f()" << endl; }
};

class B:public A{
    public: void f(){ cout << "B::f()" << endl; }
};

void f(A& a) { a.f(); }

int main()
{
    A a;
    B b;
    f(a);
    f(b);
    return 0;
}