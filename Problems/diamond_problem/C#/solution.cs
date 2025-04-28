
/* C# no permite herencia múltiple de clases, pero sí de interfaces. 
   Si dos interfaces heredan de una tercera y definen un método por defecto, la clase que las implementa 
   debe resolver la ambigüedad explícitamente. */

using System;

public interface IA 
{
    void Print() => Console.WriteLine("A");
}

public interface IB : IA {}
public interface IC : IA {}

public class D : IB, IC 
{
    // Resuelve la ambigüedad implementando el método(otra solucion seria definir explicitamente el metodo para cada interfaz)
    public void Print() => Console.WriteLine("D");
}

public class Program 
{
    public static void Main() 
    {
        D d = new D();
        d.Print(); // Salida: "D"
    }
}