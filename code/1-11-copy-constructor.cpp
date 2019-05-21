#include <iostream>
using namespace std;

class A{
public:
    static int count;
    A(){
        count++;
        cout << "A::构造函数  ";
        print();
    }
    A(const A&){
        count++;
        cout << "A::拷贝构造  ";
        print();
    }
    ~A(){ 
        count--;
        cout << "A::析构函数  ";
        print();
    }
    static void print(){ cout << "count = " << count << endl; }
};

int A::count = 0;

A f(A a){
    return a;
}

int main()
{
    A a1;
    A a3 = f(a1);
    return 0;
}