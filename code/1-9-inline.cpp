class A{
public:
    void f() const { g();}
    void g() const { }
};

int main()
{
    A a;
    a.f();
    return 0;
}