#include <iostream>
using namespace std;

class A{
    static int i;
    int x;
    const static int n = 10; 
public:
    A(int x) :x(x) { cout << "A::构造函数 --- " << x << endl; }
    ~A() { cout << "A::析构函数 --- " << x << endl; }
};

int A::i = 1;

static A a1(1);

void f(){ static A a2(2); }
void g(){ static A a3(3); }

int main()
{
    static A a4(4);
    g();
    f();
    return 0;
}