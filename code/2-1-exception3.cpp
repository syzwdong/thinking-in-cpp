#include <iostream>
#include <exception>
using namespace std;

class A{
public:
    int *p;
    A(){
        try{
            p = new int;
            throw exception();
        }catch(...){
            delete p;
            throw;
        }
    }
    ~A(){ delete p; }
};

int main()
{
    try{
        A a;
    }catch(exception& e){
        cout << "捕获异常" << endl;
    }
    cout << " --- end main --- " << endl;
    return 0;
}