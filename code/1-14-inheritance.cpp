#include <iostream>
using namespace std;

class Base{
public:
    int i;
    Base(int ii) :i(ii){
        cout << "Base::构造函数---" << i << endl;
    }
    ~Base(){
        cout << "Base::析构函数---" << i << endl;
    }
    void f(){
        cout << "Base::f()" << endl;
    }
    void f(int x){
        cout << "Base::f() (int) " << x << endl;
    }

};

class A{
public:
    A(){
        cout << "A::构造函数" << endl;
    }
    ~A(){
        cout << "A::析构函数" << endl;
    }

};

class Sub:public Base
{
public:
    int x;
    A a;
    Sub():x(0),a(),Base(0){
        cout  << "Sub::无参构造函数" << endl;
    }
    Sub(int x):x(x),Base(0),a(){
        cout  << "Sub::单参构造函数" << endl;
    }
    void f(){
        cout << "Sub::f()" << endl;
    }
    ~Sub(){
        cout << "Sub::析构函数---" << i << endl;
    }
};

int main()
{

    Sub s1;
    s1.f();
    // s.f(0); error 重定义基类中一个函数，其他重载版本被隐藏
    cout << "--------------" << endl;

    Sub s2(1);
    //Base 与 A 构造函数调用的顺序与初始化列表中出现顺序无关
    cout << "--------------" << endl;

    return 0;
}