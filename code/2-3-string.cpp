#include <iostream>
#include <string>
using namespace std;


int main()
{
    string s1;
    string s2("hello,");
    string s3(s2);
    string s4;
    s4 = " world.";
    string s5 = s4.substr();
    string s6 = s3 + s5;
    cout << s6 << endl;

    cout << "index : " << s6.find("world") << endl;

    for(auto start = s6.begin(); start != s6.end(); start++){
        if(islower(*start))
            *start = toupper(*start);
    }
    cout << s6 << endl;

    cout << "size : " << s6.size() << endl;

    s6.replace(s6.find(","), 1, " :");
    cout << s6 << endl;

    s2.insert(s2.size(), s4);
    cout << s2 << endl;

    s2.erase(0, 7);
    cout << s2 << endl;

    return 0;
}