#include <iostream>
using namespace std;

class A{ };

class B1:virtual public A{
public:
    void f(){ cout << "B1::f()" << endl; }
};

class B2:virtual public A{
public:
    void f(){ cout << "B2::f()" << endl; }
};

class C:public B1, public B2{ };

class D:public B1, public B2{ 
public:
    using B1::f;
};

int main()
{
    C c;
    //c.f();
    //"C::f" is ambiguous

    D d;
    d.f();

    return 0;
}