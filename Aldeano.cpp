#include "Aldeano.h"

Aldeano::Aldeano (){

}

Aldeano::Aldeano (const string &nombre, size_t edad, const string &genero, float salud){
    this->nombre = nombre;
    this->edad = edad;
    this->genero = genero;
    this->salud = salud;
}

void Aldeano::setNombre (const string &value){
    nombre = value;
}

string Aldeano::getNombre (){
    return nombre;
}

void Aldeano::setEdad (size_t value){
    edad = value;
}

size_t Aldeano::getEdad () const{
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

float Aldeano::getSalud () const{
    return salud;
}