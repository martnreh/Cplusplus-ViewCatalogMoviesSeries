//
//  Serie.hpp
//  Proyecto_Integrador_A01570656
//
//  Created by Adrian Martin Hernandez  on 18/05/21.
//

#ifndef Serie_hpp
#define Serie_hpp

#include "Video.hpp"
#include "Episodio.hpp"
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Serie : public Video {
    
private:
    //atributo
    Episodio episodios[5]{};
    int cantidad;
    
    
public:
    //constructores
    Serie();
    Serie(string _iD,string _titulo,int _duracion,string _genero,double _calificacionPromedio, int cantidad);
    
    //setters
    void setEpisodio(int _iE, Episodio _episodio);
    void setCantidad(int _cantidad);
    
    //getters
    Episodio getEpisodio(int _iE);
    int getCantidad();
    string getTitulo();
    
    //otros métodos
    double calculaCalPromedio();
    
    //str()
    string str();
    
    //función para concatenar los episodios de una serie usando str() para despues agregarlo al final de out de la sobrecarga de operador <<
    string episodios_concatenado() const;
    
    //sobrecarga del operador << como función amiga para acceder a los atributos de la clase
    friend std::ostream& operator<< (std::ostream &out, const Serie &serie);
    
    
};


//constructores
Serie::Serie():Video(){
    cantidad = 0;
}

Serie::Serie(string _iD,string _titulo,int _duracion,string _genero,double _calificacionPromedio, int _cantidad):Video(_iD,_titulo,_duracion,_genero,_calificacionPromedio){
    
    cantidad = _cantidad;
}



//setters
void Serie::setEpisodio( int _iE, Episodio _episodio){
    if(_iE >= 0 && _iE <= cantidad){
        episodios[_iE] = _episodio;
    }
}

void Serie::setCantidad(int _cantidad){
    cantidad = _cantidad;
}


//getters
Episodio Serie::getEpisodio(int _iE){
    if(_iE >= 0 && _iE < cantidad){
        return episodios[_iE];
    }
    else{
        return Episodio();
    }
}

int Serie::getCantidad(){
    return cantidad;
}


//otros métodos

//calcula el promedio de todos los episodios de la serie en base a las calificaciones de sus episodios y lo asigna a calificacionPromedio
double Serie::calculaCalPromedio(){
    double promedio = 0;
    double acum = 0;

    if (cantidad> 0){
        for(int i = 0; i < cantidad;i++){
            acum = acum + episodios[i].getCalificacion();
        }
        promedio = acum / cantidad;
    }
    else{
        promedio = -1;
    }
    calificacionPromedio = promedio;
    return calificacionPromedio;
}


//str()
string Serie::str(){
    string strEpisodios;
    
    for(int iE = 0; iE < cantidad; iE ++){
        strEpisodios = strEpisodios + to_string(iE) + ":"+ episodios[iE].str() + '\n';
    }
    return ("S" + Video::str() + ',' +  to_string(cantidad) + '\n' + strEpisodios);
}

//función para concatenar los episodios de una serie usando str() para despues agregarlo al final de out de la sobrecarga de operador <<
string Serie::episodios_concatenado() const{
    std::string  sEpisodios = "";
    
    for(int iR = 0; iR < cantidad; iR++){
        sEpisodios = sEpisodios  + to_string(iR) + ":" + episodios[iR].str() + '\n';
    }
    return sEpisodios;
}



//sobrecarga del operador << como función amiga para acceder a los atributos de la clase
std::ostream& operator<< (std::ostream &out, const Serie &serie){
    
    std::string  sEpisodios = "\n";
    
    
    out << "S" + serie.iD + ',' +  serie.titulo + ',' + to_string(serie.duracion) + ',' + serie.genero + ',' +   to_string(serie.calificacionPromedio) + ',' + to_string(serie.cantidad) + '\n' + serie.episodios_concatenado();
    
    return out;
}




#endif /* Serie_hpp */
