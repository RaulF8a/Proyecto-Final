#include "Civilizacion.h"
#include "Barco.h"

Guerrero registrarGuerrero (){
    Guerrero guerrero;
    
    cin >> guerrero;

    return guerrero;
}

void menuPuerto (Civilizacion &c){
    int opcionMenu, opcionGuerrero, opcionEliminar;
    bool banderaEliminar = true, banderaCombustible = true;
    size_t auxT;
    float auxF;
    string auxS;
    Barco *b;
    Barco *auxBarco;

    do{
        system ("cls");

        cout << "\t\tMenu del Puerto\n" << endl;

        cout << "1. Agregar Barco." << endl;
        cout << "2. Mostrar Todos los Barcos." << endl;
        cout << "3. Buscar Barco." << endl;
        cout << "4. Eliminar Barco." << endl;
        cout << "0. Salir." << endl;

        cout << "\nOpcion: ";
        cin >> opcionMenu;

        switch (opcionMenu){
            case 1:
                b = new Barco ();

                system ("cls");
                cout << "\t\tAgregar Barco\n" << endl;
        
                cout << "Digita el ID del barco: ";
                fflush (stdin);
                getline (cin, auxS);
                b->setID (auxS);

                do{
                    fflush (stdin);

                    cout << "Combustible (0-100): ";
                    cin >> auxF;

                    if (auxF < 0 or auxF > 100){
                        cout << "\nValor no valido." << endl;
                        system ("pause");
                        system ("cls");
                    }
                    else{
                        banderaCombustible = false;
                    }

                }while(banderaCombustible);

                b->setCombustible (auxF);

                c.agregarBarco (b);

                cout << "\nBarco agregado con exito." << endl;

                system ("pause");
                break;
            case 2:
                system ("cls");
                cout << "\t\tMostrar Todos los Barcos\n" << endl;

                c.mostrarBarcos ();

                cout << endl;
                system ("pause");
                break;
            case 3:
                system ("cls");
                cout << "\t\tBuscar Barco\n" << endl;

                cout << "Digita el ID del barco: ";
                fflush (stdin);
                getline (cin, auxS);

                auxBarco = c.buscarBarco (auxS);

                if (auxBarco != nullptr){
                    cout << "\nSe encontro el barco" << endl;
                    system ("pause");

                    do{
                        system ("cls");
                        cout << "\t\tMenu de Guerreros\n" << endl;

                        cout << "1. Agregar Guerrero." << endl;
                        cout << "2. Eliminar Guerrero." << endl;
                        cout << "3. Mostrar al Ultimo Guerrero Agregado." << endl;
                        cout << "4. Mostrar a Todos los Guerreros." << endl;
                        cout << "0. Salir." << endl;

                        cout <<"\nOpcion: ";
                        cin >> opcionGuerrero;

                        switch (opcionGuerrero){
                            case 1:
                                system ("cls");
                                cout << "\t\tAgregar Guerrero\n" << endl;

                                auxBarco->agregarGuerrero(registrarGuerrero ());

                                cout << "\nGuerrero agregado con exito." << endl;

                                system ("pause");
                                break;
                            case 2:
                                system ("cls");
                                cout << "\t\tEliminar Guerrero\n" << endl;

                                if (auxBarco->guerrerosEmpty()){
                                    cout << "No has agregado ningun guerrero.\n" << endl;
                                }
                                else{
                                    auxBarco->eliminarGuerrero ();

                                    cout << "Guerrero al tope eliminado con exito.\n" << endl;
                                }

                                system ("pause");
                                break;
                            case 3:
                                system ("cls");
                                cout << "\t\tMostrar al Ultimo Guerrero Agregado\n" << endl;

                                auxBarco->topeGuerrero ();

                                cout << endl;
                                system ("pause");
                                break;
                            case 4:
                                system ("cls");
                                cout << "\t\tMostrar a todos los Guerreros\n" << endl;

                                auxBarco->mostrarGuerreros ();
                                
                                cout << endl;
                                system ("pause");
                                break;
                            case 0:
                                break;
                            default:
                                cout << "\nOpcion no valida." << endl;
                                system ("pause");
                        }

                    }while (opcionGuerrero != 0);
                }
                else{
                    cout << "\nNo se encontro el barco." << endl;
                    system ("pause");
                }

                break;
            case 4:
                do{
                    system ("cls");
                    cout << "\t\tEliminar Barco\n" << endl;

                    cout << "1. Eliminar por ID." << endl;
                    cout << "2. Eliminar por combustible menor a X." << endl;

                    cout << "\nOpcion: ";
                    cin >> opcionEliminar;

                    switch (opcionEliminar){
                        case 1:
                            system ("cls");
                            cout << "\nDigita el ID del barco: ";
                            fflush (stdin);
                            getline (cin, auxS);

                            auxBarco = c.buscarBarco (auxS);

                            if (auxBarco != nullptr){
                                c.eliminarID (auxS);
                                cout << "\nBarco eliminado con exito." << endl;
                                banderaEliminar = false;
                            }
                            else{
                                cout << "\nNo se encontro el barco." << endl;
                            }

                            system ("pause");
                            break;
                        case 2:
                            system ("cls");
                            cout << "\nDigita el valor de X: ";
                            cin >> auxF;

                            c.eliminarCombustible (auxF);

                            cout << "\nBarcos eliminados con exito." << endl;

                            banderaEliminar = false;
                            system ("pause");
                            break;
                        case 0:
                            break;
                        default:
                            cout << "\nOpcion no valida." << endl;
                            system ("pause");
                    }

                }while (banderaEliminar);

                break;
            case 0:
                break;
            default:
                cout << "\nOpcion no valida." << endl;
                system ("pause");
        }

    }while (opcionMenu != 0);
}