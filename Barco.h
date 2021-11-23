#ifndef BARCO_H
#define BARCO_H
#include <iostream>
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

    private:
        string id;
        float combustible;
        float velocidad;
        float armadura;

        stack<Guerrero> guerreros;
};

#endif