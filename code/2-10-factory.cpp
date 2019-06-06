#include <iostream>
using namespace std;

class Shape{
public:
    virtual void f() = 0;
    static Shape* factory(const string& type);
};

class Circle : public Shape{
    Circle(){ }
    friend class Shape;
public:
    void f(){ cout << "circle" << endl; }
};

class Square : public Shape{
    Square(){ }
    friend class Shape;
public:
    void f(){ cout << "square" << endl; }
};

Shape* Shape::factory(const string& type)
{  
    if(type == "Circle")
        return new Circle;
    if(type == "Square")
        return new Square;
    return nullptr;
}

int main()
{
    Shape *s1 = Shape::factory("Circle"), *s2 = Shape::factory("Square");
    if(s1 != nullptr)
        s1->f();
    if(s2 != nullptr)
        s2->f();

    delete s1;
    delete s2;

    return 0;
}