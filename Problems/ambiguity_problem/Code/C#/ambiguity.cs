using System;
interface IAnimal
{
    void Action();
}

interface IHerramienta
{
    void Action();
}

class Gato : IAnimal, IHerramienta
{
    // Implementación explícita para evitar ambigüedad
    void IAnimal.Action()
    {
        Console.WriteLine("miau miau miau");
    }

    void IHerramienta.Action()
    {
        Console.WriteLine("Levantando vehiculo ...");
    }
}

class Program
{
    static void Main(string[] args)
    {
        Gato gato = new Gato();        
        // Para llamar a una implementación específica, necesitamos hacer un cast
        ((IAnimal)gato).Action();  // Salida: miau miau miau
        ((IHerramienta)gato).Action();  // Salida: Levantando vehiculo ...
    }
}