#include <iostream>
using namespace std;

class A{
    int i;
public:
    void f() { }
};

class B{
    int i;
public:
    virtual void f() { }
};

class C{
    int i;
public:
    virtual void f() { }
    virtual void g() { }
};

int main()
{
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;
    cout << sizeof(C) << endl;
    //有虚函数的类比没有虚函数的类多一个void* 的长度

    return 0;
}