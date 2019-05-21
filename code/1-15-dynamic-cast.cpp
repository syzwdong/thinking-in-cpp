#include <iostream>
using namespace std;

class A{ public: virtual ~A(){ } };
class B:public A{ };
class C:public A{ };

int main()
{
    A *a = new B;

    B *b = dynamic_cast<B*>(a);
    C *c = dynamic_cast<C*>(a);

    cout << b << endl;
    cout << c << endl;
    
    return 0;
}