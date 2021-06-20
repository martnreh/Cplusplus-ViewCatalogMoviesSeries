//
//  Peliculas.hpp
//  Proyecto_Integrador_A01570656
//
//  Created by Adrian Martin Hernandez  on 21/05/21.
//

#ifndef Peliculas_hpp
#define Peliculas_hpp

#include "Pelicula.hpp"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
const int  MAX_PEL = 50;


class Peliculas{
    
private:
    //atributos
    Pelicula *arrPtrPeliculas[MAX_PEL]; //arreglo de apuntadores de la clase peliculas
    int cantidad;
    
    
public:
    //constructores
    Peliculas();
    
    //setters
    void setPtrPelicula(Pelicula *ptr);
    void setCantidad(int _cantidad);
    
    
    //getters
    Pelicula* getPtrPelicula(string sId);
    int getCantidadPeliculas();
    
    //otros
    
        //lee las peliculas desde un archivo csv y la carga en arreglo de arrPtrPeliculas
    void leerArchivo();
        //reporte de todas las peliculas en el arreglo arrPtrPeliculas
    void reporteTodasLasPeliculas();
        //reporte de todas las peliculas en el arreglo arrPtrPeliculas que tengan la misma calificacion que da el usuario
    void reporteConCalificacion(double calificacion);
    //reporte de todas las peliculas en el arreglo arrPtrPeliculas que sea del mimso género que da el usuario
    void reporteGenero(string genero);
    
};


//constructores
Peliculas::Peliculas(){
    cantidad = 0;
    for(int iR = 0; iR < MAX_PEL ; iR++){
        arrPtrPeliculas[iR] = nullptr;
    }
}

//setters
void Peliculas::setPtrPelicula(Pelicula *ptr){
    
    arrPtrPeliculas[cantidad] = ptr;
    cantidad = cantidad + 1;
}
void Peliculas::setCantidad(int _cantidad){
    cantidad = _cantidad;
}


//getters

Pelicula* Peliculas::getPtrPelicula(string sId){

    for(int iR = 0; iR < cantidad; iR++){
        if(arrPtrPeliculas[iR]->getId() == sId){
            return (arrPtrPeliculas[iR]);
        }
    }

        return nullptr;
}


int Peliculas::getCantidadPeliculas(){
    return cantidad;
}

//otros
void Peliculas::leerArchivo(){
    fstream archivoPeliculas;
    string row[6];
    string line,word;
    archivoPeliculas.open("Pelicula.csv");
    cantidad = 0;
    
    while(getline(archivoPeliculas,line)){
        //cout<<cantidad<<line<<endl;
        stringstream s(line);
        
        int iR = 0;
        
        while(getline(s,word,',')){
            row[iR++] = word;
        }
        
        //El arreglo de Pointers de peliculas recibe un objeto Pelicula new para agregar en su lista. El new se usa ya que solo se almacena el número de bytes de película. Entonces new regresa el apuntador del objeto Pelicula. 
        arrPtrPeliculas[cantidad] = new Pelicula(row[0],row[1] , stoi(row[2]),row[3],stod(row[4]),stoi(row[5]) );
        
        //cout<<"iD: " << row[0] << "\n";
        //cout<<"Titulo: " << row[1] << "\n";
        //cout<<"Duracion: " << row[2] << "\n";
        //cout<<"Genero: " << row[3] << "\n";
        //cout<<"Calificacion: " << row[4] << "\n";
        //cout<<"Oscares: " << row[5] << "\n";
        
        //cout<<"Dentro del objeto:"<<arrPtrPeliculas[cantidad] -> str()<< endl;
        
        cantidad = cantidad + 1;

    }
    archivoPeliculas.close();

    for(int iR = 0; iR < cantidad; iR++){
        //cout << iR << "-" << arrPtrPeliculas[iR]->str() << endl;
    }
    
}


void Peliculas::reporteTodasLasPeliculas(){
    double calificacion = 0;
    for(int iR = 0; iR < cantidad; iR++){
        //cout << arrPtrPeliculas[iR]->str() << endl; ANTES
        cout << *arrPtrPeliculas[iR] << endl; //uso de sobrecarga de operador <<
        calificacion = calificacion + arrPtrPeliculas[iR]->getCalificacion();
    }
    
    cout<<"Promedio:"<<(calificacion/cantidad)<<endl;
}



void Peliculas::reporteConCalificacion(double calificacion){
    for(int iR = 0; iR < cantidad; iR++){
        if(arrPtrPeliculas[iR]->getCalificacion() == calificacion){
            cout<<*arrPtrPeliculas[iR]<<endl; //uso de sobrecarga de operador <<
        }
       
    }  
    
}

    void Peliculas::reporteGenero(string genero){
        for(int iR = 0; iR < cantidad; iR++){
            if(arrPtrPeliculas[iR]->getGenero() == genero){
                cout<<*arrPtrPeliculas[iR]<<endl;  //uso de sobrecarga de operador <<
            }
           
        }
    }





#endif /* Peliculas_hpp */
