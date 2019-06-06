#include <iostream>
using namespace std;

class A{
    class Base{
    public:
        virtual string f() = 0;
    };
    class Sub1 : public Base{
    public:
        string f() { return string("sub1"); }
    };
    class Sub2 : public Base{
    public:
        string f() { return string("sub2"); }
    };
    Base* base;
public:
    A(){ base = new Sub1; }
    ~A(){ delete base; }
    void print() { cout << base->f() << endl; }
    void change(){
        delete base;
        base = new Sub2;
    }
};

int main()
{
    A a;
    a.print();
    a.change();
    a.print();
    
    return 0;
}