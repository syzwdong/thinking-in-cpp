#include <iterator>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> data;
    istream_iterator<int> begin(cin), end;
    copy(begin, end, back_inserter(data));
    //Ctrl + D 结束输入 (Linux)
    copy(data.begin(), data.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    return 0;
}