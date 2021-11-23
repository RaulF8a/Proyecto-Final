#ifndef GUERRERO_H
#define GUERRERO_H
#include <iostream>

using namespace std;

class Guerrero{
    public:
        Guerrero ();

        void setID (const string &value);
        string getID ();
        void setSalud (size_t value);
        size_t getSalud ();
        void setFuerza (float value);
        float getFuerza ();
        void setEscudo (float value);
        float getEscudo ();
        void setTipo (const string &value);
        string getTipo ();

    private:
        string id;
        size_t salud;
        float fuerza;
        float escudo;
        string tipo;
};

#endif