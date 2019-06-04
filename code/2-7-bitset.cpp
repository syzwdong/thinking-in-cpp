#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    //64位PC
    cout << sizeof(unsigned long) << " ";
    cout << sizeof(bitset<1>) << " ";
    cout << sizeof(bitset<63>) << " ";
    cout << sizeof(bitset<64>) << " ";
    cout << sizeof(bitset<65>) << endl;
    //=>8 8 8 16

    bitset<20> bs(65535);
    cout << bs << endl;
    //=>00001111111111111111
    unsigned long l = bs.to_ulong();
    cout << l << endl;
    //=>65535

    bitset<6> bs2("1001");
    cout << bs2 << " " << bs2.to_ulong() << endl;
    //=>001001 9

    bitset<6> bs3("110");
    cout << (bs2 & bs3) << endl;//=>000000
    cout << (bs2 | bs3) << endl;//=>001111
    cout << (bs2 ^ bs3) << endl;//=>001111

    cout << bs3.set(0).set(5) << endl;//=>100111
    cout << bs3.reset() << endl;//=>000000
    cout << bs3.flip() << endl;//=>111111

    return 0;
}