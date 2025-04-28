class Animal:
    def accion(self):
        print("miau, miau, miau")

class Herramienta:
    def accion(self):
        print("levantando vehiculo....")

class Gato(Animal, Herramienta): # (cambiar orden para observar el cambio)
    pass

mi_gato = Gato()
mi_gato.accion()  # Siempre ejecuta Animal.accion() por el orden de herencia