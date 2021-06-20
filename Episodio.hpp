//
//  Episodio.hpp
//  Proyecto_Integrador_A01570656
//
//  Created by Adrian Martin Hernandez  on 18/05/21.
//

#ifndef Episodio_hpp
#define Episodio_hpp

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;


class Episodio{
    
private:
    //atributos
    string titulo;
    int temporada;
    double calificacion;
    
    
public:
    //constructores
    Episodio();
    Episodio(string _titulo,int _temporada,double _calificacion);
    
    //setters
    void setTitulo(string _titulo);
    void setTemporada(int _temporada);
    void setCalificacion(double _calificacion);
    
    
    //getters
    string getTitulo();
    int getTemporada();
    double getCalificacion();
    
    //str()
    string str() const;
    
    
    double operator+ (double dPuntuacion){
        return calificacion + dPuntuacion;
    }
    
    //sobrecarga del operador << como función amiga para acceder a los atributos de la clase
    friend std::ostream& operator << (std::ostream &out, const Episodio &episodio);

    
};

Episodio::Episodio(){
    titulo = "sin titulo";
}
Episodio::Episodio(string _titulo,int _temporada,double _calificacion){
    titulo = _titulo;
    temporada = _temporada;
    calificacion = _calificacion;
}

//setters
void Episodio::setTitulo(string _titulo){
    titulo = _titulo;
}
void Episodio::setTemporada(int _temporada){
    temporada = _temporada;
}
void Episodio::setCalificacion(double _calificacion){
    calificacion = _calificacion;
}

//getters
string Episodio::getTitulo(){
    return titulo;
}
int Episodio::getTemporada(){
    return temporada;
}
double Episodio::getCalificacion(){
    return calificacion;
}

//str()
string Episodio::str() const{
    return "E" + titulo + ',' +  to_string(temporada) + ',' + to_string(calificacion);
}


//sobrecarga del operador << como función amiga para acceder a los atributos de la clase
std::ostream& operator << (std::ostream &out, const Episodio &episodio){
    
    out << "E" + episodio.titulo   << ',' << to_string(episodio.temporada) << ',' << to_string(episodio.calificacion);
    
    return out;
}





#endif /* Episodio_hpp */
