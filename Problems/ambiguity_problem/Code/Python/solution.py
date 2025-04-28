# Solution: Implementar metodo manualmente y escoger cual de los comportamientos se desea

class Animal:
    def accion(self):
        print("miau, miau, miau")

class Herramienta:
    def accion(self):
        print("levantando vehiculo....")

class Gato(Animal, Herramienta):
    def accion(self):
        # Elige ejecutar Herramienta.accion() aunque herede primero de Animal
        Herramienta.accion(self)

mi_gato = Gato()
mi_gato.accion()  # Salida: "levantando vehiculo...."