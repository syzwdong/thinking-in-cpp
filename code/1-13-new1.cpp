#include <cstdio>
#include <cstdlib>

void* operator new(size_t sz){
    printf("operator new \n");
    void* m = malloc(sz);
    return m;
}

void operator delete(void *m){
    printf("operator delete \n");
    free(m);
}

class A{
public:
    A() { printf("A::构造函数\n"); }
    ~A() { printf("A::析构函数\n"); }
};

int main()
{
    // int *pi = new int;
    A * pa = new A;
    // delete pi;
    delete pa;
    return 0;
}