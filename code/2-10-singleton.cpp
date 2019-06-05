#include <iostream>
using namespace std;

class A{
    A(int x){ i = x; }
    A(const A&) = delete;
    A& operator=(const A&) = delete;
    int i;
    static A a;
public:
    static A& instance(){
        return a;
    }
    int get(){
        return i;
    }
    void set(int x){
        i = x;
    }
};

A A::a(0);

int main()
{
    A& a = A::instance();
    cout << a.get() << endl;
    a.set(7);
    cout << a.get() << endl;

    return 0;
}