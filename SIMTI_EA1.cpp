/* Bibliotecas importadas para que el software duncione adecuadamente */
#include <iostream>
#include <string>
#include <vector>

using namespace std;
const char *nombre_archivo = "inventario.dat";

/* áqui cree una enumeracción para manejar de mejor manera las categorias */
enum categorias {
    equiposDeDiagnostico = 1,
    equiposDeTratamiento,
    equiposDeMonitorizacion,
    istrumentalQuirurgico,
    equiposDeLaboratorio,
    mobiliarioClinico,
    dispositivosMedicosEspecializados
};

/* en este caso dicidi cambiar las propiedades del objeto Equipo: descripcion, categorias y propietario para un mejor manejo de los datos */
struct Equipo {
    int id_equipo;
    std::string descripcion;
    categorias categoria;
    char estado[3];
    std::string propietario;
    std::string fecha_compra;
    double valor;
};

std::vector<Equipo> inventario;

/* como la enumeración solo acepta valores enteros, se creo una función para convertir los valores enteros a strings mediante un switch */
std::string categoriaToString(categorias categoria) {
    switch (categoria) {
        case equiposDeDiagnostico: return "Equipos de diagnostico";
        case equiposDeTratamiento: return "Equipos de tratamiento";
        case equiposDeMonitorizacion: return "Equipos de monitorizacion";
        case istrumentalQuirurgico: return "Instrumental quirurgico";
        case equiposDeLaboratorio: return "Equipos de laboratorio";
        case mobiliarioClinico: return "Mobiliario clinico";
        case dispositivosMedicosEspecializados: return "Dispositivos medicos especializados";
        default: return "Categoria desconocida";
    }
};

/* áqui ordene un poco el código  de la función agregar equipo.
 Para mayor legibilidad y ajuste la entradad de datos standard de strings a getline para que consuma los datos de manera adecuada */
void agregarEquipo() {
    Equipo equipo;

    std::cout << "Ingrese la identificacion del equipo (debe ser número entero): ";
    std::cin >> equipo.id_equipo;
    std::cin.ignore();

    std::cout << "Ingrese la descripcion del equipo: ";
    std::getline(std::cin, equipo.descripcion);

    std::cout << "-------------------------" << std::endl;
    std::cout << "Categorias Disponibles" << std::endl;
    std::cout << "Categoria 01: Equipos de diagnostico (ecografos y equipos de rayos X)." << std::endl;
    std::cout << "Categoria 02: Equipos de tratamiento (respiradores y bombas de infusion)." << std::endl;
    std::cout << "Categoria 03: Equipos de monitorizacion (monitores de signos vitales y electrocardiografos)." << std::endl;
    std::cout << "Categoria 04: Instrumental quirurgico (como bisturis, pinzas y tijeras)." << std::endl;
    std::cout << "Categoria 05: Equipos de laboratorio (como centrifugas y microscopios)." << std::endl;
    std::cout << "Categoria 06: Mobiliario clinico (como camas, mesas hospitalarias y sillas de ruedas)." << std::endl;
    std::cout << "Categoria 07: Dispositivos medicos especializados (marcapasos y protesis)." << std::endl;
    std::cout << "-------------------------" << std::endl;

    /* para esta sección se uso un bucle do while para que compruebe primero si el usario ingreso un numero de categoria mayor de 1 y menor de 7.
    Dependiendo de el valor ingresado es asignada a su categoria correspondiente. */
    int categoriaSeleccionada;
    do {
        std::cout << "Ingrese una categoria (Del 01 al 07): ";
        std::cin >> categoriaSeleccionada;
        std::cin.ignore();
    } while (categoriaSeleccionada < 1 || categoriaSeleccionada > 7);
    equipo.categoria = static_cast<categorias>(categoriaSeleccionada);

/* para esta parte del código se respeto el código original, se estilizo un poco para mayor legibilidad y se ajusto el consumo de datos de entrada a getline */
    std::cout << "-------------------------" << std::endl;
    std::cout << "Estados Disponibles" << std::endl;
    std::cout << "OP: Operativo." << std::endl;
    std::cout << "RE: Reparación." << std::endl;
    std::cout << "FS: Fuera de Servicio." << std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout << "Ingrese el estado del equipo (OP, RE o FS): ";
    std::cin.getline(equipo.estado, 3);

    std::cout << "Ingrese el propietario del equipo: ";
    std::getline(std::cin, equipo.propietario);

    std::cout << "Ingrese la fecha de compra del equipo (dd-mm-yyyy): ";
    std::getline(std::cin, equipo.fecha_compra);

    std::cout << "Ingrese el valor de adquisicion del equipo: ";
    std::cin >> equipo.valor;
    std::cin.ignore();

    inventario.push_back(equipo);
    std::cout << "Equipo agregado al inventario correctamente." << std::endl;
};

void mostrarInventario() {
    if (inventario.empty()) {
        std::cout << "El inventario esta vacio." << std::endl;
    } else {
        std::cout << "Inventario:" << std::endl;
        for (const auto& equipo : inventario) {
            std::cout << "ID: " << equipo.id_equipo << std::endl;
            std::cout << "Descripcion: " << equipo.descripcion << std::endl;
            std::cout << "Categoria: " << categoriaToString(equipo.categoria) << std::endl;
            std::cout << "Estado: " << equipo.estado << std::endl;
            std::cout << "Propietario: " << equipo.propietario << std::endl;
            std::cout << "Fecha de compra: " << equipo.fecha_compra << std::endl;
            std::cout << "Valor: " << equipo.valor << std::endl;
            std::cout << "-------------------------" << std::endl;
        }
    }
};

int main() {
    int opcion;
    do {
        std::cout << "Sistema de Inventario MedTech Innovations" << std::endl;
        std::cout << "1. Agregar equipo" << std::endl;
        std::cout << "2. Mostrar inventario" << std::endl;
        std::cout << "3. Salir" << std::endl;
        std::cout << "Ingrese una opcion: ";
        std::cin >> opcion;

        /* proximamente se desarrollará el crud para mostar Equipo por ID, actualizar y eliminar al menu. */
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

    return 0;
};
