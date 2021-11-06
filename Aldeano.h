#ifndef ALDEANO_H
#define ALDEANO_H
#include <iostream>

using namespace std;

class Aldeano{
    public:
        Aldeano ();

        void setNombre (const string &value);
        string getNombre ();
        void setEdad (int value);
        int getEdad ();
        void setGenero (const string &value);
        string getGenero ();
        void setSalud (float value);
        float getSalud ();

    private:
        string nombre;
        int edad;
        string genero;
        float salud;
};

#endif