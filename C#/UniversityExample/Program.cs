namespace UniversityExample
{
    // Clase base para todas las personas en la universidad
    public abstract class Persona
    {
        public string Nombre { get; set; }

        protected Persona(string nombre)
        {
            Nombre = nombre;
        }

        public override string ToString()
        {
            return $"Nombre: {Nombre}";
        }
    }

    // Interface para los que pueden recibir clases
    public interface IReceptor
    {
        void RecibirClase(int horas);
        int HorasClaseRecibidas { get; set; }
    }

    // Interface para los que pueden impartir clases
    public interface IImpartidor
    {
        void ImpartirClase(int horas);
        int HorasClaseImpartidas { get; set; }
    }

    // Interface para los que reciben salario (plantilla)
    public interface IPlantilla
    {
        void CobrarSalario();
        decimal Salario { get; set; }
    }

    // Estudiante: Recibe clases y puede cobrar salario (becas)
    public class Estudiante : Persona, IReceptor, IPlantilla
    {
        public int HorasClaseRecibidas { get; set; }
        public decimal Salario { get; set; }

        public Estudiante(string nombre, decimal salario = 0) : base(nombre)
        {
            Salario = salario;
        }

        public void RecibirClase(int horas)
        {
            HorasClaseRecibidas += horas;
            Console.WriteLine($"{Nombre} recibió {horas} horas de clase. Total: {HorasClaseRecibidas}");
        }

        public void CobrarSalario()
        {
            Console.WriteLine($"{Nombre} cobró {Salario:C} como estudiante");
        }

        public override string ToString()
        {
            return $"Estudiante: {base.ToString()}, Horas recibidas: {HorasClaseRecibidas}, Salario: {Salario:C}";
        }
    }

    // Trabajador: Cobra salario
    public class Trabajador : Persona, IPlantilla
    {
        public decimal Salario { get; set; }

        public Trabajador(string nombre, decimal salario) : base(nombre)
        {
            Salario = salario;
        }

        public void CobrarSalario()
        {
            Console.WriteLine($"{Nombre} cobró {Salario:C} como trabajador");
        }

        public override string ToString()
        {
            return $"Trabajador: {base.ToString()}, Salario: {Salario:C}";
        }
    }

    // Profesor: Es trabajador e imparte clases
    public class Profesor : Trabajador, IImpartidor
    {
        public int HorasClaseImpartidas { get; set; }

        public Profesor(string nombre, decimal salario) : base(nombre, salario)
        {
        }

        public void ImpartirClase(int horas)
        {
            HorasClaseImpartidas += horas;
            Console.WriteLine($"{Nombre} impartió {horas} horas de clase. Total: {HorasClaseImpartidas}");
        }

        public override string ToString()
        {
            return $"Profesor: {base.ToString()}, Horas impartidas: {HorasClaseImpartidas}";
        }
    }

    // Profesor Adiestrado: Es profesor que también recibe clases
    public class ProfesorAdiestrado : Profesor, IReceptor
    {
        public int HorasClaseRecibidas { get; set; }

        public ProfesorAdiestrado(string nombre, decimal salario) : base(nombre, salario)
        {
        }

        public void RecibirClase(int horas)
        {
            HorasClaseRecibidas += horas;
            Console.WriteLine($"{Nombre} recibió {horas} horas de adiestramiento. Total: {HorasClaseRecibidas}");
        }

        public override string ToString()
        {
            return $"Profesor Adiestrado: {base.ToString()}, Horas recibidas: {HorasClaseRecibidas}";
        }
    }

    // Alumno Ayudante: Es estudiante que también puede impartir clases y recibir salario adicional
    public class AlumnoAyudante : Estudiante, IImpartidor
    {
        public int HorasClaseImpartidas { get; set; }
        public decimal SalarioAyudante { get; set; }

        public AlumnoAyudante(string nombre, decimal salarioEstudiante, decimal salarioAyudante)
            : base(nombre, salarioEstudiante)
        {
            SalarioAyudante = salarioAyudante;
        }

        public void ImpartirClase(int horas)
        {
            HorasClaseImpartidas += horas;
            Console.WriteLine($"{Nombre} impartió {horas} horas de clase como ayudante. Total: {HorasClaseImpartidas}");
        }

        public void CobrarSalarioAyudante()
        {
            Console.WriteLine($"{Nombre} cobró {SalarioAyudante:C} como ayudante");
        }

        // Sobrescribimos CobrarSalario para que cobre ambos salarios
        public new void CobrarSalario()
        {
            base.CobrarSalario(); // Cobra como estudiante
            CobrarSalarioAyudante(); // Cobra como ayudante
        }

        public override string ToString()
        {
            return $"Alumno Ayudante: {base.ToString()}, Horas impartidas: {HorasClaseImpartidas}, Salario Ayudante: {SalarioAyudante:C}";
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Sistema Universitario");
            Console.WriteLine("====================");

            // Ejemplos de uso
            var estudiante = new Estudiante("Carlos Pérez", 2000);
            estudiante.RecibirClase(20);
            estudiante.CobrarSalario();
            Console.WriteLine(estudiante);
            Console.WriteLine();

            var trabajador = new Trabajador("Ana Gómez", 15000);
            trabajador.CobrarSalario();
            Console.WriteLine(trabajador);
            Console.WriteLine();

            var profesor = new Profesor("Luis Martínez", 25000);
            profesor.ImpartirClase(15);
            profesor.CobrarSalario();
            Console.WriteLine(profesor);
            Console.WriteLine();

            var profesorAdiestrado = new ProfesorAdiestrado("Elena Rodríguez", 20000);
            profesorAdiestrado.ImpartirClase(10);
            profesorAdiestrado.RecibirClase(5);
            profesorAdiestrado.CobrarSalario();
            Console.WriteLine(profesorAdiestrado);
            Console.WriteLine();

            var alumnoAyudante = new AlumnoAyudante("Mario Fernández", 2500, 5000);
            alumnoAyudante.RecibirClase(18);
            alumnoAyudante.ImpartirClase(6);
            alumnoAyudante.CobrarSalario();
            Console.WriteLine(alumnoAyudante);
        }
    }
}