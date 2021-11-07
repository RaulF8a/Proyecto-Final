#ifndef ALDEANO_H
#define ALDEANO_H
#include <iostream>
#include <iomanip>

using namespace std;

class Aldeano{
    public:
        Aldeano ();
        Aldeano (const string &nombre, size_t edad, const string &genero, float salud);

        void setNombre (const string &value);
        string getNombre ();
        void setEdad (size_t value);
        size_t getEdad () const;
        void setGenero (const string &value);
        string getGenero ();
        void setSalud (float value);
        float getSalud () const;

        friend ostream& operator << (ostream &out, const Aldeano &a){
            out << left;
            out << setw(20) << a.nombre;
            out << setw(20) << a.edad;
            out << setw(25) << a.genero;
            out << setw(30) << a.salud;

            return out;
        }

        friend istream& operator >> (istream &in, Aldeano &a){
            cout << "Nombre del Aldeano: ";
            fflush (stdin);
            getline (cin, a.nombre);

            cout << "Edad: ";
            cin >> a.edad;

            cout << "Genero: ";
            fflush (stdin);
            getline (cin, a.genero);

            cout << "Salud: ";
            cin >> a.salud;

            return in;
        }

        bool operator < (const Aldeano &a){
            return nombre < a.nombre;
        }

        bool operator < (const Aldeano &a) const{
            return nombre < a.nombre;
        }

    private:
        string nombre;
        size_t edad;
        string genero;
        float salud;
};

#endif