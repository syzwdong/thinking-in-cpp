#include <iostream>
using namespace std;

class A{
public:
    int x;
    int y;
    void f(int z) const
    {
        A * t = (A *)this;
        t->x = z;
        t->y = z;
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
    a.f(1);
    b.f(2);
    cout << a.x << " " << a.y << endl;
    cout << b.x << " " << b.y << endl;
    return 0;
}