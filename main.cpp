#include <iostream>
#include <stdlib.h>
#include "VideoGame.h"

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
void agregarNombreUsuario ();
void agregarCivilizacion ();
void insertarCivilizacion ();
void crearCivilizaciones ();
void primeraCivilizacion ();
void ultimaCivilizacion ();
void ordenarCivilizaciones ();
void eliminarCivilizacion ();
void buscarCivilizacion ();
void modificarCivilizacion ();
void resumenCivilizaciones ();

int main (){
    
    menu ();

    system ("pause");
    return 0;
}

void menu (){
    VideoGame videojuego;
    int opcion;

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
                system ("pause");
                break;
            case OPC_AGREGAR:
                system ("cls");
                system ("pause");
                break;
            case OPC_INSERTAR:
                system ("cls");
                system ("pause");
                break;
            case OPC_CREAR:
                system ("cls");
                system ("pause");
                break;
            case OPC_PRIMERA:
                system ("cls");
                system ("pause");
                break;
            case OPC_ULTIMA:
                system ("cls");
                system ("pause");
                break;
            case OPC_ORDENAR:
                system ("cls");
                system ("pause");
                break;
            case OPC_ELIMINAR:
                system ("cls");
                system ("pause");
                break;
            case OPC_BUSCAR:
                system ("cls");
                system ("pause");
                break;
            case OPC_MODIFICAR:
                system ("cls");
                system ("pause");
                break;
            case OPC_RESUMEN:
                system ("cls");
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

void agregarNombreUsuario (){

}

void agregarCivilizacion (){

}

void insertarCivilizacion (){

}

void crearCivilizaciones (){

}

void primeraCivilizacion (){

}

void ultimaCivilizacion (){

}

void ordenarCivilizaciones (){

}

void eliminarCivilizacion (){

}

void buscarCivilizacion (){

}

void modificarCivilizacion (){

}

void resumenCivilizaciones (){
    
}