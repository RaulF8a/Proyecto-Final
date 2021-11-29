#ifndef GUERRERO_H
#define GUERRERO_H
#include <iostream>
#include <iomanip>

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

        friend ostream& operator << (ostream &out, Guerrero &g){
            out << left;
            out << setw(20) << g.id;
            out << setw(20) << g.salud;
            out << setw(20) << g.fuerza;
            out << setw(20) << g.escudo;
            out << setw(20) << g.tipo;

            return out;
        }

        friend istream& operator >> (istream &in, Guerrero &g){
            int opcion;
            bool bandera = true;

            cout << "ID del Guerrero: ";
            fflush (stdin);
            getline (cin, g.id);

            do{
                cout << "Salud (0-100): ";
                cin >> g.salud;

                if (g.salud < 0 or g.salud > 100){
                    cout << "\nValor no valido." << endl;
                    system ("pause");
                    system ("cls");
                }
                else{
                    break;
                }
            }while (1);

            do{
                cout << "Fuerza (0-60): ";
                cin >> g.fuerza;

                if (g.fuerza < 0 or g.fuerza > 60){
                    cout << "\nValor no valido." << endl;
                    system ("pause");
                    system ("cls");
                }
                else{
                    break;
                }
            }while (1);

            do{
                cout << "Escudo (0-30): ";
                cin >> g.escudo;

                if (g.escudo < 0 or g.escudo > 30){
                    cout << "\nValor no valido." << endl;
                    system ("pause");
                    system ("cls");
                }
                else{
                    break;
                }
            }while (1);

            do{
                system ("cls");
                cout << "\t\tTipo de Guerrero\n" << endl;
                cout << "1. Tropa Terrestre." << endl;
                cout << "2. Tropa Aerea." << endl;
                cout << "3. Tanque." << endl;
                cout << "4. Apoyo." << endl;

                cout << "\nOpcion: ";
                cin >> opcion;

                switch (opcion){
                    case 1:
                        g.tipo = "Tropa Terrestre";
                        bandera = false;
                        break;
                    case 2:
                        g.tipo = "Tropa Aerea";
                        bandera = false;
                        break;
                    case 3:
                        g.tipo = "Tanque";
                        bandera = false;
                        break;
                    case 4:
                        g.tipo = "Apoyo";
                        bandera = false;
                        break;
                    default:
                        cout << "\nOpcion no valida." << endl;
                        system ("pause");
                }
            }while (bandera);

            return in;
        }

    private:
        string id;
        size_t salud;
        float fuerza;
        float escudo;
        string tipo;
};

#endif