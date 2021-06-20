//
//  Video.hpp
//  Proyecto_Integrador_A01570656
//
//  Created by Adrian Martin Hernandez  on 18/05/21.
//

#ifndef Video_hpp
#define Video_hpp

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;


class Video {
protected:
    //atributos
    string iD;
    string titulo;
    int duracion;
    string genero;
    double calificacionPromedio;
    
public:
    //constructores
    Video();
    Video(string _iD,string _titulo,int _duracion,string _genero,double _calificacionPromedio);
    
    //setters
    void setId(string _iD);
    void setTitulo(string _titulo);
    void setDuracion(int _duracion);
    void setGenero(string _genero);
    void setCalificacion(double _calificacionPromedio);
    
    //getters
    string getId() const;
    string getTitulo() const;
    int getDuracion() const;
    string getGenero() const;
    double getCalificacion() const;
    
    //str()
    virtual string str();
    
    //sobrecarga del operador << como función amiga para acceder a los atributos de la clase
    friend std::ostream& operator<<(std::ostream &out, const Video &video);

};


Video::Video(){
    iD = "000";
    titulo = "___";
    duracion = 0;
    genero = "XXX";
    calificacionPromedio = 0;
}

Video::Video(string _iD,string _titulo,int _duracion,string _genero,double _calificacionPromedio){
    iD = _iD;
    titulo = _titulo;
    duracion = _duracion;
    genero = _genero;
    calificacionPromedio = _calificacionPromedio;
}

//setters
void Video::setId(string _iD){
    iD = _iD;
}
void Video::setTitulo(string _titulo){
    titulo = _titulo;
}
void Video::setDuracion(int _duracion){
    duracion = _duracion;
}
void Video::setGenero(string _genero){
    genero = _genero;
}
void Video::setCalificacion(double _calificacionPromedio){
    calificacionPromedio = _calificacionPromedio;
}

//getters
string Video::getId() const{
    return iD;
}
string Video::getTitulo() const{
    return titulo;
}
int Video::getDuracion() const{
    return duracion;
}
string Video::getGenero() const{
    return genero;
}
double Video::getCalificacion() const{
    return calificacionPromedio;
}

//str()
string Video::str(){
    return iD + ',' + titulo + ',' + to_string(duracion)+ ',' + genero + ',' + to_string(calificacionPromedio) ;
    
}

//sobrecarga del operador << como función amiga para acceder a los atributos de la clase
std::ostream& operator<<(std::ostream &out, const Video &video){
    out << video.iD + ',' +  video.titulo + ',' + to_string(video.duracion) + ',' + video.genero + ',' + to_string(video.calificacionPromedio);
    
    return out;
}






#endif /* Video_hpp */
