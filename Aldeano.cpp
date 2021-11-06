#include "Aldeano.h"

Aldeano::Aldeano (){

}

void Aldeano::setNombre (const string &value){
    nombre = value;
}

string Aldeano::getNombre (){
    return nombre;
}

void Aldeano::setEdad (int value){
    edad = value;
}

int Aldeano::getEdad (){
    return edad;
}

void Aldeano::setGenero (const string &value){
    genero = value;
}

string Aldeano::getGenero (){
    return genero;
}

void Aldeano::setSalud (float value){
    salud = value;
}

float Aldeano::getSalud (){
    return salud;
}