#include <iostream>
using namespace std;

class A{
public:
    int x;
    A(int a):x(a){ }
};

class B{
public:
    int y;
    B(int b):y(b){ }
};

class C:public A, public B{
public:
    int z;
    C(int a, int b, int c):A(a), B(b), z(c){ }
};

int main()
{
    C c(1, 2, 3);
    cout << "sizeof A B C : ";
    cout << sizeof(A) << " " << sizeof(B) << " " << sizeof(C) << " " << endl;
    cout << "x y z : ";
    cout << c.x << " " << c.y << " " << c.z << endl;
    cout << "&x &y &z : ";
    cout << &c.x << " " << &c.y << " " << &c.z << endl;
    cout << "&c : ";
    cout << &c << endl;
    A *ap = &c;
    B *bp = &c;
    cout << "ap : ";
    cout << ap << endl;
    cout << "bp : ";
    cout << bp << endl;   
    C *cp1 = static_cast<C*>(ap);
    C *cp2 = static_cast<C*>(bp);
    cout << "cp : ";
    cout << cp1 << " " << cp2 << endl;

    return 0;
}