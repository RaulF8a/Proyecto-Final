#include "Civilizacion.h"

Civilizacion::Civilizacion (){

}

void Civilizacion::setNombre (const string &value){
    nombre = value;
}

string Civilizacion::getNombre (){
    return nombre;
}

void Civilizacion::setX (size_t value){
    x = value;
}

size_t Civilizacion::getX (){
    return x;
}

void Civilizacion::setY (size_t value){
    y = value;
}

size_t Civilizacion::getY (){
    return y;
}

void Civilizacion::setPuntuacion (float value){
    puntuacion = value;
}

float Civilizacion::getPuntuacion (){
    return puntuacion;
}