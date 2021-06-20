//
//  Pelicula.hpp
//  Proyecto_Integrador_A01570656
//
//  Created by Adrian Martin Hernandez  on 18/05/21.
//

#ifndef Pelicula_hpp
#define Pelicula_hpp

#include "Video.hpp"
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;


class Pelicula : public Video {
    
private:
    //atributo
    int oscares;
    
    
public:
    //constructores
    Pelicula();
    Pelicula(string _iD,string _titulo,int _duracion,string _genero,double _calificacionPromedio,int _oscares);
    
    //setters
    void setOscares(int _oscares);
    
    
    //getters
    int getOscares()const;
    
    //str()
    string str();
    
    
    
};

//sobrecarga del operador << para acceder a los atributos de la clase pero no como función amiga
//por no ser función amiga tiene que mencionarse su firma fuera de la clase
std::ostream& operator<<(std::ostream &out, const Pelicula &pelicula);


//constructores
Pelicula::Pelicula(){
    oscares = 0;
}
Pelicula::Pelicula(string _iD,string _titulo,int _duracion,string _genero,double _calificacionPromedio,int _oscares):Video(_iD, _titulo, _duracion, _genero, _calificacionPromedio){
    
    oscares = _oscares;
    
}

//setters
void Pelicula::setOscares(int _oscares){
    oscares = _oscares;
    
    calificacionPromedio = oscares * 0.5;
}


//getters
int Pelicula::getOscares() const{
    return oscares;
}

//str()
string Pelicula::str(){
    
    return "P" + Video::str() + ',' +  to_string(oscares);
}


//sobrecarga del operador << para acceder a los atributos de la clase pero no como función amiga por lo que se necestan getters para accesar a los atributos
std::ostream& operator<<(std::ostream &out, const Pelicula &pelicula){
    out << "P"  + pelicula.getId() + ',' + pelicula.getTitulo() + ',' + to_string(pelicula.getDuracion()) + ',' + pelicula.getGenero() + ',' +to_string(pelicula.getCalificacion()) + ',' + to_string(pelicula.getOscares());
    return out;
}




#endif /* Pelicula_hpp */
