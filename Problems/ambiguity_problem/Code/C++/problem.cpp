#include <iostream>
using namespace std;

class Animal {
public:
    void accion() {
        cout << "miau, miau, miau" << endl;
    }
};

class Herramienta {
public:
    void accion() {
        cout << "levantando vehiculo...." << endl;
    }
};

class Gato : public Animal, public Herramienta {};

int main() {
    Gato mi_gato;
    mi_gato.accion();  // Error de compilación: ambigüedad
    return 0;
}