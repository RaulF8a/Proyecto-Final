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
        void primeraCivilizacion ();
        void ultimaCivilizacion ();
        void ordenarCivilizaciones();
        void eliminarCivilizacion (const Civilizacion &value);
        Civilizacion* buscarCivilizacion (const Civilizacion &value);
        void totalCivilizaciones (); //usar vector.size()

    private:
        string nombreUsuario;
        vector <Civilizacion> civilizaciones;
};

#endif