#include <iostream>
using namespace std;

class ProxyBase{
    public:
    virtual void f() = 0;
    virtual void g() = 0;
    virtual void h() = 0;
};

class Implementation : public ProxyBase{
    public:
    void f() { cout << "Implementation.f()" << endl; }
    void g() { cout << "Implementation.g()" << endl; }
    void h() { cout << "Implementation.h()" << endl; }
};

class Proxy : public ProxyBase{
    ProxyBase* implementation;
    public:
    Proxy(){ implementation = new Implementation; }
    ~Proxy(){ delete implementation; }
    void f(){ implementation->f(); }
    void g(){ implementation->g(); }
    void h(){ implementation->h(); }
};

int main()
{
    Proxy p;
    p.f();
    p.g();
    p.h();
    
    return 0;
}