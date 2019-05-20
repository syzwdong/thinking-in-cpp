class X{
public:
    X(){}
};

//去掉goto与case的注释将报错

void f(int i){
    if(i < 10){
        //goto jump1;
    }
    X x1;
jump1:
    switch (i)
    {
    case 1:
       // X x2;
        break;
    default:
        break;
    }
}
int main()
{
    f(9);
    f(11);
    return 0;
}