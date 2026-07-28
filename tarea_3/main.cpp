#include <iostream>
#include <vector>

#include "Cancion.h"
#include "Podcast.h"

using namespace std;

void registrarCancion(vector<Audio*>& lista)
{
    string titulo, artista;

    cout << "Titulo de la cancion: ";
    cin.ignore();
    getline(cin, titulo);

    cout << "Artista: ";
    getline(cin, artista);

    lista.push_back(new Cancion(titulo, artista));

    cout << "Cancion registrada.\n";
}

void registrarPodcast(vector<Audio*>& lista)
{
    string titulo, presentador;

    cout << "Titulo del podcast: ";
    cin.ignore();
    getline(cin, titulo);

    cout << "Presentador: ";
    getline(cin, presentador);

    lista.push_back(new Podcast(titulo, presentador));

    cout << "Podcast registrado.\n";
}

void mostrarAudios(const vector<Audio*>& lista)
{
    if (lista.empty())
    {
        cout << "No hay audios registrados.\n";
        return;
    }

    cout << "\n--- Lista de audios ---\n";

for (Audio* audio : lista)
{
    audio->mostrar();
}
}

int main()
{
vector<Audio*> lista;
int opcion = -1;

while (opcion != 0)
{
    cout << "\n=== Registro de audios ===\n";
    cout << "1. Registrar cancion\n";
    cout << "2. Registrar podcast\n";
    cout << "3. Mostrar audios\n";
    cout << "0. Salir\n";
    cout << "Opcion: ";

    cin >> opcion;

    if (opcion == 1)
    {
        registrarCancion(lista);
    }
    else if (opcion == 2)
    {
        registrarPodcast(lista);
    }
    else if (opcion == 3)
    {
        mostrarAudios(lista);
    }
    else if (opcion != 0)
    {
        cout << "Opcion no valida.\n";
    }
}

for (Audio* audio : lista)
{
    delete audio;
}

return 0;
}
