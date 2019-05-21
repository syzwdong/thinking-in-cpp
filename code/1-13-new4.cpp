#include <iostream>
using namespace std;

class A{
public:
    int i;
    A(int ii = 0) :i(ii){
        cout << "A::构造函数---" << i << endl;
    }
    ~A(){
        cout << "A::析构函数---" << i << endl;
    }
    void* operator new(size_t, void* loc){
        cout << "A::new " << endl;
        return loc;
    }
};
int main()
{
    A a1(1);
    A *pa1 = &a1;
    A *pa = new(pa1) A(2);
    cout << a1.i << endl;

    //只析构了一次
    return 0;
}