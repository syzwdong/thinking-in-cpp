#include <iostream>
#include <string>
#include <sstream>
using namespace std;

template<typename T>
T fromString(const string& s){
    istringstream is(s);
    T t;
    is >> t;
    return t;
}

template<typename T>
string toString(const T& t){
    ostringstream os;
    os << t;
    return os.str();
}

int main()
{
    string sf = "1.45";
    double f = fromString<double>(sf);
    cout << f << endl;

    int i = 987;
    string si = toString<int>(i);
    cout << si << endl;
    
    return 0;
}