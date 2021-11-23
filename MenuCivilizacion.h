#include "Civilizacion.h"
#include "MenuPuerto.h"

Aldeano capturarAldeano (){
    Aldeano aldeano;

    cin >> aldeano;

    return aldeano;
}

void menuCivilizacion (Civilizacion &c){
    int opcionAldeano, opcionAgregarAldeano, opcionEliminarAldeano, opcionOrdenarAldeano, opcionModificarAldeano, auxInt;
    float auxFloat;
    bool banderaAgregar, banderaEliminar, banderaOrdenar, banderaModificar;
    size_t auxT;
    Aldeano auxAldeano;
    Aldeano* auxAldeanoPTR;
    string auxString;

     do{
        system ("cls");

        cout << "\t\tMenu de Aldeanos\n" << endl;
        cout << "1. Agregar Aldeano." << endl;
        cout << "2. Eliminar Aldeano." << endl;
        cout << "3. Clasificar Aldeanos." << endl; 
        cout << "4. Buscar Aldeano." << endl;
        cout << "5. Modificar Aldeano." << endl;
        cout << "6. Mostrar Todos los Aldeanos." << endl;
        cout << "7. Visitar Puerto." << endl;
        cout << "0. Salir." << endl;

        cout << "\nOpcion: ";
        cin >> opcionAldeano;

        switch (opcionAldeano){
            case 1:
                banderaAgregar = true;

                do{
                    system ("cls");
                    cout << "\t\tAgregar Aldeano\n" << endl;
                    
                    cout << "1. Agregar Aldeano al Inicio." << endl;
                    cout << "2. Agregar Aldeano al Final." << endl;
                    cout << "0. Salir." << endl;

                    cout << "\nOpcion: ";
                    cin >> opcionAgregarAldeano;

                    switch (opcionAgregarAldeano){
                        case 1:
                            system ("cls");
                            
                            cout << endl;
                            c.agregarInicio (capturarAldeano());
                            c.setPuntuacion (c.getPuntuacion () + 100);

                            cout << "\nAldeano agregado al inicio con exito." << endl;

                            banderaAgregar = false;
                            system ("pause");
                            break;
                        case 2:
                            system ("cls");

                            cout << endl;
                            c.agregarFinal (capturarAldeano());
                            c.setPuntuacion (c.getPuntuacion () + 100);

                            cout << "\nAldeano agregado al final con exito." << endl;

                            banderaAgregar = false;
                            system ("pause");
                            break;
                        case 0:
                            banderaAgregar = false;
                            break;
                        default:
                            cout << "\nOpcion no valida." << endl;
                            system ("pause");
                    }
                }while (banderaAgregar);
                break;
            case 2:
                banderaEliminar = true;

                do{
                    system ("cls");
                    cout << "\t\tEliminar Aldeano\n" << endl;
                    
                    cout << "1. Eliminar por Nombre." << endl;
                    cout << "2. Eliminar por Salud Menor a X." << endl;
                    cout << "3. Eliminar por Edad Mayor a 60." << endl;
                    cout << "0. Salir." << endl;

                    cout << "\nOpcion: ";
                    cin >> opcionEliminarAldeano;

                    switch (opcionEliminarAldeano){
                        case 1:
                            system ("cls");

                            cout << "\nDigita el nombre del aldeano: ";
                            fflush (stdin);
                            getline (cin, auxString);

                            if (c.buscarAldeano (auxString) != nullptr){
                                c.eliminarNombre (auxString);
                                cout << "\nAldeano eliminado con exito." << endl;

                                banderaEliminar = false;
                            }
                            else{
                                cout << "\nNo se encontro al aldeano." << endl;
                            }

                            system ("pause");
                            break;
                        case 2:
                            system ("cls");

                            cout << "\nDigita el valor de X: ";
                            cin >> auxT;

                            c.eliminarSalud (auxT);

                            cout << "\nElementos eliminados con exito." << endl;

                            banderaEliminar = false;
                            system ("pause");
                            break;
                        case 3:
                            system ("cls");

                            c.eliminarEdad ();

                            banderaEliminar = false;
                            cout << "\nElementos eliminados con exito." << endl;
                            system ("pause");
                            break;
                        case 0:
                            banderaEliminar = false;
                            break;
                        default:
                            cout << "\nOpcion no valida." << endl;
                            system ("pause"); 
                    }
                }while (banderaEliminar);
                break;
            case 3:
                banderaOrdenar = true;

                do{
                    system ("cls");
                    cout << "\t\tOrdenar Aldeanos\n" << endl;
                    
                    cout << "1. Ordenar por Nombre." << endl;
                    cout << "2. Ordenar por Edad." << endl;
                    cout << "3. Ordenar por Salud." << endl;
                    cout << "0. Salir." << endl;

                    cout << "\nOpcion: ";
                    cin >> opcionOrdenarAldeano;

                    switch (opcionOrdenarAldeano){
                        case 1:
                            system ("cls");

                            c.ordenarNombre ();

                            cout << "\nAldeanos ordenados por nombre con exito." << endl;

                            banderaOrdenar = false;
                            system ("pause");
                            break;
                        case 2:
                            system ("cls");

                            c.ordenarEdad ();

                            cout << "\nAldeanos ordenados por edad con exito." << endl;
                            
                            banderaOrdenar = false;
                            system ("pause");
                            break;
                        case 3:
                            system ("cls");

                            c.ordenarSalud ();

                            cout << "\nAldeanos ordenados por salud con exito." << endl;
                            
                            banderaOrdenar = false;
                            system ("pause");
                            break;
                        case 0:
                            banderaOrdenar = false;
                            break;
                        default:
                            cout << "\nOpcion no valida." << endl;
                            system ("pause");
                    }
                }while (banderaOrdenar);
                break;
            case 4:
                system ("cls");

                cout << "\nDigita el nombre del aldeano: ";
                fflush (stdin);
                getline (cin, auxString);

                auxAldeanoPTR = c.buscarAldeano (auxString);

                if (auxAldeanoPTR != nullptr){
                    cout << "\nSe encontro al aldeano.\n" << endl;
                    cout << left;
                    cout << setw (20) << "Nombre";
                    cout << setw (20) << "Edad";
                    cout << setw (25) << "Genero";
                    cout << setw (30) << "Salud";
                    cout << endl;
                    cout << *auxAldeanoPTR;

                    cout << "\n" << endl;
                }
                else{
                    cout << "\nNo se encontro al aldeano." << endl;
                }

                system ("pause");
                break;
            case 5:
                banderaModificar = true;

                system ("cls");
                cout << "\t\tModificar Aldeano\n" << endl;

                cout << "Digita el nombre del aldeano: ";
                fflush (stdin);
                getline (cin, auxString);

                auxAldeanoPTR = c.buscarAldeano (auxString);

                if (auxAldeanoPTR != nullptr){
                    cout << endl;
                    cout << left;
                    cout << setw (20) << "Nombre";
                    cout << setw (20) << "Edad";
                    cout << setw (25) << "Genero";
                    cout << setw (30) << "Salud";
                    cout << endl;
                    cout << *auxAldeanoPTR;
                    cout << endl;
                    system ("pause");

                    do{
                        system ("cls");
                        cout << "\t\tMenu de Modificaciones\n" << endl;
                        cout << "1. Modificar Nombre." << endl;
                        cout << "2. Modificar Edad." << endl;
                        cout << "3. Modificar Genero." << endl;
                        cout << "4. Modificar Salud." << endl;
                        cout << "0. Salir." << endl;

                        cout << "\nOpcion: ";
                        cin >> opcionModificarAldeano;

                        switch (opcionModificarAldeano){
                            case 1:
                                system ("cls");

                                cout << "\nDigita el nuevo nombre: ";
                                fflush (stdin);
                                getline (cin, auxString);

                                c.modificarNombre (*auxAldeanoPTR, auxString);

                                cout << "\nNombre modificado con exito." << endl;
                                banderaModificar = false;
                                system ("pause");
                                break;
                            case 2:
                                system ("cls");

                                cout << "\nDigita la nueva edad: ";
                                cin >> auxT;

                                c.modificarEdad (*auxAldeanoPTR, auxT);

                                cout << "\nEdad modificada con exito." << endl;
                                banderaModificar = false;
                                system ("pause");
                                break;
                            case 3:
                                system ("cls");

                                cout << "\nDigita el nuevo genero: ";
                                fflush (stdin);
                                getline (cin, auxString);

                                c.modificarGenero (*auxAldeanoPTR, auxString);

                                cout << "\nGenero modificado con exito." << endl;
                                banderaModificar = false;
                                system ("pause");
                                break;
                            case 4:
                                system ("cls");

                                cout << "\nDigita la nueva salud: ";
                                cin >> auxFloat;

                                c.modificarSalud (*auxAldeanoPTR, auxFloat);

                                cout << "\nSalud modificada con exito." << endl;
                                banderaModificar = false;
                                system ("pause");
                                break;
                            case 0:
                                banderaModificar = false;
                                break;
                            default:
                                cout << "\nOpcion no valida." << endl;
                                system ("pause");
                        }
                    }while (banderaModificar);
                }
                else{
                    cout << "\nNo se encontro al aldeano." << endl;
                    system ("pause");
                }
                break;
            case 6:
                system ("cls");

                cout << "\t\tMostrar a Todos los Aldeanos\n" << endl;

                c.mostrarAldeanos ();

                cout << endl;
                system ("pause");
                break;
            case 7:
                menuPuerto (c);
                break;
            case 0:
                break;
            default:
                cout << "\nOpcion no valida." << endl;
                system ("pause");
        }
    }while (opcionAldeano != 0);
}
