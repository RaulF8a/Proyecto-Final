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

void Civilizacion::agregarFinal (const Aldeano &value){
    aldeanos.push_back (value);
}

void Civilizacion::agregarInicio (const Aldeano &value){
    aldeanos.push_front (value);
}

void Civilizacion::mostrarAldeanos (){
    cout << left;
    cout << setw (20) << "Nombre";
    cout << setw (20) << "Edad";
    cout << setw (25) << "Genero";
    cout << setw (30) << "Salud";
    cout << endl;

    //Las listas no tienen sobrecargado el operador [] para acceder a cada elemento.
    //Como los elementos no estan guardados en posiciones de memoria consecutivas, tenemos que usar iteradores para ir saltando
    //entre cada nodo de la lista. Al sumarle uno a it, se dirije al siguiente nodo de la lista.
    for (auto it = aldeanos.begin (); it != aldeanos.end (); it++){
        //Como it es una direccion de memoria, tenemos que usar el operador * para imprimir el contenido.
        cout << *it << endl;
    }
}

void Civilizacion::eliminarNombre (const string &value){
    for (auto it = aldeanos.begin (); it != aldeanos.end (); it++){
        Aldeano &a = *it;

        if (a.getNombre () == value){
            aldeanos.erase (it);

            break;
        }
    }
}

void Civilizacion::eliminarSalud (size_t value){
    aldeanos.remove_if ([value](const Aldeano &a){return a.getSalud() < value;});
}

bool comparadorEdad (const Aldeano &a){
    return a.getEdad () >= 60;
}

void Civilizacion::eliminarEdad (){
    aldeanos.remove_if (comparadorEdad);
}

void Civilizacion::ordenarNombre (){
    aldeanos.sort ();
}

void Civilizacion::ordenarEdad (){
    aldeanos.sort ([](const Aldeano &a1, const Aldeano &a2){return a1.getEdad () > a2.getEdad ();});
}

void Civilizacion::ordenarSalud (){
    aldeanos.sort ([](const Aldeano &a1, const Aldeano &a2){return a1.getSalud () > a2.getSalud ();});
}

Aldeano* Civilizacion::buscarAldeano (const string &value){
    for (auto it = aldeanos.begin (); it != aldeanos.end (); it++){
        Aldeano &a = *it;

        if (a.getNombre () == value){
            return &a;
        }
    }

    return nullptr;
}

void Civilizacion::modificarNombre (Aldeano &value, const string &nuevoNombre){
    value.setNombre (nuevoNombre);
}

void Civilizacion::modificarEdad (Aldeano &value, size_t nuevaEdad){
    value.setEdad (nuevaEdad);
}

void Civilizacion::modificarGenero (Aldeano &value, const string &nuevoGenero){
    value.setGenero (nuevoGenero);
}

void Civilizacion::modificarSalud (Aldeano &value, float nuevaSalud){
    value.setSalud (nuevaSalud);
}

void Civilizacion::respaldarAldeanos (){
    ofstream archivo (getNombre() + ".txt", ios::out);

    for (auto it = aldeanos.begin (); it != aldeanos.end(); it++){
        Aldeano &a = *it;

        archivo << a.getNombre () << endl;
        archivo << a.getEdad () << endl;
        archivo << a.getGenero () << endl;
        archivo << a.getSalud () << endl;
    }

    archivo.close ();
}

void Civilizacion::recuperarAldeanos (Civilizacion &c){
    ifstream archivo (c.getNombre() + ".txt");

    string tempS;
    size_t tempT;
    float tempF;
    Aldeano a;

    while (true){
        getline (archivo, tempS);

        if (archivo.eof ()){
            break;
        }

        a.setNombre (tempS);

        getline (archivo, tempS);
        tempT = stoi (tempS);
        a.setEdad (tempT);

        getline (archivo, tempS);
        a.setGenero (tempS);

        getline (archivo, tempS);
        tempF = stof (tempS);
        a.setSalud (tempF);

        c.agregarFinal (a);
    }

    archivo.close ();
}

void Civilizacion::agregarBarco (Barco *value){
    puerto.push_back (value);
}

void Civilizacion::mostrarBarcos (){
    cout << left;
    cout << setw (20) << "ID";
    cout << setw (20) << "Combustible";
    cout << setw (25) << "Velocidad";
    cout << setw (20) << "Armadura";
    cout << setw (20) << "Numero de Guerreros";
    cout << endl;

    for (auto it = puerto.begin (); it != puerto.end (); it++){
        auto &barco = *it;

        cout << *barco << endl;
    }
}

Barco* Civilizacion::buscarBarco (const string &value){
    for (auto it = puerto.begin (); it != puerto.end (); it++){
        auto &barco = *it;

        if (barco->getID () == value){
            return barco;
        }
    }

    return nullptr;
}

void Civilizacion::eliminarID (const string &value){
    for (auto it = puerto.begin (); it != puerto.end (); it++){
        auto &barco = *it;

        if (barco->getID () == value){
            puerto.remove (barco);
            delete barco;
            break;
        }
    }
}

void Civilizacion::eliminarCombustible (float value){
    puerto.remove_if ([value](Barco *b){
        if (b->getCombustible() < value){
            delete b;
            return true;
        }
        else{
            return false;
        }});
}