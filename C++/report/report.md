## Herencia y Polimorfismo en C++

C++ es un lenguaje de programación orientado a objetos poderoso, y dos de sus pilares fundamentales son la **herencia** y el **polimorfismo**.

### Herencia

La **herencia** es la capacidad de una clase para derivar propiedades y características de otra clase. Es una característica importante de la Programación Orientada a Objetos en C++ que permite compartir similitudes entre clases, manteniendo sus diferencias. La herencia fomenta la reutilización de código al tomar clases previamente creadas y formar nuevas clases a partir de ellas, heredando sus atributos y métodos. Las nuevas clases pueden ser modificadas agregándoles nuevas características.

*   La clase de la cual se toman las características se conoce como **clase base** (o superclase), mientras que la clase que se crea a partir de la clase base se conoce como **clase derivada** (o subclase). Se dice que una clase base es más **general** que su clase derivada, y una clase derivada es más **especializada** que su clase base.

La herencia en C++ se implementa permitiendo a una clase incorporar a otra clase dentro de su declaración usando la siguiente sintaxis:

```c++
class ClaseDerivada : modo_de_herencia ClaseBase {
    // Cuerpo de la Clase Derivada
};
```

El `modo_de_herencia` controla el nivel de acceso de los miembros heredados de la clase base en la clase derivada. En C++, existen 3 modos de herencia:

*   **Herencia Pública (`public`)**: Los miembros públicos de la clase base se convierten en miembros públicos en la clase derivada, y los miembros protegidos de la clase base se convierten en miembros protegidos en la clase derivada. Este es el tipo de acceso más comúnmente usado en la herencia.
*   **Herencia Protegida (`protected`)**: Tanto los miembros públicos como los protegidos de la clase base se convierten en miembros protegidos en la clase derivada. El acceso protegido es un nivel intermedio entre el acceso privado y público.
*   **Herencia Privada (`private`)**: Tanto los miembros públicos como los protegidos de la clase base se convierten en miembros privados en la clase derivada. El modo privado es el modo **predeterminado** si no se especifica ninguno.

Los miembros de la clase base se pueden acceder en la clase derivada simplemente usando su nombre. Sin embargo, los miembros privados de la clase base no se pueden acceder directamente en la clase derivada, mientras que los miembros protegidos y públicos sí pueden. Para acceder o actualizar los miembros privados de la clase base en la clase derivada, se deben usar las funciones `getter` y `setter` correspondientes de la clase base o declarar la clase derivada como `friend`.

En C++, existen **5 tipos de herencia** basados en la relación entre la clase derivada y la clase base:

*   **Herencia Simple**: Una clase hereda de una sola clase base.
*   **Herencia Múltiple**: Una clase hereda de más de una clase base.
*   **Herencia Multinivel**: Una clase derivada se crea a partir de otra clase derivada, y esa clase derivada puede derivar de una clase base u otra clase derivada.
*   **Herencia Jerárquica**: Más de una subclase hereda de una única clase base.
*   **Herencia Híbrida**: Se implementa combinando más de un tipo de herencia. Por ejemplo, combinar herencia jerárquica y herencia múltiple.

**Constructores y Destructores en Herencia**: Los **constructores y destructores no se heredan** en la clase derivada, pero se puede llamar al constructor de la clase base desde la clase derivada. Los constructores se llaman en el orden en que se heredan las clases (primero los de la clase base, luego los de la clase derivada), y los destructores se llaman en el orden inverso.

**Miembros Estáticos en Herencia**: Los miembros estáticos pertenecen a la clase, no a ningún objeto individual, y son compartidos por todas las instancias de la clase. Los miembros estáticos de la clase base no se heredan de la manera tradicional, pero se pueden acceder usando el nombre de la clase, como `NombreClase::miembroEstatico`.

**Funciones y Clases Amigas en Herencia**: Las funciones y clases amigas proporcionan acceso a los miembros privados y protegidos de una clase, ofreciendo flexibilidad y control sobre las interacciones entre clases.

### Polimorfismo

El **polimorfismo** permite tratar de forma genérica objetos de distintas clases derivadas de una misma clase base. Es la capacidad de objetos de diferentes clases, relacionadas mediante herencia, para responder de forma distinta a una misma llamada de un método. Una variable de tipo clase A puede almacenar referencias a objetos de cualquier tipo derivado de A.

En C++, el polimorfismo se implementa principalmente a través de **funciones virtuales**. Una función virtual es una función miembro declarada como `virtual` en una clase base y que puede ser redefinida (sobreescrita) en una o más clases derivadas.

*   Cuando se accede a una función a través de un puntero o una referencia a la clase base, y este puntero o referencia mantiene una referencia a un objeto de una clase derivada, el programa determina en tiempo de ejecución (vinculación dinámica o *late binding*) a qué función llamar, de acuerdo al tipo de objeto al que se apunta.
*   Para lograr polimorfismo en tiempo de ejecución, es necesario usar funciones virtuales. Si una función en la clase derivada tiene la misma firma (nombre, lista de parámetros, calificación `const`, y calificador de referencia) que una función virtual en la clase base, la función de la clase derivada **sobreescribe** la función virtual de la clase base.
*   Una **función virtual pura** se declara en la clase base utilizando la sintaxis `= 0` al final de su declaración (ej: `virtual void printShapeName() const = 0;`). Una clase que contiene al menos una función virtual pura se convierte en una **clase abstracta**, y no se pueden crear objetos directos de clases abstractas. Las clases abstractas sirven como interfaces, definiendo métodos que las clases derivadas deben implementar.

Es importante distinguir entre **sobreescritura (overriding)** de funciones virtuales y el **ocultamiento (hiding)** de funciones no virtuales.

*   El **ocultamiento** ocurre cuando una clase derivada declara una función con el mismo nombre que una función en la clase base, independientemente de sus firmas. La función en la clase derivada oculta la función de la clase base en el ámbito de la clase derivada. Incluso si la función en la clase base y la clase derivada tienen diferentes listas de parámetros, la función de la clase base se oculta.
*   La **sobreescritura** solo se aplica a las funciones virtuales. Para que una función en la clase derivada sobreescriba una función virtual de la clase base, deben tener la misma firma. La sobreescritura permite el polimorfismo en tiempo de ejecución.

La **sobrecarga** de métodos (no mencionada explícitamente como "concealment") consiste en la redefinición de un método dentro de la misma clase con la misma forma pero con diferente tipo y número de parámetros. Esto permite que un método tenga varias definiciones distintas con el mismo nombre.

### Visibilidad

La **visibilidad** de los miembros de una clase (atributos y métodos) está controlada por los especificadores de acceso: `public`, `protected`, y `private`.

*   Los miembros **públicos** pueden ser utilizados por cualquier método. En el contexto de la herencia pública, se mantienen públicos en la clase derivada.
*   Los miembros **protegidos** pueden ser accedidos por los métodos de la propia clase y por los métodos de sus clases derivadas. Tienen visibilidad privada para el resto de ámbitos. En la herencia pública, permanecen protegidos en la clase derivada.
*   Los miembros **privados** solo pueden ser accedidos por los métodos de la propia clase. No son directamente accesibles en las clases derivadas.

El **operador de ámbito** (`::`) se utiliza para acceder a identificadores (como nombres de variables y funciones) definidos en otro ámbito desde el ámbito actual. Por ejemplo, se puede usar para llamar explícitamente a una función de la clase base que ha sido oculta por una función con el mismo nombre en la clase derivada.

### Representación en Memoria

La representación en memoria de los objetos en C++ está relacionada con la disposición de sus miembros (atributos).

1.  **Objeto de una clase que no hereda de ninguna otra clase**: Un objeto de una clase sin herencia contendrá espacio en memoria para todos sus atributos miembro, dispuestos según el diseño de la clase definido por el programador o el compilador.

2.  **Objeto de una clase que muestra herencia simple**: Un objeto de una clase derivada con herencia simple contendrá en memoria los atributos de su clase base seguidos de los atributos definidos en la propia clase derivada. La disposición exacta puede depender del compilador, pero conceptualmente, el objeto contiene la "parte" de la clase base y la "parte" de la clase derivada.

3.  **Objeto de una clase que utiliza herencia múltiple**: Un objeto de una clase derivada con herencia múltiple contendrá en memoria las partes correspondientes a cada una de sus clases base, seguidas de los atributos definidos en la propia clase derivada. Si existen nombres de miembros ambiguos heredados de diferentes clases base, el compilador necesitará información adicional (por ejemplo, mediante el operador de ámbito) para determinar a qué miembro se está accediendo, a menos que se utilice herencia virtual para resolver la ambigüedad del "problema del diamante".

### Herencia Múltiple

La **herencia múltiple** es una característica de C++ donde una clase puede heredar de más de una clase base. Esto permite a la clase derivada combinar los miembros de todas sus clases base en una sola clase. La sintaxis para declarar herencia múltiple implica enumerar las clases base separadas por comas después de los dos puntos (`:`) en la definición de la clase derivada:

```c++
class ClaseDerivada : public ClaseBase1, public ClaseBase2, ... {
    // ...
};
```

La herencia múltiple puede llevar al **Problema del Diamante**. Este problema surge cuando una clase derivada hereda de dos o más clases base que comparten un ancestro común. Esto resulta en múltiples caminos para acceder a los miembros heredados del ancestro común, lo que genera ambigüedad durante la resolución de métodos y el acceso a miembros. El ejemplo en la fuente ilustra este problema.

C++ resuelve el Problema del Diamante utilizando la **herencia virtual**. Al declarar la herencia de la clase base como `virtual public ClaseBase`, se asegura que solo exista una única instancia de la clase base común en la jerarquía de herencia, eliminando la ambigüedad. El ejemplo en la fuente muestra cómo la herencia virtual resuelve el problema del diamante.

Es recomendable evitar el uso de herencia múltiple siempre que sea posible, ya que puede aumentar la complejidad del código. En algunos casos, la composición puede ser una alternativa más adecuada.

### Casting

El término "**casting**" en el contexto de la herencia se refiere a la conversión de un puntero o referencia de un tipo de clase a otro tipo de clase dentro de una jerarquía de herencia.

*   **Upcasting**: Convertir un puntero o referencia de una clase derivada a un puntero o referencia de su clase base. Esta conversión es **segura y a menudo implícita**, ya que un objeto de la clase derivada "es un" objeto de la clase base. El polimorfismo se basa en el upcasting para llamar a métodos virtuales de objetos derivados a través de punteros o referencias de la clase base.
*   **Downcasting**: Convertir un puntero o referencia de una clase base a un puntero o referencia de una clase derivada. Esta conversión es **potencialmente insegura** porque un objeto de la clase base no necesariamente "es un" objeto de la clase derivada. El downcasting generalmente requiere un **casting explícito** y a menudo se realiza utilizando operadores de casting seguros como `dynamic_cast` en C++, que realiza una verificación en tiempo de ejecución para asegurar que la conversión sea válida (es decir, que el objeto base al que se apunta o referencia es realmente un objeto de la clase derivada). Si la conversión no es válida, `dynamic_cast` devuelve `nullptr` para punteros o lanza una excepción de tipo `std::bad_cast` para referencias.

Las fuentes proporcionadas mencionan el concepto general de **conversión de tipos** en C++ y los **operadores de casting**, pero no se centran en los detalles específicos del casting dentro de jerarquías de herencia. Sin embargo, el concepto de polimorfismo, que se basa en la capacidad de tratar objetos derivados como objetos base, está intrínsecamente relacionado con el upcasting.