#include <iostream>

#include "Sistema.h"



int main()
{
    Sistema sistema;

    int opcion;

    do
    {
       std::cout << "\n===== MENU =====\n";
        std::cout << "1. Agregar estudiante\n";
        std::cout << "2. Agregar materia\n";
        std::cout << "3. Agregar profesor\n";
        std::cout << "4. Registrar calificacion\n";
        std::cout << "5. Ver calificaciones\n";
        std::cout << "6. Salir\n";

        std::cout << "Opcion: ";
        std::cin >> opcion;

        switch (opcion)
        {
            case 1:
                sistema.agregarEstudiante();
                break;

            case 2:
                sistema.agregarMateria();
                break;

            case 3:
                sistema.agregarProfesor();
                break;

            case 4:
                sistema.agregarCalificacion();
                break;

            case 5:
                sistema.mostrarCalificaciones();
                break;

            case 6:
                std::cout << "Hasta luego.\n";
                break;

            default:
                std::cout << "Opcion invalida.\n";
        }

    } while (opcion != 6);

    return 0;
}
