#ifndef CIVILIZACION_H
#define CIVILIZACION_H
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <list>
#include "Aldeano.h"

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

        void agregarFinal (const Aldeano &value);
        void agregarInicio (const Aldeano &value);
        void mostrarAldeanos ();
        void eliminarNombre (const string &value);
        void eliminarSalud (size_t value);
        void eliminarEdad ();
        void ordenarNombre ();
        void ordenarEdad ();
        void ordenarSalud ();
        Aldeano* buscarAldeano (const string &value);

        void modificarNombre (Aldeano &value, const string &nuevoNombre);
        void modificarEdad (Aldeano &value, size_t nuevaEdad);
        void modificarGenero (Aldeano &value, const string &nuevoGenero);
        void modificarSalud (Aldeano &value, float nuevaSalud);

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

        friend ostream& operator << (ostream &out, const Civilizacion &c){
            out << left;
            out << setw(20) << c.nombre;
            out << setw(20) << c.x;
            out << setw(25) << c.y;
            out << setw(30) << c.puntuacion;

            return out;
        }

        friend istream& operator >> (istream &in, Civilizacion &c){
            cout << "Nombre de la Civilizacion: ";
            fflush (stdin);
            getline (cin, c.nombre);

            cout << "Posicion en X: ";
            cin >> c.x;

            cout << "Posicion en Y: ";
            cin >> c.y;

            cout << "Puntuacion: ";
            cin >> c.puntuacion;

            return in;
        }

    private:
        string nombre;
        size_t x;
        size_t y;
        float puntuacion;

        list <Aldeano> aldeanos;
};

#endif