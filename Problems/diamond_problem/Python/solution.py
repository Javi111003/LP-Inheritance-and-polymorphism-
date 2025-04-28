""" Python resuelve el problema con el MRO (Method Resolution Order), que define un orden lineal para buscar métodos. 
Si dos clases padres tienen un método en común, se usa el de la primera clase en la lista de herencia."""

class A:
    def print(self):
        print("A")

class B(A):
    def print(self):
        print("B")

class C(A):
    def print(self):
        print("C")

class D(B, C):  # Hereda primero de B, luego de C (cambiar orden para notar el cambio)
    pass

d = D()
d.print()  # Salida: "B" (porque B está primero en el MRO) 