#include <cstdio>
#include <cstdlib>

void* operator new(size_t sz){
    printf("全局 new \n");
    void* m = malloc(sz);
    return m;
}

void operator delete(void *m){
    printf("全局 delete \n");
    free(m);
}

class A{
    int i;
public:
    A() { printf("A::构造函数\n"); }
    ~A() { printf("A::析构函数\n"); }
    void * operator new(size_t);
    void operator delete(void *);
    void* operator new[](size_t);
    void operator delete[](void *);
};

void* A::operator new(size_t sz){
    printf("A:: new \n");
    void* m = malloc(sz);
    return m;
}

void A::operator delete(void* m){
    printf("A:: delete \n");
    free(m);
}

void* A::operator new[](size_t sz){
    printf("A:: new []\n");
    void* m = malloc(sz);
    return m;    
}

void A::operator delete[](void *m){
    printf("A:: delete [] \n");
    free(m);
}

int main()
{
    A *pa = new A;
    delete pa;
    A *pas = new A[1];
    delete []pas;

    return 0;
}