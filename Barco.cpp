#include "Barco.h"

Barco::Barco (){

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