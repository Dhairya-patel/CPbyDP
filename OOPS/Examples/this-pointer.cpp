#include<bits/stdc++.h>

using namespace std;

class Box {

    public:

    //  Non-static member functions have 'this' pointer as their implicit parameter
    Box(double length, double breadth, double height) {
        this->length = length;
        this->breadth = breadth;
        this->height = height;
    }

    double volume() {
        return length * breadth * height;
    }

    //  Non-static member functions have 'this' pointer as their implicit parameter
    bool compare(Box box) {
        return this->volume() > box.volume();
    }

    private:

    double length, breadth, height;

};

int main() {

    Box b1(9, 2, 3);
    Box b2(2, 3, 4);

    if(b1.compare(b2))
        cout<<"Box1 larger than box2"<<endl;
    else
        cout<<"Box2 larger or equal to box1"<<endl;

    return 0;
}