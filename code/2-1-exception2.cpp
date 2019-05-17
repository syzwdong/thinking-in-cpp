#include <iostream>
using namespace std;

class E{};
class A:public E{};
class B:public E{};

int main()
{
    try{
        throw B();
    }catch(E& e){
        cout << "E" << endl;
    }catch(A& a){
        cout << "A" << endl;
    }catch(B& b){
        cout << "B" << endl;
    }

    try{
        throw B();
    }catch(E e){
        cout << "E" << endl;
    }catch(A a){
        cout << "A" << endl;
    }catch(B b){
        cout << "B" << endl;
    }

    //均输出E
    
    cout << " --- end main --- " << endl;
    return 0;
}