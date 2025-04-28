class Persona:
    def __init__(self, nombre):
        self.nombre = nombre

    def __str__(self):
        return self.nombre
    
class RecibirClase:
    def __init__(self, horas_clase_alumno):
        self.horas_clase_alumno = horas_clase_alumno
        
    def RecibirClase(self):
        print(f"{self.nombre} recibe clases durante {self.horas_clase_alumno} horas.")
      
        
class ImpartirClase:
    def __init__(self, horas_clase_profesor):
        self.horas_clase_profesor = horas_clase_profesor
        
    def ImpartirClase(self):
        print(f"{self.nombre} imparte clases durante {self.horas_clase_profesor} horas.")
        
class CobrarSalario:
    def __init__(self, salario):
        self.salario = salario
        
    def CobrarSalario(self):
        print(f"{self.nombre} cobra salario como trabajador: {self.salario}")
    





class Estudiante(Persona, RecibirClase):
    def __init__(self, nombre, horas_clase_alumno, estipendio):
        RecibirClase.__init__(self, horas_clase_alumno)
        Persona.__init__(self, nombre)
        self.estipendio = estipendio

    def CobrarEstipendio(self):
        print(f"{self.nombre} cobra salario como estudiante: {self.estipendio}")
        
        
class Trabajador(Persona, CobrarSalario): 
    def __init__(self, nombre, salario):
        Persona.__init__(self, nombre)
        CobrarSalario.__init__(self, salario)


class Profesor(Trabajador, ImpartirClase):
    def __init__(self, nombre, horas_clase_profesor, salario):
        Trabajador.__init__(self, nombre, salario)
        ImpartirClase.__init__(self, horas_clase_profesor)


class AlumnoAyudante(Estudiante, ImpartirClase, CobrarSalario):
    def __init__(self, nombre, horas_clase_alumno, horas_clase_profesor, estipendio, salario):
        Estudiante.__init__(self, nombre, horas_clase_alumno,estipendio)
        ImpartirClase.__init__(self, horas_clase_profesor)
        CobrarSalario.__init__(self, salario) 


class ProfesorAdiestrado(Profesor, RecibirClase):
    def __init__(self, nombre, horas_clase_profesor, horas_clase_alumno, salario):
        Profesor.__init__(self, nombre, horas_clase_profesor, salario)
        RecibirClase.__init__(self, horas_clase_alumno)
    
        
persona = Persona("Juan")
estudiante = Estudiante("Maria", horas_clase_alumno=20, estipendio=500)
trabajador = Trabajador("Pedro", salario=1000)
profesor = Profesor("Ana", horas_clase_profesor=30, salario=1500)
alumno_ayudante = AlumnoAyudante("Carlos", horas_clase_alumno=15, horas_clase_profesor=10, salario=1200, estipendio=300)
profesor_adiestrado = ProfesorAdiestrado("Laura", horas_clase_profesor=25, horas_clase_alumno=5, salario=1300)

estudiante.RecibirClase()
estudiante.CobrarEstipendio()
trabajador.CobrarSalario()
profesor.ImpartirClase()
alumno_ayudante.CobrarSalario()
profesor_adiestrado.ImpartirClase()
profesor_adiestrado.CobrarSalario()
