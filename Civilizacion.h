#ifndef CIVILIZACION_H
#define CIVILIZACION_H
#include <iostream>
#include <stdlib.h>

using namespace std;

class Civilizacion{
    public:
        Civilizacion();

        void setNombre (const string &value);
        string getNombre ();
        void setX (size_t value);
        size_t getX ();
        void setY (size_t value);
        size_t getY ();
        void setPuntuacion (float value);
        float getPuntuacion ();

        bool operator == (const Civilizacion &c){
            return nombre == c.nombre;
        }

        bool operator == (const Civilizacion &c) const{
            return nombre == c.nombre;
        }

        bool operator < (const Civilizacion &c){
            return nombre < c.nombre;
        }

        bool operator < (const Civilizacion &c) const{
            return nombre < c.nombre;
        }

    private:
        string nombre;
        size_t x;
        size_t y;
        float puntuacion;
};

#endif