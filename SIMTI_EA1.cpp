/* Bibliotecas importadas para que el software funcione adecuadamente */
#include <iostream>
#include <string>
#include <vector>
#include <fstream> 

using namespace std;
const char *nombre_archivo = "inventario.dat";

/* Aquí cree una enumeracción para manejar de mejor manera las categorias */
enum categorias {
    equiposDeDiagnostico = 1,
    equiposDeTratamiento,
    equiposDeMonitorizacion,
    istrumentalQuirurgico,
    equiposDeLaboratorio,
    mobiliarioClinico,
    dispositivosMedicosEspecializados
};

/* en este caso decidi cambiar las propiedades del objeto Equipo: descripcion, categorias y propietario para un mejor manejo de los datos */
struct Equipo {
    int id_equipo;
    std::string descripcion;
    categorias categoria;
    std::string estado;
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

/* Aquí ordene un poco el código  de la función agregar equipo.
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

    /* Para esta sección se uso un bucle do while para que compruebe primero si el usario ingreso un numero de categoria mayor de 1 y menor de 7.

    Dependiendo del valor ingresado es asignada a su categoria correspondiente. */
    int categoriaSeleccionada;
    do {
        std::cout << "Ingrese una categoria (Del 01 al 07): ";
        std::cin >> categoriaSeleccionada;
        std::cin.ignore();
    } while (categoriaSeleccionada < 1 || categoriaSeleccionada > 7);
    equipo.categoria = static_cast<categorias>(categoriaSeleccionada);

/* Para esta parte del código se respeto el código original, se estilizo un poco para mayor legibilidad y se ajusto el consumo de datos de entrada a getline */
    std::cout << "-------------------------" << std::endl;
    std::cout << "Estados Disponibles" << std::endl;
    std::cout << "OP: Operativo." << std::endl;
    std::cout << "RE: Reparación." << std::endl;
    std::cout << "FS: Fuera de Servicio." << std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout << "Ingrese el estado del equipo (OP, RE o FS): ";
    std::getline(std::cin, equipo.estado);

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

/* Función Buscar equipo por ID */
void buscarEquipoId(){
    int buscarId;
    std::cout << "ingresa el id del equipo que desea buscar: ";
    std::cin >> buscarId;
    std::cin.ignore();

    bool encontrado = false;
    for(const auto& equipo: inventario){
        if (equipo.id_equipo == buscarId){
            std::cout << "Equipo encontrado:" << std::endl;
            std::cout << "-------------------------" << std::endl;
            std::cout << "ID: " << equipo.id_equipo << std::endl;
            std::cout << "Descripcion: " << equipo.descripcion << std::endl;
            std::cout << "Categoria: " << categoriaToString(equipo.categoria) << std::endl;
            std::cout << "Estado: " << equipo.estado << std::endl;
            std::cout << "Propietario: " << equipo.propietario << std::endl;
            std::cout << "Fecha de compra: " << equipo.fecha_compra << std::endl;
            std::cout << "Valor: " << equipo.valor << std::endl;
            std::cout << "-------------------------" << std::endl;
            encontrado = true;
            break;
        }else{
            std::cout << "No se encontro ningun equipo con el ID que ingresaste: " << buscarId << std::endl;
        }
    }
}

/* Función Actualizar equipo por ID */
void actualizarEquipo() {
    int actualizarId;
    std::cout << "Ingrese el ID del equipo que desea actualizar: ";
    std::cin >> actualizarId;
    std::cin.ignore();

    for (auto& equipo : inventario) {
        if (equipo.id_equipo == actualizarId) {
            std::cout << "Equipo encontrado. Ingrese los nuevos datos:" << std::endl;
            std::cout << "-------------------------" << std::endl;

            std::cout << "Ingrese la nueva descripcion del equipo: ";
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

            int categoriaSeleccionada;
            do {
                std::cout << "Ingrese la nueva categoria (Del 01 al 07): ";
                std::cin >> categoriaSeleccionada;
                std::cin.ignore();
            } while (categoriaSeleccionada < 1 || categoriaSeleccionada > 7);
            equipo.categoria = static_cast<categorias>(categoriaSeleccionada);

            std::cout << "-------------------------" << std::endl;
            std::cout << "Estados Disponibles" << std::endl;
            std::cout << "OP: Operativo." << std::endl;
            std::cout << "RE: Reparación." << std::endl;
            std::cout << "FS: Fuera de Servicio." << std::endl;
            std::cout << "-------------------------" << std::endl;
            std::cout << "Ingrese el nuevo estado del equipo (OP, RE o FS): ";
            std::getline(std::cin, equipo.estado);

            std::cout << "Ingrese el nuevo propietario del equipo: ";
            std::getline(std::cin, equipo.propietario);

            std::cout << "Ingrese la nueva fecha de compra del equipo (dd-mm-yyyy): ";
            std::getline(std::cin, equipo.fecha_compra);

            std::cout << "Ingrese el nuevo valor de adquisicion del equipo: ";
            std::cin >> equipo.valor;
            std::cin.ignore();

            std::cout << "Equipo actualizado correctamente." << std::endl;
            return;
        }
    }

    std::cout << "No se encontro ningun equipo con el ID: " << actualizarId << std::endl;
}

/* Función Eliminar equipo por ID */
void eliminarEquipo() {
    int idEliminar;
    std::cout << "Ingrese el ID del equipo que desea eliminar: ";
    std::cin >> idEliminar;
    std::cin.ignore();

    for (auto it = inventario.begin(); it != inventario.end(); ++it) {
        if (it->id_equipo == idEliminar) {
            inventario.erase(it);
            std::cout << "Equipo eliminado correctamente." << std::endl;
            return;
        }
    }

    std::cout << "No se encontro ningun equipo con el ID: " << idEliminar << std::endl;
}

/* Función Mostrar inventario */
void mostrarInventario() {
    if (inventario.empty()) {
        std::cout << "El inventario esta vacio." << std::endl;
    } else {
        std::cout << "-------------------------" << std::endl;
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

/* Función Cargar inventario */
void cargarInventario() {
    std::ifstream archivo(nombre_archivo, std::ios::binary);
    if (archivo.is_open()) {
        while (archivo.peek() != EOF) {
            Equipo equipo;
            size_t len;

            archivo.read(reinterpret_cast<char*>(&equipo.id_equipo), sizeof(equipo.id_equipo));

            archivo.read(reinterpret_cast<char*>(&len), sizeof(len));
            equipo.descripcion.resize(len);
            archivo.read(&equipo.descripcion[0], len);

            archivo.read(reinterpret_cast<char*>(&equipo.categoria), sizeof(equipo.categoria));

            archivo.read(reinterpret_cast<char*>(&len), sizeof(len));
            equipo.estado.resize(len);
            archivo.read(&equipo.estado[0], len);

            archivo.read(reinterpret_cast<char*>(&len), sizeof(len));
            equipo.propietario.resize(len);
            archivo.read(&equipo.propietario[0], len);

            archivo.read(reinterpret_cast<char*>(&len), sizeof(len));
            equipo.fecha_compra.resize(len);
            archivo.read(&equipo.fecha_compra[0], len);

            archivo.read(reinterpret_cast<char*>(&equipo.valor), sizeof(equipo.valor));

            inventario.push_back(equipo);
        }
        archivo.close();
        std::cout << "Inventario cargado desde " << nombre_archivo << std::endl;
    } else {
        std::cout << "No se encontro el archivo " << nombre_archivo << ". Se iniciara un inventario vacio." << std::endl;
    }
}

/* Función Guardar inventario */
void guardarInventario() {
    std::ofstream archivo(nombre_archivo, std::ios::binary);
    if (archivo.is_open()) {
        for (const auto& equipo : inventario) {
            archivo.write(reinterpret_cast<const char*>(&equipo.id_equipo), sizeof(equipo.id_equipo));
            size_t len = equipo.descripcion.length();
            archivo.write(reinterpret_cast<const char*>(&len), sizeof(len));
            archivo.write(equipo.descripcion.c_str(), len);
            archivo.write(reinterpret_cast<const char*>(&equipo.categoria), sizeof(equipo.categoria));
            len = equipo.estado.length();
            archivo.write(reinterpret_cast<const char*>(&len), sizeof(len));
            archivo.write(equipo.estado.c_str(), len);
            len = equipo.propietario.length();
            archivo.write(reinterpret_cast<const char*>(&len), sizeof(len));
            archivo.write(equipo.propietario.c_str(), len);
            len = equipo.fecha_compra.length();
            archivo.write(reinterpret_cast<const char*>(&len), sizeof(len));
            archivo.write(equipo.fecha_compra.c_str(), len);
            archivo.write(reinterpret_cast<const char*>(&equipo.valor), sizeof(equipo.valor));
        }
        archivo.close();
        std::cout << "Guardando datos.. " << std::endl;
        std::cout << "-------------------------" << std::endl;
    } else {
        std::cerr << "No se pudo abrir el archivo para guardar el inventario." << std::endl;
    }
}


int main() {
    int opcion;
    cargarInventario();

    do {
        std::cout << "--------------------------" << std::endl;
        std::cout << "Sistema de Inventario MedTech Innovations" << std::endl;
        std::cout << "--------------------------" << std::endl;
        std::cout << "1. Agregar equipo" << std::endl;
        std::cout << "2. Actualizar equipo" << std::endl;
        std::cout << "3. Eliminar equipo" << std::endl;
        std::cout << "4. Mostrar inventario" << std::endl;
        std::cout << "5. Buscar equipo por ID" << std::endl;
        std::cout << "6. Ayuda" << std::endl;
        std::cout << "7. Salir" << std::endl;
        std::cout << "Ingrese una opcion: ";
        std::cin >> opcion;


        switch (opcion) {
            case 1:
                agregarEquipo();
                break;
            case 2:
                actualizarEquipo();
                break;
            case 3:
                eliminarEquipo();
                break;
            case 4:
                mostrarInventario();
                    break;
            case 5:
                buscarEquipoId();
                break;
            case 6:
                std::cout << "Instruciones de uso" << std::endl;
                std::cout << "----------------------" << std::endl;
                std::cout << "Lea con atención el menú, elija la opción correspondiente mediante un número del 1-7" << std::endl;
                std::cout << "1 permite agregar un dato al inventario" << std::endl;
                std::cout << "2 permite actualizar un dato por medio de su ID" << std::endl;
                std::cout << "3 permite eliminar un dato del inventario por medio de su ID" << std::endl;
                std::cout << "4 permite ver el inventario completo" << std::endl;
                std::cout << "5 permite buscar un dato individual por ID" << std::endl;
                std::cout << "6 muestra el menú de ayuda" << std::endl;
                std::cout << "7 permite salir del programa" << std::endl;
                std::cout << "----------------------" << std::endl;
                break;
            case 7:
                guardarInventario();
                std::cout << "Saliendo del programa..." << std::endl;
                break;
            default:
                std::cout << "Opcion invalida. Intente nuevamente." << std::endl;
                break;
        }
    } while (opcion != 7);

    return 0;
};
