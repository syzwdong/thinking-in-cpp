#include <iostream>
using namespace std;

class A { };
class B:public A { };

void f(A& a) { }

class Base{
public:
    int i;
    Base(int i):i(i) { }
    Base(const Base& b){ i = b.i; }
};

class Sub:public Base{
public:
    int x;
    Sub(int i, int x):x(x), Base(i) { }
    Sub(const Sub& s) :Base(s){ x = s.x; }//Base(s)将s向上转换为Base
};

int main()
{
    A a;
    B b;
    f(a);
    f(b);//向上类型转换

    Sub s1(1,5);
    Sub s2(s1);
    cout << s2.i << " " << s2.x << endl;
    
    return 0;
}