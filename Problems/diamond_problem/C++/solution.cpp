// Solución: Usar herencia virtual para compartir una única instancia de la clase base.

#include <iostream>
using namespace std;

// Clase base
class A {
    public:
        void print() { cout << "A" << endl; }
    };

class B : virtual public A {};  // (uso de virtual)
class C : virtual public A {};

class D : public B, public C {}; // Ahora solo hay una copia de A

int main() {
    D d;
    d.print(); // Correcto: "A"
    return 0;
}