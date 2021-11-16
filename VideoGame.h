#ifndef VIDEOGAME_H
#define VIDEOGAME_H
#include <iostream>
#include <vector>
#include "Civilizacion.h"

using namespace std;

class VideoGame{
    public:
        VideoGame();

        void setNombreUsuario (const string &value);
        string getNombreUsuario ();

        void agregarCivilizacion (const Civilizacion &value);
        void insertarCivilizacion (const Civilizacion &value, size_t position);
        void inicializarCivilizaciones (const Civilizacion &value, size_t n);
        Civilizacion primeraCivilizacion ();
        Civilizacion ultimaCivilizacion ();
        void ordenarNombre ();
        void ordenarX ();
        void ordenarY ();
        void ordenarPuntuacion ();
        void eliminarCivilizacion (const string &value);
        Civilizacion* buscarCivilizacion (const string &value);
        size_t totalCivilizaciones (); //usar vector.size()
        size_t compararNombre (const string value);
        void modificarNombre (size_t position, const string &nombre);
        void modificarPosicionX (size_t position, int posX);
        void modificarPosicionY (size_t position, int posY);
        void modificarPuntuacion (size_t position, float puntuacion);
        void mostrarCivilizaciones ();
        void respaldarCivilizaciones ();
        void recuperarCivilizaciones ();

    private:
        string nombreUsuario;
        vector <Civilizacion> civilizaciones;
};

#endif