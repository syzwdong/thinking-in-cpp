#include <iostream>
using namespace std;

template<class T, size_t sz>
class Array{
    enum { size = sz };
    T data[size];
public:
    virtual ~Array() { }
    T& operator[](const size_t index){
        if(index < size)
            return data[index];
        throw "下标越界";
    }
    size_t length() const{
        return size;
    }
    class iterator;
	iterator begin() { return iterator(data); }
	iterator end() { return iterator(data + size); }
    class iterator{
        T* index;
    public:
        iterator(T* i) :index(i){ }
        T& operator*() const { return *index; }
        T* operator->() const { return &*index; }
        iterator& operator++()   
        {
            ++index; 
            return *this;
        }
        iterator operator++(int) 
        {
            iterator old = *this;
            ++index;
            return old;
        }
        bool operator!=(const iterator right) const
        {
            return index != right.index;
        }
        bool operator==(const iterator right) const
        {
            return index == right.index;
        }        
    };

};

int main()
{
    const size_t num = 5;
    Array<int, num> data;
    cout << "sizeof : " << sizeof(data) << endl;
    cout << "length : " << data.length() << endl;
    for(int i = 0; i < data.length(); i++){
        data[i] = i * 2;
    }
    Array<int, num>::iterator start = data.begin();
    while(start != data.end()){
        cout << *start << "  ";
        ++start;
    }
    cout << endl;

    return 0;
}