class A{ };
class B{ };
class E; //声明E
class C{
public:
    C(){ }
    C(const A&){ }
    explicit C(const B&){ }
    C(E);
};
class D{
public:
    D(){}
    D(const A&){}
    operator C(){ return C(); }
};

class E{
public:
    E(){ }
    operator C(){ return C(); }
};

void f(C){ }
void g(C){ }
void g(D){ }

int main()
{
    //自动类型转换

    A a;
    B b;
    f(a); //构造函数转换
    // f(b); error
    f(C(b));
    D d;
    f(d); //运算符转换
    E e;
    // f(e); 二义性
    // g(a);扇出 fan-out

    return 0;
}