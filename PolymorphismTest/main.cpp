#include <iostream>

using namespace std;


struct B {
    virtual void f() const {cout << "B::F" << endl;}
    void g() const {cout << "B::G"<< endl;}
};
struct D:B {
    void f() const {cout << "D::F"<< endl;}
    void g() {cout << "D::G"<< endl;}
};
struct DD:D {
    void f() {cout << "DD::F"<< endl;}
    void g() const {cout << "DD::G"<< endl;}
};
void call (const B &b) {
    b.f();
    b.g();
}
int main () {
    B b; 
    D d;
    DD dd;
    call (b);
    call (d);
    call (dd);
    b.f();
    b.g();
    d.f();
    d.g();
    dd.f();
    dd.g();
}