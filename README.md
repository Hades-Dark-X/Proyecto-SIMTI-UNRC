# Software de inventario SIMTI_EA1.

<p>
El software busca implementar una aplicación de terminal que le permita a la empresa llevar un registo de su inventario. Así mismo busca que el programador novato se familiarise con los tipos de datos, las estructuras de control, las funciones y su sintaxis en C++.
</p>

### Requisitos para trabajar con el proyecto.

- Instalar MSYS2
  https://www.msys2.org/

- Instalar Visual Studio Code
  https://code.visualstudio.com/ - Extencsión C/C++ de Microsoft

- Si lo prefieres puedes trabajar con DevC++
  https://www.bloodshed.net/

- También puedes trabajar online con:
  https://www.jdoodle.com/online-compiler-c++

  https://www.onlinegdb.com/online_c++_compiler

### Ejemplos:

Struct o estructura

```C++
struct Equipo {
    int id_equipo;
    char descripcion[101];
    int categoria;
    char estado[3];
    char propietario[101];
    std::string fecha_compra;
    double valor;
};
```

Salida standard por terminal o pantalla.

```C++
std::cout << "Ingrese la identificacion del equipo: ";
```

Entrada standard de datos por teclado.

```C++
std::cin >> equipo.valor;
    std::cin.ignore();
```

Funcion de mostrar inventario y estructura condicional if, else

```C++
void mostrarInventario() {
    if (inventario.empty()) {
        std::cout << "El inventario esta vacio." << std::endl;
    } else {
        std::cout << "Inventario:" << std::endl;
        for (std::vector<Equipo>::const_iterator it = inventario.begin(); it != inventario.end(); ++it) {
            const Equipo& equipo = *it;
            std::cout << "ID: " << equipo.id_equipo << std::endl;
            std::cout << "Descripcion: " << equipo.descripcion << std::endl;
            std::cout << "Categoria: " << equipo.categoria << std::endl;
            std::cout << "Estado: " << equipo.estado << std::endl;
            std::cout << "Propietario: " << equipo.propietario << std::endl;
            std::cout << "Fecha de compra: " << equipo.fecha_compra << std::endl;
            std::cout << "Valor: " << equipo.valor << std::endl;
            std::cout << "-------------------------" << std::endl;
        }
    }
};
```

Bucle do while y estructura de control switch

```C++
int opcion;
    do {
        std::cout << "Sistema de Inventario MedTech Innovations" << std::endl;
        std::cout << "1. Agregar equipo" << std::endl;
        std::cout << "2. Mostrar inventario" << std::endl;
        std::cout << "3. Salir" << std::endl;
        std::cout << "Ingrese una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                agregarEquipo();
                break;
            case 2:
                mostrarInventario();
                break;
            case 3:
                std::cout << "Saliendo del programa..." << std::endl;
                break;
            default:
                std::cout << "Opcion invalida. Intente nuevamente." << std::endl;
                break;
        }
    } while (opcion != 3);
```

---

### Reporte.

---

El objetivo de esta aplicación es adentrar a los futuros profesionales a los conceptos básicos del lenguaje de C++ y el paradigma de la programación estructurada.

- Como principales tareas es identificar los tipos de datos primitivos y compuestos
- Identificar estructuras de control como lo son condicionales o bucles
- Conocer la estructura de una función
- Identificar la función `main`
- Familiarizarse con la biblioteca`iostream` y `string`

#### Análisis del código original

- El código original de la app se puede compilar y ejecutar de manera correcta y me permitió observar el comportamiento de un inventario que se utiliza para venta y reparación de equipo médico.

- Primeramente, me propuse ordenar de una mejor manera el código antes de cambiar alguna de sus partes con la finalidad de que fuese más legible y por consiguiente, más fácil de manejar.

- Como segunda encomienda me dispuse a ir identificando los tipos de datos, una vez identificados los tipos de datos me aboque a entender como podría cambiarlos para ser más eficiente en el manejo de la información.

- La siguiente tarea fue observar que estructuras de control había en el proyecto para posteriormente encontrar una manera de optimizarlas y que tuvieran un mejor comportamiento.

#### Implementación de mejoras

- Los cambios se realizaron de manera sistemática, un cambio a la vez para después correr el código y observar si trabajaba de manera adecuada, debo señalar que fue desafiante enfrentar los errores de la salida de comandos por terminal.

- El mayor reto fue manejar los condicionales y bucles para manejar las categorías, usé un bucle do while donde primero verifica si el usuario ingreso un número entre 1 y 7 si es así utiliza un método del objeto equipo para seleccionar la categoría adecuada desde la enumeración categorías.

```C++
 int categoriaSeleccionada;

    do {

        std::cout << "Ingrese una categoria (Del 01 al 07): ";

        std::cin >> categoriaSeleccionada;

        std::cin.ignore();

    } while (categoriaSeleccionada < 1 || categoriaSeleccionada > 7);

    equipo.categoria = static_cast<categorias>(categoriaSeleccionada);
```

- Realice cambios en el tipo de datos en casos donde considere que string era mejor opción que char para el manejo de cadena de caracteres.

- Código original:

```C++
char descripcion[101];
```

- Código mejorado

```C++
std::string descripcion;
```

- Se cambió la propiedad de la estructura equipo atreves de una enumeración para el mejor manejo de las categorías de los artículos del inventario.

- Use una función para transformar los valores enteros de la enumeración por cadenas de caracteres por medio de un switch en donde cada caso devolvía el string correspondiente a cada categoría.

- Para agregar los datos de categoría ingresados por el usuario primero hice un bucle while que comprueba primero la condición si el usuario ingreso un dato numérico correcto y después lo guarda en la propiedad categorías de la estructura equipo.

- Se respetó el código en la medida de lo posible.

#### Conclusiones.

Los cambios realizados se llevaron a cabo con la finalidad de darle legibilidad al código, eficiencia y mayor capacidad de escalabilidad hacia el futuro.

---

Última actualización:

- Se implementó la función de buscar equipo por medio del su ID
- Se agregó la funcionalidad de actualizar equipo a través de su ID
- En esta última versión podemos eliminar un equipo del inventario por ID
- Se implementó la persistencia de datos mediante las funciones cargarInventario y GuardarInventario
- Podemos acceder a un menú de ayuda para orientarnos sobre el manejo de la app
- Se corrigieron errores estéticos que hacen la experiencia de usuario más amigable
