#include <iostream>
#include <vector>
using namespace std;

class Command{
    public: virtual void execute() = 0;
};

class Hello : public Command{
    public: void execute(){ cout << "hello "; }
};

class World : public Command{
    public: void execute(){ cout << "world." << endl; }
};

class A{
    vector<Command*> commands;
public:
    void add(Command* c) { commands.push_back(c); }
    void run(){
        auto it = commands.begin();
        while(it != commands.end()){
            (*it++)->execute();
        }
    }
};

int main()
{
    A a;
    a.add(new Hello);
    a.add(new World);
    a.run();

    return 0;
}