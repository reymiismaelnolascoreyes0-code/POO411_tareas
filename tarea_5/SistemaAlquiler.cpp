#include "SistemaAlquiler.h"
#include "Automovil.h"
#include "Motocicleta.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdexcept>

SistemaAlquiler::SistemaAlquiler() {
    cargarClientes();
    cargarVehiculos();
    cargarAlquileres();
}

std::string SistemaAlquiler::leerTexto(const std::string& mensaje) const {
    std::string texto;
    while (true) {
        std::cout << mensaje;
        std::getline(std::cin, texto);
        if (!texto.empty()) {
            return texto;
        }
        std::cout << "El texto no puede estar vacio." << std::endl;
    }
}

int SistemaAlquiler::leerEntero(const std::string& mensaje) const {
    std::string texto;
    while (true) {
        std::cout << mensaje;
        std::getline(std::cin, texto);
        try {
            int valor = std::stoi(texto);
            if (valor > 0) {
                return valor;
            }
        } catch (const std::exception&) {
        }
        std::cout << "Debe ingresar un numero entero positivo." << std::endl;
    }
}

double SistemaAlquiler::leerDouble(const std::string& mensaje) const {
    std::string texto;
    while (true) {
        std::cout << mensaje;
        std::getline(std::cin, texto);
        try {
            double valor = std::stod(texto);
            if (valor > 0) {
                return valor;
            }
        } catch (const std::exception&) {
        }
        std::cout << "Debe ingresar un numero positivo." << std::endl;
    }
}

std::vector<std::string> SistemaAlquiler::dividirLinea(const std::string& linea, char separador) const {
    std::vector<std::string> partes;
    std::string actual;
    for (char c : linea) {
        if (c == separador) {
            partes.push_back(actual);
            actual.clear();
        } else {
            actual += c;
        }
    }
    partes.push_back(actual);
    return partes;
}

bool SistemaAlquiler::existeCliente(const std::string& cedula) const {
    for (const auto& cliente : clientes) {
        if (cliente.getCedula() == cedula) {
            return true;
        }
    }
    return false;
}

bool SistemaAlquiler::existeVehiculo(const std::string& matricula) const {
    for (const auto& vehiculo : vehiculos) {
        if (vehiculo->getMatricula() == matricula) {
            return true;
        }
    }
    return false;
}

int SistemaAlquiler::contarAlquileresActivos(const std::string& cedula) const {
    int contador = 0;
    for (const auto& alquiler : alquileres) {
        if (alquiler.getCedulaCliente() == cedula && alquiler.getActivo()) {
            contador++;
        }
    }
    return contador;
}

Vehiculo* SistemaAlquiler::buscarVehiculo(const std::string& matricula) {
    for (auto& vehiculo : vehiculos) {
        if (vehiculo->getMatricula() == matricula) {
            return vehiculo.get();
        }
    }
    return nullptr;
}

void SistemaAlquiler::cargarClientes() {
    std::ifstream archivo("clientes.txt");
    if (!archivo) {
        return;
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        if (linea.empty()) {
            continue;
        }
        std::vector<std::string> partes = dividirLinea(linea, ';');
        if (partes.size() == 3) {
            Cliente cliente(partes[0], partes[1], partes[2]);
            clientes.push_back(cliente);
        }
    }
}

void SistemaAlquiler::cargarVehiculos() {
    std::ifstream archivo("vehiculos.txt");
    if (!archivo) {
        return;
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        if (linea.empty()) {
            continue;
        }
        std::vector<std::string> partes = dividirLinea(linea, ';');
        if (partes.size() != 8) {
            continue;
        }

        std::string tipo = partes[0];
        std::string matricula = partes[1];
        std::string marca = partes[2];
        std::string modelo = partes[3];
        int anio = std::stoi(partes[4]);
        double tarifa = std::stod(partes[5]);
        bool disponible = (partes[6] == "1");
        int extra = std::stoi(partes[7]);

        if (tipo == "AUTO") {
            auto vehiculo = std::make_unique<Automovil>(matricula, marca, modelo, anio, tarifa, extra);
            vehiculo->setDisponible(disponible);
            vehiculos.push_back(std::move(vehiculo));
        } else if (tipo == "MOTO") {
            auto vehiculo = std::make_unique<Motocicleta>(matricula, marca, modelo, anio, tarifa, extra);
            vehiculo->setDisponible(disponible);
            vehiculos.push_back(std::move(vehiculo));
        }
    }
}

void SistemaAlquiler::cargarAlquileres() {
    std::ifstream archivo("alquileres.txt");
    if (!archivo) {
        return;
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        if (linea.empty()) {
            continue;
        }
        std::vector<std::string> partes = dividirLinea(linea, ';');
        if (partes.size() != 7) {
            continue;
        }

        int dias = std::stoi(partes[4]);
        double tarifa = std::stod(partes[5]);

        Alquiler alquiler(partes[0], partes[1], partes[2], partes[3], dias, tarifa);
        if (partes[6] == "0") {
            alquiler.finalizar();
        }
        alquileres.push_back(alquiler);
    }
}

void SistemaAlquiler::guardarClientes() const {
    std::ofstream archivo("clientes.txt");
    for (const auto& cliente : clientes) {
        archivo << cliente.getCedula() << ";" << cliente.getNombre() << ";" << cliente.getTelefono() << std::endl;
    }
}

void SistemaAlquiler::guardarVehiculos() const {
    std::ofstream archivo("vehiculos.txt");
    for (const auto& vehiculo : vehiculos) {
        std::string tipo = (vehiculo->obtenerTipo() == "Automovil") ? "AUTO" : "MOTO";
        archivo << tipo << ";" << vehiculo->getMatricula() << ";" << vehiculo->getMarca() << ";" << vehiculo->getModelo() << ";" << vehiculo->getAnio() << ";" << vehiculo->getTarifaBase() << ";" << (vehiculo->getDisponible() ? "1" : "0") << ";" << vehiculo->obtenerDatoExtra() << std::endl;
    }
}

void SistemaAlquiler::guardarAlquileres() const {
    std::ofstream archivo("alquileres.txt");
    for (const auto& alquiler : alquileres) {
        archivo << alquiler.getCodigo() << ";" << alquiler.getCedulaCliente() << ";" << alquiler.getMatriculaVehiculo() << ";" << alquiler.getFechaInicio() << ";" << alquiler.getDias() << ";" << alquiler.getTarifaDiaria() << ";" << (alquiler.getActivo() ? "1" : "0") << std::endl;
    }
}

void SistemaAlquiler::registrarCliente() {
    std::string cedula;
    while (true) {
        cedula = leerTexto("Cedula: ");
        if (!existeCliente(cedula)) {
            break;
        }
        std::cout << "Ya existe un cliente con esa cedula." << std::endl;
    }

    std::string nombre = leerTexto("Nombre completo: ");
    std::string telefono = leerTexto("Telefono: ");

    Cliente nuevo(cedula, nombre, telefono);
    clientes.push_back(nuevo);

    std::cout << "Cliente registrado." << std::endl;
}

void SistemaAlquiler::registrarAutomovil() {
    std::string matricula;
    while (true) {
        matricula = leerTexto("Matricula: ");
        if (!existeVehiculo(matricula)) {
            break;
        }
        std::cout << "Ya existe un vehiculo con esa matricula." << std::endl;
    }

    std::string marca = leerTexto("Marca: ");
    std::string modelo = leerTexto("Modelo: ");
    int anio = leerEntero("Anio: ");
    double tarifa = leerDouble("Tarifa diaria: ");
    int puertas = leerEntero("Cantidad de puertas: ");

    vehiculos.push_back(std::make_unique<Automovil>(matricula, marca, modelo, anio, tarifa, puertas));

    std::cout << "Automovil registrado." << std::endl;
}

void SistemaAlquiler::registrarMotocicleta() {
    std::string matricula;
    while (true) {
        matricula = leerTexto("Matricula: ");
        if (!existeVehiculo(matricula)) {
            break;
        }
        std::cout << "Ya existe un vehiculo con esa matricula." << std::endl;
    }

    std::string marca = leerTexto("Marca: ");
    std::string modelo = leerTexto("Modelo: ");
    int anio = leerEntero("Anio: ");
    double tarifa = leerDouble("Tarifa diaria: ");
    int cilindrada = leerEntero("Cilindrada: ");

    vehiculos.push_back(std::make_unique<Motocicleta>(matricula, marca, modelo, anio, tarifa, cilindrada));

    std::cout << "Motocicleta registrada." << std::endl;
}

void SistemaAlquiler::verClientes() const {
    if (clientes.empty()) {
        std::cout << "No hay clientes registrados." << std::endl;
        return;
    }

    std::cout << std::left << std::setw(15) << "Cedula" << std::setw(25) << "Nombre" << "Telefono" << std::endl;
    for (const auto& cliente : clientes) {
        std::cout << std::left << std::setw(15) << cliente.getCedula() << std::setw(25) << cliente.getNombre() << cliente.getTelefono() << std::endl;
    }
}

void SistemaAlquiler::verVehiculos() const {
    if (vehiculos.empty()) {
        std::cout << "No hay vehiculos registrados." << std::endl;
        return;
    }

    std::cout << std::left << std::setw(10) << "Matricula" << std::setw(12) << "Marca" << std::setw(12) << "Modelo" << std::setw(6) << "Anio" << std::setw(10) << "Tarifa" << std::setw(12) << "Disponible" << "Dato extra" << std::endl;
    for (const auto& vehiculo : vehiculos) {
        std::string etiqueta = (vehiculo->obtenerTipo() == "Automovil") ? "Puertas: " : "Cilindrada: ";
        std::cout << std::left << std::setw(10) << vehiculo->getMatricula() << std::setw(12) << vehiculo->getMarca() << std::setw(12) << vehiculo->getModelo() << std::setw(6) << vehiculo->getAnio() << std::setw(10) << vehiculo->calcularTarifaDiaria() << std::setw(12) << (vehiculo->getDisponible() ? "Si" : "No") << etiqueta << vehiculo->obtenerDatoExtra() << std::endl;
    }
}

void SistemaAlquiler::registrarAlquiler() {
    if (clientes.empty()) {
        std::cout << "No hay clientes registrados." << std::endl;
        return;
    }
    if (vehiculos.empty()) {
        std::cout << "No hay vehiculos registrados." << std::endl;
        return;
    }

    std::string cedula;
    while (true) {
        cedula = leerTexto("Cedula del cliente: ");
        if (existeCliente(cedula)) {
            break;
        }
        std::cout << "Cliente no encontrado." << std::endl;
    }

    if (contarAlquileresActivos(cedula) >= 2) {
        std::cout << "El cliente ya tiene dos alquileres activos." << std::endl;
        return;
    }

    std::string matricula;
    Vehiculo* vehiculo = nullptr;
    while (true) {
        matricula = leerTexto("Matricula del vehiculo: ");
        vehiculo = buscarVehiculo(matricula);
        if (vehiculo == nullptr) {
            std::cout << "Vehiculo no encontrado." << std::endl;
        } else if (!vehiculo->getDisponible()) {
            std::cout << "El vehiculo no esta disponible." << std::endl;
        } else {
            break;
        }
    }

    std::string fecha = leerTexto("Fecha de inicio (aaaa-mm-dd): ");
    int dias = leerEntero("Cantidad de dias: ");

    std::string codigo = "A" + std::to_string(alquileres.size() + 1);
    double tarifa = vehiculo->calcularTarifaDiaria();

    Alquiler nuevo(codigo, cedula, matricula, fecha, dias, tarifa);
    alquileres.push_back(nuevo);
    vehiculo->setDisponible(false);

    std::cout << "Alquiler registrado con codigo " << codigo << std::endl;
}

void SistemaAlquiler::registrarDevolucion() {
    if (alquileres.empty()) {
        std::cout << "No hay alquileres registrados." << std::endl;
        return;
    }

    std::string codigo;
    Alquiler* alquiler = nullptr;
    while (true) {
        codigo = leerTexto("Codigo del alquiler: ");
        for (auto& item : alquileres) {
            if (item.getCodigo() == codigo && item.getActivo()) {
                alquiler = &item;
            }
        }
        if (alquiler != nullptr) {
            break;
        }
        std::cout << "No existe un alquiler activo con ese codigo." << std::endl;
    }

    alquiler->finalizar();

    Vehiculo* vehiculo = buscarVehiculo(alquiler->getMatriculaVehiculo());
    if (vehiculo != nullptr) {
        vehiculo->setDisponible(true);
    }

    std::cout << "Costo total: " << alquiler->calcularCostoTotal() << std::endl;
}

void SistemaAlquiler::verAlquileresActivos() const {
    bool hay = false;
    std::cout << std::left << std::setw(8) << "Codigo" << std::setw(15) << "Cedula" << std::setw(12) << "Matricula" << std::setw(12) << "Fecha" << std::setw(6) << "Dias" << "Tarifa" << std::endl;
    for (const auto& alquiler : alquileres) {
        if (alquiler.getActivo()) {
            hay = true;
            std::cout << std::left << std::setw(8) << alquiler.getCodigo() << std::setw(15) << alquiler.getCedulaCliente() << std::setw(12) << alquiler.getMatriculaVehiculo() << std::setw(12) << alquiler.getFechaInicio() << std::setw(6) << alquiler.getDias() << alquiler.getTarifaDiaria() << std::endl;
        }
    }
    if (!hay) {
        std::cout << "No hay alquileres activos." << std::endl;
    }
}

void SistemaAlquiler::verHistorialAlquileres() const {
    if (alquileres.empty()) {
        std::cout << "No hay alquileres registrados." << std::endl;
        return;
    }

    std::cout << std::left << std::setw(8) << "Codigo" << std::setw(15) << "Cedula" << std::setw(12) << "Matricula" << std::setw(10) << "Dias" << std::setw(12) << "Estado" << "Costo" << std::endl;
    for (const auto& alquiler : alquileres) {
        std::string estado = alquiler.getActivo() ? "Activo" : "Finalizado";
        std::cout << std::left << std::setw(8) << alquiler.getCodigo() << std::setw(15) << alquiler.getCedulaCliente() << std::setw(12) << alquiler.getMatriculaVehiculo() << std::setw(10) << alquiler.getDias() << std::setw(12) << estado << alquiler.calcularCostoTotal() << std::endl;
    }
}

void SistemaAlquiler::ejecutar() {
    int opcion = 0;
    while (opcion != 10) {
        std::cout << std::endl;
        std::cout << "=== Sistema de alquiler de vehiculos ===" << std::endl;
        std::cout << "1. Registrar cliente" << std::endl;
        std::cout << "2. Registrar automovil" << std::endl;
        std::cout << "3. Registrar motocicleta" << std::endl;
        std::cout << "4. Ver clientes" << std::endl;
        std::cout << "5. Ver vehiculos" << std::endl;
        std::cout << "6. Registrar alquiler" << std::endl;
        std::cout << "7. Registrar devolucion" << std::endl;
        std::cout << "8. Ver alquileres activos" << std::endl;
        std::cout << "9. Ver historial de alquileres" << std::endl;
        std::cout << "10. Guardar datos y salir" << std::endl;

        while (true) {
            opcion = leerEntero("Opcion: ");
            if (opcion >= 1 && opcion <= 10) {
                break;
            }
            std::cout << "Opcion invalida." << std::endl;
        }

        switch (opcion) {
            case 1:
                registrarCliente();
                break;
            case 2:
                registrarAutomovil();
                break;
            case 3:
                registrarMotocicleta();
                break;
            case 4:
                verClientes();
                break;
            case 5:
                verVehiculos();
                break;
            case 6:
                registrarAlquiler();
                break;
            case 7:
                registrarDevolucion();
                break;
            case 8:
                verAlquileresActivos();
                break;
            case 9:
                verHistorialAlquileres();
                break;
            case 10:
                guardarClientes();
                guardarVehiculos();
                guardarAlquileres();
                std::cout << "Datos guardados. Hasta luego." << std::endl;
                break;
            default:
                break;
        }
    }
}
