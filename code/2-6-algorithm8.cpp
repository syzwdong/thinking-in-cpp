#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

template<typename T>
void print(vector<T>& data){
    copy(data.begin(), data.end(), ostream_iterator<T>(cout, " "));
    cout << endl;
}

int main()
{
    vector<int> data(10);
    generate(data.begin(), data.end(), [](){ return rand() % 20; });
    print(data);
    //=>3 6 17 15 13 15 6 12 9 1
    vector<int> data_copy(data), data_copy2(data), data_copy3(data);
    sort(data.begin(), data.end());
    print(data);
    //=>1 3 6 6 9 12 13 15 15 17
    stable_sort(data_copy.begin(), data_copy.end());
    print(data_copy);
    //=>1 3 6 6 9 12 13 15 15 17

    partial_sort(data_copy2.begin(), data_copy2.begin() + 5, data_copy2.end());
    print(data_copy2);
    //=>1 3 6 6 9 17 15 15 13 12

    nth_element(data_copy3.begin(), data_copy3.begin() + 5, data_copy3.end());
    print(data_copy3);
    //=>6 3 1 6 9 12 13 15 15 17
    
    bool isfind = binary_search(data.begin(), data.end(), 10);
    cout << isfind << endl;
    //=>0

    auto iter = lower_bound(data.begin(), data.end(), 10);
    cout << *iter << endl;
    //=>12

    iter = upper_bound(data.begin(), data.end(), 10);
    cout << *iter << endl;
    //=>12

    auto pair_iter = equal_range(data.begin(), data.end(), 12);
    for(auto i = pair_iter.first; i != pair_iter.second; i++){
        cout << *i << endl;
    }
    //=>12

    int a[3] = { 1, 2, 3};
    int b[4] = { 0, 1, 3, 4};
    vector<int> array;
    merge(a, a + 3, b, b + 4, back_inserter(array));
    print(array);
    //=>0 1 1 2 3 3 4 

    rotate(array.begin(),array.begin()+4, array.end());
    print(array);
    //=>3 3 4 0 1 1 2 
    inplace_merge(array.begin(),array.begin()+3, array.end());
    print(array);
    //=>0 1 1 2 3 3 4 

    vector<int> array2 { 0, 1, 1 };
    cout << includes(array.begin(), array.end(), array2.begin(), array2.end()) << endl;
    //=>1

    vector<int> array3 { -2, -1, 0, 1, 1 };
    set_union(array.begin(), array.end(), array3.begin(), array3.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    //=>-2 -1 0 1 1 2 3 3 4

    set_intersection(array.begin(), array.end(), array3.begin(), array3.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    //=>0 1 1

    set_difference(array.begin(), array.end(), array3.begin(), array3.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    //=>2 3 3 4

    set_symmetric_difference(array.begin(), array.end(), array3.begin(), array3.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    //=>-2 -1 2 3 3 4

    return 0;
}