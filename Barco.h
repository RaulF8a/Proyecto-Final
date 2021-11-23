#ifndef BARCO_H
#define BARCO_H
#include <iostream>
#include <iomanip>
#include <stack>
#include "Guerrero.h"

using namespace std;

class Barco {
    public:
        Barco ();

        void setID (const string &value);
        string getID ();
        void setCombustible (float value);
        float getCombustible ();
        void setVelocidad (float value);
        float getVelocidad ();
        void setArmadura (float value);
        float getArmadura ();

        void agregarGuerrero (const Guerrero &value);
        void eliminarGuerrero ();
        void topeGuerrero ();
        size_t sizeGuerreros ();
        void mostrarGuerreros ();

        friend ostream& operator << (ostream &out, Barco &b){
            out << left;
            out << setw(20) << b.id;
            out << setw(20) << b.combustible;
            out << setw(25) << b.velocidad;
            out << setw(20) << b.armadura;
            out << setw(20) << b.sizeGuerreros();

            return out;
        }

    private:
        string id;
        float combustible;
        float velocidad;
        float armadura;

        stack<Guerrero> guerreros;
};

#endif