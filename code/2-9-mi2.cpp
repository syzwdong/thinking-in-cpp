#include <iostream>
using namespace std;

class A{
public:
    int x;
    A(int a):x(a){ }
};

class B1:public A{
public:
    int y1;
    B1(int a, int b1):A(a), y1(b1){ }
};

class B2:public A{
public:
    int y2;
    B2(int a, int b2):A(a), y2(b2){ }
};

class C:public B1, public B2{
public:
    int z;
    C(int a, int b1, int b2, int c):B1(a, b1), B2(a, b2), z(c){ }
};

int main()
{
    cout << "sizeof(A) : " << sizeof(A) << endl;
    cout << "sizeof(B1) : " << sizeof(B1) << endl;
    cout << "sizeof(B2) : " << sizeof(B2) << endl;
    cout << "sizeof(C) : " << sizeof(C) << endl;

    C c(1, 2, 3, 4);
    //cout << "c.x : " << c.x << endl;
    //member ‘x’ is ambiguous
    cout << "c.y1 : " << c.y1 << endl;
    cout << "c.y2 : " << c.y2 << endl;
    cout << "c.z : " << c.z << endl;

    B1 *b1 = &c;
    B2 *b2 = &c;
    cout << "b1 : " << b1 << endl;
    cout << "b2 : " << b2 << endl;
    cout << "b1->x : " << b1->x << endl;
    cout << "b2->x : " << b2->x << endl;

    //A *a = &c;
    //base class "A" is ambiguous

    A *a1 = b1, *a2 = b2;
    cout << "a1->x : " << a1->x << endl;
    cout << "a2->x : " << a2->x << endl;

    return 0;
}