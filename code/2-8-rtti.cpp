#include <iostream>
#include <typeinfo>
using namespace std;

class A{
public:
    virtual ~A(){ }
    virtual void f(){ cout << "A::f()" << endl; };
};

class B: public A{
public:
    ~B(){ }
    void f(){ cout << "B::f()" << endl; };
};


int main()
{
    A *a = new A;
    A *b = new B;
    //多态
    a->f();
    b->f();
    B *c = dynamic_cast<B*>(b);
    cout << c << endl;
    B *d = dynamic_cast<B*>(a);
    cout << d << endl;
    //=>0

    cout << typeid(a).name() << endl;//=>P1A
    cout << typeid(b).name() << endl;//=>P1A
    cout << typeid(*a).name() << endl;//=>1A
    cout << typeid(*b).name() << endl;//=>1B

    delete a;
    delete b;

    return 0;
}