#include "VideoGame.h"
#include <algorithm>

VideoGame::VideoGame(){

}

void VideoGame::setNombreUsuario (const string &value){
    nombreUsuario = value;
}

string VideoGame::getNombreUsuario (){
    return nombreUsuario;
}

void VideoGame::agregarCivilizacion (const Civilizacion &value){
    civilizaciones.push_back (value);
}

void VideoGame::insertarCivilizacion (const Civilizacion &value, size_t position){
    civilizaciones.insert(civilizaciones.begin() + position, value);
}

void VideoGame::inicializarCivilizaciones (const Civilizacion &value, size_t n){
    civilizaciones = vector <Civilizacion> (n, value);
}

Civilizacion VideoGame::primeraCivilizacion (){
    return civilizaciones.front();
}

Civilizacion VideoGame::ultimaCivilizacion (){
    return civilizaciones.back();
}

void VideoGame::ordenarNombre (){
    sort (civilizaciones.begin(), civilizaciones.end(), [](Civilizacion c1, Civilizacion c2){return c1.getNombre () < c2.getNombre ();});
}

void VideoGame::ordenarX (){
    sort (civilizaciones.begin(), civilizaciones.end(), [](Civilizacion c1, Civilizacion c2){return c1.getX () < c2.getX ();});
}

void VideoGame::ordenarY (){
    sort (civilizaciones.begin(), civilizaciones.end(), [](Civilizacion c1, Civilizacion c2){return c1.getY () < c2.getY ();});
}

void VideoGame::ordenarPuntuacion (){
    sort (civilizaciones.begin(), civilizaciones.end(), [](Civilizacion c1, Civilizacion c2){return c1.getPuntuacion () > c2.getPuntuacion ();});
}

void VideoGame::eliminarCivilizacion (const string &value){
    //Erase-Remove Idiom
    civilizaciones.erase (std::remove_if(civilizaciones.begin(), civilizaciones.end(), [&value](Civilizacion &v)->bool{return v.getNombre() == value;}), civilizaciones.end());
}

Civilizacion* VideoGame::buscarCivilizacion (const string &value){
    auto it = find_if(civilizaciones.begin(), civilizaciones.end(), [&value](Civilizacion &v){return v.getNombre() == value;});

    if (it == civilizaciones.end()){
        return nullptr;
    }
    else{
        return &(*it);
    }
}

size_t VideoGame::totalCivilizaciones (){
    return civilizaciones.size ();
}

size_t VideoGame::compararNombre (const string value){
    size_t posicion;

    for (size_t i = 0; i < totalCivilizaciones(); i++){
        if (civilizaciones[i].getNombre() == value){
            posicion = i;
            return posicion;
        }
    }

    return totalCivilizaciones ();
}

void VideoGame::modificarNombre (size_t position, const string &nombre){
    civilizaciones[position].setNombre (nombre);
}

void VideoGame::modificarPosicionX (size_t position, int posX){
    civilizaciones[position].setX (posX);
}

void VideoGame::modificarPosicionY (size_t position, int posY){
    civilizaciones[position].setY (posY);
}

void VideoGame::modificarPuntuacion (size_t position, float puntuacion){
    civilizaciones[position].setPuntuacion (puntuacion);
}

void VideoGame::mostrarCivilizaciones (){
    cout << left;
    cout << setw (20) << "Nombre";
    cout << setw (20) << "Posicion en X";
    cout << setw (25) << "Posicion en Y";
    cout << setw (30) << "Puntuacion";
    cout << endl;

    for (size_t i = 0; i < totalCivilizaciones (); i++){
        Civilizacion &c = civilizaciones[i];

        cout << c;

        cout << endl;
    }
}