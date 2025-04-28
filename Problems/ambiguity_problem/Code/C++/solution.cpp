// Solution: Especificar explicitamente que comportamiento se desea

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
    mi_gato.Herramienta::accion();  // Salida: "levantando vehiculo...."
    mi_gato.Animal::accion();       // Salida: "miau miau miau"
    return 0;
}