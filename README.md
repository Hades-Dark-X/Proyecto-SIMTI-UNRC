# Software de inventario SIMTI_EA1.

<p>
El software busca implementar una aplicación de terminal que le permita a la empresa llevar un registo de su inventario. Así mismo busca que el programador novato se familiarise con los tipos de datos, las estructuras de control, las funciones y su sintaxis en C++.
</p>

### Requisitos para trabajar con el proyecto.

- Instalar MSYS2
  https://www.msys2.org/

- Instalar Visual Studio Code
  https://code.visualstudio.com/ - Extencsión C/C++ de Microsoft

---

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

Funcion de y estructura condicional if, else if

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
