#include "Guerrero.h"

Guerrero::Guerrero (){
    
}

void Guerrero::setID (const string &value){
    id = value;
}

string Guerrero::getID (){
    return id;
}

void Guerrero::setSalud (size_t value){
    salud = value;
}

size_t Guerrero::getSalud (){
    return salud;
}

void Guerrero::setFuerza (float value){
    fuerza = value;
}

float Guerrero::getFuerza (){
    return fuerza;
}

void Guerrero::setEscudo (float value){
    escudo = value;
}

float Guerrero::getEscudo (){
    return escudo;
}

void Guerrero::setTipo (const string &value){
    tipo = value;
}

string Guerrero::getTipo (){
    return tipo;
}