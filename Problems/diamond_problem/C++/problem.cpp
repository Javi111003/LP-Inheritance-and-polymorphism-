// En C++, se crean dos instancias de la clase base, causando ambigüedad.

#include <iostream>
using namespace std;

// Clase base
class A {
public:
    void print() { cout << "A" << endl; }
};

// Clases derivadas SIN herencia virtual (problema)
class B : public A {};
class C : public A {};

// Clase que hereda de B y C (dos copias de A)
class D : public B, public C {};

int main() {
    D d;
    // d.print(); // Error: ambigüedad (¿A de B o A de C?) (descomentar para ver)
    d.B::print(); // A
    d.C::print(); // A
    return 0;
}