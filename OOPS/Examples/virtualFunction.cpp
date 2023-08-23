#include<bits/stdc++.h>

using namespace std;

class Base {

    public:

    virtual void display() {
        cout<<"Base Class"<<endl;
    }

};

class Child: public Base {

    public:

    //  Method Overriding => Run-time polymorphism
    void display() {
        cout<<"Child Class"<<endl;
    }

};

class Shape {

    public:

    //  pure virtual function / "do-nothing" function => acts as a placeholder
    virtual void display() = 0;

};

class Circle: public Shape {

    public:

    //  Implements its own version of the function display
    void display() {
        cout<<"Circle IS-A Shape"<<endl;
    }

};

int main() {

    Base base1;
    Child child1;
    
    // Calling their respective methods
    base1.display();
    child1.display();

    Base *base2;
    base2 = &child1;

    base2->display();

    //  Using Scope Resolution Operator to access Base class's overriden function from child class instance
    child1.Base::display();     //  prints Base

    Circle c;
    c.display();

    return 0;
}