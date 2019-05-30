#include <iostream>
using namespace std;

class A{
public:
    static int count;
    A(){ count ++; }
};
int A::count = 0;
class B:public A{};
class C:public A{};

int main(){
    B b1;
    cout << B::count << endl;
    B b2;
    cout << B::count << endl;
    C c1;
    cout << C::count << endl;
}