#include <iostream>
using namespace std;

class Error{
    public:
        Error(){
            cout << "构造函数" << endl;
        }
        Error(const Error& e){
            cout << "拷贝构造" << endl;
        }
        ~Error(){
            cout << "析构函数" << endl;
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

void f(){
    A a;
    throw Error();
}
int main(){
    try{
        f();
    }
    catch(Error e){
        cout << "捕获Error" << endl;
    }
    
    cout << " --- end main --- " << endl;
    return 0;
}