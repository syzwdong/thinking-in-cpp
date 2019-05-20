class A{
    int x;
public:
    A(int i){ x = i; }
};

A f(int i = 0) { return A(i); }
int g(int i = 0) { return i; }
int main()
{
    f() = A(5); 
    //g() = g(5); 按值返回内建类型不能成为左值
    return 0;
} 