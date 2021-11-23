#include "Barco.h"

Barco::Barco (){
    id = "";
    combustible = 0.0;
    velocidad = 0.0;
    armadura = 0.0;
}

void Barco::setID (const string &value){
    id = value;
}

string Barco::getID (){
    return id;
}

void Barco::setCombustible (float value){
    combustible = value;
}

float Barco::getCombustible (){
    return combustible;
}

void Barco::setVelocidad (float value){
    velocidad = value;
}

float Barco::getVelocidad (){
    return velocidad;
}

void Barco::setArmadura (float value){
    armadura = value;
}

float Barco::getArmadura (){
    return armadura;
}

size_t Barco::sizeGuerreros (){
    return guerreros.size ();
}

void Barco::agregarGuerrero (const Guerrero &value){
    guerreros.push (value);
}

void Barco::eliminarGuerrero (){
    guerreros.pop ();
}

void Barco::topeGuerrero (){
    cout << left;
    cout << setw(20) << "ID del Guerrero";
    cout << setw(20) << "Salud";
    cout << setw(20) << "Fuerza";
    cout << setw(20) << "Escudo";
    cout << setw(20) << "Tipo";
    cout << endl;

    cout << guerreros.top () << endl;
}

void Barco::mostrarGuerreros (){
    stack<Guerrero> copiaGuerreros (guerreros);

    cout << left;
    cout << setw(20) << "ID del Guerrero";
    cout << setw(20) << "Salud";
    cout << setw(20) << "Fuerza";
    cout << setw(20) << "Escudo";
    cout << setw(20) << "Tipo";
    cout << endl;

    while (!copiaGuerreros.empty ()){
        Guerrero g = copiaGuerreros.top ();

        cout << g << endl;

        copiaGuerreros.pop ();
    }
}

bool Barco::guerrerosEmpty (){
    return guerreros.empty ();
}