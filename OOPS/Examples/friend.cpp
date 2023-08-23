#include<bits/stdc++.h>

using namespace std;


////////////////////////    FRIEND CLASS EXAMPLE     /////////////////////////////

class B;

class A {
    private:

    int x;

    public:

    A(): x(0) {}

    void set(int v) {
        x = v;
    }

    friend class B;
};

class B {

    public:

    void setAndDisplayA(A &a, int v) {
        cout<<"Value Before: "<<a.x<<endl;
        a.set(v);
        cout<<"Value After: "<<a.x<<endl;
    }

};

////////////////////////    FRIEND FUNCTION EXAMPLE     /////////////////////////////
class Fraction {

    private:

    int num;
    
    protected:

    int deno;

    public:

    //  Constructor
    Fraction(int n, int d) {
        num = n, deno = d;
    }

    //  Member Function - declared inside class & can access private properties
    void simpleMemberFunc() {
        cout<<"Fraction is : "<<num<<" / "<<deno<<endl;
    }

    // Friend declaration
    friend Fraction multByInteger(Fraction f, int x);

};

Fraction multByInteger(Fraction f, int x) {
    return Fraction(f.num * x, f.deno);
}

int main() {

    ////////////////////////    FRIEND CLASS EXAMPLE     /////////////////////////////

    A a;
    B b;

    b.setAndDisplayA(a, 10);
    b.setAndDisplayA(a, 20);

    ////////////////////////    FRIEND FUNCTION EXAMPLE     /////////////////////////////

    Fraction f1(1, 2);
    //  call member function
    f1.simpleMemberFunc();
    //  call friend function and see how we can call it independently like a plain old cpp function
    Fraction f2 = multByInteger(f1, 3);
    f2.simpleMemberFunc();
    return 0;
}