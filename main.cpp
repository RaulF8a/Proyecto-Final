#include <iostream>
#include <stdlib.h>
#include "VideoGame.h"
#include "MenuCivilizacion.h"

using namespace std;

enum Opciones{
    OPC_SALIR,
    OPC_NOMBRE_USUARIO,
    OPC_AGREGAR,
    OPC_INSERTAR,
    OPC_CREAR,
    OPC_PRIMERA,
    OPC_ULTIMA,
    OPC_ORDENAR,
    OPC_ELIMINAR,
    OPC_BUSCAR,
    OPC_MODIFICAR,
    OPC_RESUMEN
};

void menu ();

int main (){
    
    menu ();

    system ("pause");
    return 0;
}

void menu (){
    VideoGame videojuego;
    Civilizacion auxCivilizacion;
    string auxString;
    size_t posicion;
    int opcion, opcionOrdenar, opcionModificar, auxInt;
    bool banderaOrdenar, banderaModificar;
    float auxFloat;

    do{
        system ("cls");
        
        cout << "\t\tMenu Principal\n" << endl;

        cout << OPC_NOMBRE_USUARIO << ". Nombre de Usuario." << endl;
        cout << OPC_AGREGAR << ". Agregar Civilizacion." << endl;
        cout << OPC_INSERTAR << ". Insertar Civilizacion en una Posicion." << endl;
        cout << OPC_CREAR << ". Crear Civilizaciones." << endl;
        cout << OPC_PRIMERA << ". Mostrar Primera Civilizacion del Vector." << endl;
        cout << OPC_ULTIMA << ". Mostrar Ultima Civilizacion del Vector." << endl;
        cout << OPC_ORDENAR << ". Ordenar Civilizaciones." << endl;
        cout << OPC_ELIMINAR << ". Eliminar Civilizacion." << endl;
        cout << OPC_BUSCAR << ". Buscar Civilizacion." << endl;
        cout << OPC_MODIFICAR << ". Modificar Civilizacion." << endl;
        cout << OPC_RESUMEN << ". Resumen de las Civilizaciones." << endl;
        cout << OPC_SALIR << ". Salir." << endl;

        cout << "\nOpcion: ";
        cin >> opcion;

        switch (opcion){
            case OPC_NOMBRE_USUARIO:
                system ("cls");
                cout << "\t\tNombre de Usuario\n" << endl;

                cout << "Digita tu nombre de usuario: ";
                fflush (stdin);
                getline (cin, auxString);

                videojuego.setNombreUsuario (auxString);

                cout << "\nNombre registrado con exito." << endl;

                system ("pause");
                break;
            case OPC_AGREGAR:
                system ("cls");
                cout << "\t\tAgregar Civilizacion\n" << endl;

                cin >> auxCivilizacion;
                videojuego.agregarCivilizacion (auxCivilizacion);
                fflush (stdin);

                cout << "\nCivilizacion agregada con exito." << endl;

                system ("pause");
                break;
            case OPC_INSERTAR:
                system ("cls");
                cout << "\t\tInsertar Civilizacion\n" << endl;

                cout << "Digita la posicion donde se va a insertar: ";
                cin >> posicion;

                if (posicion >= videojuego.totalCivilizaciones()){
                    cout << "\nPosicion no valida." << endl;
                }
                else{
                    cout << endl;

                    cin >> auxCivilizacion;

                    videojuego.insertarCivilizacion (auxCivilizacion, posicion);
                    cout << "\nCivilizacion insertada con exito." << endl;
                }

                system ("pause");
                break;
            case OPC_CREAR:
                system ("cls");
                cout << "\t\tCrear Civilizaciones\n" << endl;

                cin >> auxCivilizacion;

                cout << "Digita la cantidad de veces a inicializar: ";
                cin >> posicion;

                videojuego.inicializarCivilizaciones (auxCivilizacion, posicion);

                cout << "\nVector inicializado con exito." << endl;
                system ("pause");
                break;
            case OPC_PRIMERA:
                system ("cls");
                cout << "\t\tPrimera Civilizacion\n" << endl;

                if (videojuego.totalCivilizaciones () > 0){
                    cout << left;
                    cout << setw (20) << "Nombre";
                    cout << setw (20) << "Posicion en X";
                    cout << setw (25) << "Posicion en Y";
                    cout << setw (30) << "Puntuacion";
                    cout << endl;

                    cout << videojuego.primeraCivilizacion () << endl;
                }
                else{
                    cout << "Aun no se agrega ninguna civilizacion." << endl;
                }

                cout << endl;
                system ("pause");
                break;
            case OPC_ULTIMA:
                system ("cls");
                cout << "\t\tUltima Civilizacion\n" << endl;

                if (videojuego.totalCivilizaciones () > 0){
                    cout << left;
                    cout << setw (20) << "Nombre";
                    cout << setw (20) << "Posicion en X";
                    cout << setw (25) << "Posicion en Y";
                    cout << setw (30) << "Puntuacion";
                    cout << endl;

                    cout << videojuego.ultimaCivilizacion () << endl;
                }
                else{
                    cout << "Aun no se agrega ninguna civilizacion." << endl;
                }

                cout << endl;
                system ("pause");
                break;
            case OPC_ORDENAR:
                banderaOrdenar = true;

                do{
                    system ("cls");

                    cout << "\t\tMenu de Ordenamientos\n" << endl;

                    cout << "1. Ordenar por Nombre." << endl;
                    cout << "2. Ordenar por Posicion en X." << endl;
                    cout << "3. Ordenar por posicion en Y." << endl;
                    cout << "4. Ordenar por Puntuacion." << endl;
                    cout << "0. Salir." << endl;

                    cout << "\nOpcion: ";
                    cin >> opcionOrdenar;

                    switch (opcionOrdenar){
                        case 1:
                            videojuego.ordenarNombre ();
                            cout << "\nCivilizaciones ordenadas de acuerdo al nombre." << endl;
                            banderaOrdenar = false;
                            break;
                        case 2:
                            videojuego.ordenarX ();
                            cout << "\nCivilizaciones ordenadas de acuerdo a su posicion en X." << endl;
                            banderaOrdenar = false;
                            break;
                        case 3:
                            videojuego.ordenarY ();
                            cout << "\nCivilizaciones ordenadas de acuerdo a su posicion en Y." << endl;
                            banderaOrdenar = false;
                            break;
                        case 4:
                            videojuego.ordenarPuntuacion ();
                            cout << "\nCivilizaciones ordenadas de acuerdo a su puntuacion." << endl;
                            banderaOrdenar = false;
                            break;
                        case 0:
                            banderaOrdenar = false;
                            break;
                        default:
                            cout << "\nOpcion no valida." << endl;
                            system ("pause");
                    }
                }while (banderaOrdenar);

                system ("pause");
                break;
            case OPC_ELIMINAR:
                system ("cls");
                cout << "\t\tEliminar Civilizacion\n" << endl;

                cout << "Digita el nombre de la civilizacion a eliminar: ";
                fflush (stdin);
                getline (cin, auxString);

                if (videojuego.compararNombre (auxString) != videojuego.totalCivilizaciones ()){
                    videojuego.eliminarCivilizacion (auxString);
                    cout << "\nCivilizacion eliminada con extio." << endl;
                }
                else{
                    cout << "\nNo se encontro la civilizacion." << endl;
                }

                system ("pause");
                break;
            case OPC_BUSCAR:
                system ("cls");
                cout << "\t\tBuscar Civilizacion\n" << endl;

                cout << "Digita el nombre de la civilizacion a buscar: ";
                fflush (stdin);
                getline (cin, auxString);

                if (videojuego.buscarCivilizacion (auxString) == nullptr){
                    cout << "\nNo se encontro la civilizacion." << endl;
                }
                else{
                    cout << "\nSe encontro el elemento: " << endl;
                    cout << left;
                    cout << setw (20) << "Nombre";
                    cout << setw (20) << "Posicion en X";
                    cout << setw (25) << "Posicion en Y";
                    cout << setw (30) << "Puntuacion";
                    cout << endl;
                    cout << *videojuego.buscarCivilizacion (auxString);

                    cout << "\n" << endl;
                    system ("pause");

                    menuCivilizacion (*videojuego.buscarCivilizacion (auxString));
                }

                system ("pause");
                break;
            case OPC_MODIFICAR:
                system ("cls");
                cout << "\t\tModificar Civilizacion\n" << endl;

                cout << "Digita el nombre de la civilizacion: ";
                fflush (stdin);
                getline (cin, auxString);

                if (videojuego.compararNombre (auxString) != videojuego.totalCivilizaciones ()){
                    posicion = videojuego.compararNombre (auxString);

                    cout << left;
                    cout << setw (20) << "Nombre";
                    cout << setw (20) << "Posicion en X";
                    cout << setw (25) << "Posicion en Y";
                    cout << setw (30) << "Puntuacion";
                    cout << endl;
                    cout << *videojuego.buscarCivilizacion (auxString) << "\n" << endl;
                    system ("pause");

                    banderaModificar = true;

                    do{
                        system ("cls");
                        cout << "\t\tMenu de Modificaciones\n" << endl;
                        cout << "1. Modificar Nombre." << endl;
                        cout << "2. Modificar Posicion en X." << endl;
                        cout << "3. Modificar Posicion en Y." << endl;
                        cout << "4. Modificar Puntuacion." << endl;
                        cout << "0. Salir." << endl;

                        cout << "\nOpcion: ";
                        cin >> opcionModificar;

                        switch (opcionModificar){
                            case 1:
                                system ("cls");

                                cout << "\nDigita el nuevo nombre: ";
                                fflush (stdin);
                                getline (cin, auxString);

                                videojuego.modificarNombre (posicion, auxString);

                                cout << "\nNombre modificado con exito." << endl;
                                banderaModificar = false;
                                break;
                            case 2:
                                system ("cls");

                                cout << "\nDigita la nueva posicion en X: ";
                                cin >> auxInt;

                                videojuego.modificarPosicionX (posicion, auxInt);

                                cout << "\nPosicion en X modificada con exito." << endl;
                                banderaModificar = false;
                                break;
                            case 3:
                                system ("cls");

                                cout << "\nDigita la nueva posicion en Y: ";
                                cin >> auxInt;

                                videojuego.modificarPosicionY (posicion, auxInt);

                                cout << "\nPosicion en Y modificada con exito." << endl;
                                banderaModificar = false;
                                break;
                            case 4:
                                system ("cls");

                                cout << "\nDigita la nueva puntuacion: ";
                                cin >> auxFloat;

                                videojuego.modificarPuntuacion (posicion, auxFloat);

                                cout << "\nPuntuacion modificada con exito." << endl;
                                banderaModificar = false;
                                break;
                            case 0:
                                banderaModificar = false;
                                break;
                            default:
                                cout << "Opcion no valida." << endl;
                                system ("pause");
                        }
                    }while (banderaModificar);
                }
                else{
                    cout << "\nNo se encontro la civilizacion." << endl;
                }

                system ("pause");
                break;
            case OPC_RESUMEN:
                system ("cls");
                cout << "\t\tResumen de Civilizaciones\n" << endl;

                videojuego.mostrarCivilizaciones ();

                cout << endl;
                system ("pause");
                break;
            case OPC_SALIR:
                system ("cls");
                cout << "De acuerdo, nos vemos." << endl;
                break;
            default:
                cout << "\nOpcion no valida." << endl;
                system ("pause");
        }

    }while (opcion != OPC_SALIR);
}
