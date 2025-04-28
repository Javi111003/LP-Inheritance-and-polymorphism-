#include <iostream>
#include <string>
using namespace std;

class Persona {
protected:
    string nombre;

public:
    Persona(const string& nombre) : nombre(nombre) {}

    virtual string toString() const {
        return nombre;
    }
};

class Recibidor {
protected:
    int horas_clase_alumno;

public:
    Recibidor(int horas_clase_alumno) : horas_clase_alumno(horas_clase_alumno) {}

    void RecibidorFunc() const {
         cout << " recibe clases durante " << horas_clase_alumno << " horas." <<  endl;
    }
};

class Impartidor {
protected:
    int horas_clase_profesor;

public:
    Impartidor(int horas_clase_profesor) : horas_clase_profesor(horas_clase_profesor) {}

    void ImpartidorFunc() const {
         cout << " imparte clases durante " << horas_clase_profesor << " horas." <<  endl;
    }
};

class Plantilla {
protected:
    double salario;

public:
    Plantilla(double salario) : salario(salario) {}

    void CobrarSalario() const {
        cout << " cobra salario como trabajador: " << salario << endl;
    }
};

class Estudiante : public Persona, public Recibidor {
private:
    double estipendio;

public:
    Estudiante(const  string& nombre, int horas_clase_alumno, double estipendio)
        : Persona(nombre), Recibidor(horas_clase_alumno), estipendio(estipendio) {}

    void CobrarEstipendio() const {
         cout << nombre << " cobra salario como estudiante: " << estipendio <<  endl;
    }
};

class Trabajador : public Persona, public Plantilla {
public:
    Trabajador(const  string& nombre, double salario)
        : Persona(nombre), Plantilla(salario) {}
    
        void CobrarSalario() const {
            cout << nombre << " cobra salario como trabajador: " << salario <<  endl;
    }
};

class Profesor : public Trabajador, public Impartidor {
public:
    Profesor(const  string& nombre, int horas_clase_profesor, double salario)
        : Trabajador(nombre, salario), Impartidor(horas_clase_profesor) {}
};

class AlumnoAyudante : public Estudiante, public Impartidor, public Plantilla {
public:
    AlumnoAyudante(const  string& nombre, int horas_clase_alumno, int horas_clase_profesor, double estipendio, double salario)
        : Estudiante(nombre, horas_clase_alumno, estipendio), Impartidor(horas_clase_profesor), Plantilla(salario) {}
};

class ProfesorAdiestrado : public Profesor, public Recibidor {
public:
    ProfesorAdiestrado(const  string& nombre, int horas_clase_profesor, int horas_clase_alumno, double salario)
        : Profesor(nombre, horas_clase_profesor, salario), Recibidor(horas_clase_alumno) {}
};

int main() {
    Persona persona("Juan");
    Estudiante estudiante("Maria", 20, 500);
    Trabajador trabajador("Pedro", 1000);
    Profesor profesor("Ana", 30, 1500);
    AlumnoAyudante alumno_ayudante("Carlos", 15, 10, 300, 1200);
    ProfesorAdiestrado profesor_adiestrado("Laura", 25, 5, 1300);

    alumno_ayudante.Plantilla::CobrarSalario();
    estudiante.CobrarEstipendio();
    trabajador.CobrarSalario();
    profesor.ImpartidorFunc();
    alumno_ayudante.CobrarEstipendio();
    alumno_ayudante.CobrarSalario();
    profesor_adiestrado.ImpartidorFunc();
    profesor_adiestrado.CobrarSalario();
    profesor_adiestrado.RecibidorFunc();
    profesor_adiestrado.ImpartidorFunc();

    return 0;
}