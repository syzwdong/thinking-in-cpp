#include <iostream>
using namespace std;

class A{
    int i;
public:
    A(int i = 0){
        this->i = i;
        cout << i << endl;
    }
};
union U{
private:
    int i;
    float f;
public:
    U(int a){ i = a; }
    U(float b){ f = b; }
    ~U(){}
    int get_int(){ return i; }
    float get_float(){ return f; }
};

void f(int i = 0);
void g(int a, int = 0, int = 0);

void f(int i){ cout << i << endl; }
void g(int a, int, int b){
    cout << a << " " << b << endl;
}

int main()
{
    //使用默认参数，重载构造函数
    A a[2] = { A(), A(5) };
    U u[2] = { U(1), U(0.5f) };
    cout << u[0].get_int() << " " << u[1].get_float() << endl;
 
    //函数声明与定义
    //占位符参数
    f();
    g(1);
    g(2,1,1);
    return 0;
}