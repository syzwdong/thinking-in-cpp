#include <iostream>
#include <exception>
using namespace std;

int f(int n) try{
    if(n < 0)
        throw exception();
    return 0;
}catch(exception& e){
    cout<< "捕获异常" << endl;
    return -1;
}

int main(){
    cout << f(0) << endl;
    cout << f(-1) << endl;

    cout << " --- end main --- " << endl;
    return 0;
}