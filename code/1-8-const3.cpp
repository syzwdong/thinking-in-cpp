#include <iostream>
using namespace std;

class A{
public:
    int x;
    mutable int y;//y 可以在const成员函数中被修改
    void f(int z) const
    {
        y = z;
    }
    A() : x(0), y(0) {}
    A(int x, int y) : x(x), y(y){}

};
int main()
{

    const A a;
    cout << a.x << " " << a.y << endl;
    const A b(1,2);
    cout << b.x << " " << b.y << endl;
    a.f(10);
    b.f(10);
    cout << a.x << " " << a.y << endl;
    cout << b.x << " " << b.y << endl;
    return 0;
}