//
//  Series.hpp
//  Proyecto_Integrador_A01570656
//
//  Created by Adrian Martin Hernandez  on 27/05/21.
//

#ifndef Series_hpp
#define Series_hpp
#include "Serie.hpp"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

const int  MAX_SERIES = 50;


class Series{
    
private:
    //atributos
    //arreglo de apuntadores de la clase serie
    Serie *arrPtrSeries[MAX_SERIES];
    //cantidad de series dadas de alta en el arrPtrSeies
    int cantidad{};
    
    
    
public:
    //constructores
    Series(); //constructor que inicializa el *arrPtrSeries[MAX_SERIES] con nullptr
    
    //setters
    void setPtrSerie(Serie *ptr); // se asigna ese apuntador al arrPtrSeries[cantidad] en la posición actual que tenga el atributo cantidad
    void setCantidadSeries(int _cantidad); //asigna el atributo _cantidad a cantidad
    
    
    //getters
    Serie* getPtrSeries(string _iD); //retorna un apuntador serie quue tiene el iD igual a _iD, si no existe regresa nullptr
    int getCantidadSeries(); // retornas el atributo de cantidad
    
    //otros
    void leerArchivo(); //lee las series desde un archivo csv y las carga en el arreglo arrPtrSeries
    void reporteTodasLasSeries(); //reporte de todas las series que están en el arreglo arrptrSeries y despliega todas las series usando str()
    void reporteConCalificacion(double _calificacion); //reporte de todas las series que están en el arreglo arrPtrSeries que tienen la misma calificacion que _calificacion como el paramámetro
    void reporteGenero(string _genero); //rreporte de todas las series de arrPtrSeries que son del mismo genero que el parámetro _genero
    
    
    //calcular la calificación de cada serie en base a sus episodios. Manda a llamar al método calculaCalPromedio de la clase Serie para que calcule la calificación promedio de la Serie
    void calcularCalificacionSeries();
    
    
    
};

//constructores
Series::Series(){
    cantidad = 0;
    for(int iR = 0; iR < MAX_SERIES ; iR++){
        arrPtrSeries[iR] = nullptr;
    }
}

//setters
void Series::setPtrSerie(Serie *ptr){
    arrPtrSeries[cantidad] = ptr;
    cantidad = cantidad + 1;
}
void Series::setCantidadSeries(int _cantidad){
    cantidad = _cantidad;
}


//getters
Serie* Series::getPtrSeries(string sId){
    for(int iR = 0; iR < cantidad; iR++){
        if(arrPtrSeries[iR]->getId() == sId){
            return (arrPtrSeries[iR]);
        }
    }

        return nullptr;
}

int Series::getCantidadSeries(){
    return cantidad;
}

//otros

void Series::reporteTodasLasSeries(){
    double calificacion = 0;
    
    for(int iS = 0; iS < cantidad; iS++){
        cout << *arrPtrSeries[iS] << endl; //sobrecarga de operador <<
        calificacion = calificacion + arrPtrSeries[iS] -> getCalificacion();
    }
        cout<< "Promedio Series:"<<calificacion/cantidad<<endl;
}

void Series::reporteConCalificacion(double _calificacion){
    for(int iR = 0; iR < cantidad; iR++){
        if(arrPtrSeries[iR]->getCalificacion() == _calificacion){
            cout<<*arrPtrSeries[iR]<<endl; //sobrecarga de operador <<
        }
       
    }
}

void Series::reporteGenero(string _genero){
    for(int iR = 0; iR < cantidad; iR++){
        if(arrPtrSeries[iR]->getGenero() == _genero){
            cout<<*arrPtrSeries[iR]<<endl; //sobrecarga de operador <<
        }
       
    }
}

void Series::calcularCalificacionSeries(){
    double calificacion = 0;
    
    for(int iS = 0; iS < cantidad; iS++){
        calificacion = arrPtrSeries[iS] -> calculaCalPromedio();
        arrPtrSeries[iS]->setCalificacion(calificacion);
    }
    
}

void Series::leerArchivo(){
    //Declaración de variables para usarlas al leer cada linea del archivo de series
    string linea,dato,row[6];
    // crear variable que recibirá el archivo a leer
    fstream archivo;
    Episodio* episodio;
    //variable para llevar el contador de cantidad de series leías
    int iRow= 0 , iS= 0 , cantEpisodios = 0;
    

    // *************** LEER LAS SERIES ****************
    archivo.open("Serie2021.csv");
    cantidad = 0; //inicializar cantidad en 0
    
    //ciclo para leer todo el archivo
    while(getline(archivo,linea)){
        //cout<<linea<<endl;
        stringstream registro(linea);
        
        int iRow = 0;
        
        //ciclo para separar los elementos de la serie
        while(getline(registro,dato,',')){
            //cout<<dato<<endl;
            row[iRow++] = dato;
        }
        
        //crear un objeto de la clase serie, y utilizar new para retornar su apuntador
        arrPtrSeries[cantidad] = new Serie(row[0],row[1] ,stoi(row[2]),row[3],stod(row[4]),0);
        
        //cout<<arrPtrSeries[cantidad] -> str()<< endl;
        cantidad = cantidad + 1; //aumentar cantidad para llenar la siguiente posición del array

    }
    archivo.close(); //cerrar el archivo

    
    // *************** LEER LOS EPISODIOS ****************

    archivo.open("Episodio2021.csv");
    
    //ciclo para leer todo el archivo
    while(getline(archivo,linea)){
        
        //Desplegar el episodio leido
        //cout<<linea<<endl;
        stringstream registro(linea);
        
        int iRow = 0;
        
        //ciclo para separar los elementos de la serie
        while(getline(registro,dato,',')){ //separar los datos desde la línea de registro
            row[iRow++] = dato;
        }
        
        //iD - convertir a int - sacar la posición de la serie 500 - 0, 501 - 0 , 502 - 2
        iS = stoi(row[0]) - 500; //posición del arreglo donde está el ptr de la serie pertenece al episodio
        
        // crear episodio y retornar su apuntador
        episodio = new Episodio(row[1], stoi(row[2]), stod(row[3]));
        
        //traer la cantidad de episodios de la serie iS - la 1era vez retorna 0 
        cantEpisodios  = arrPtrSeries[iS] -> getCantidad();
        
        //verificar si todavía podemos añadir otro Episodio al arreglo
        if(cantEpisodios < 5){
            arrPtrSeries[iS]-> setEpisodio(cantEpisodios, *(episodio));
            arrPtrSeries[iS]-> setCantidad(++cantEpisodios);
        }
        
        //cout << arrPtrSeries[iS] -> str() << endl;
    }
    archivo.close(); //cerrar el archivo
    
    
    //Desplegar todas las series con sus episodios. Se manda a llamar el método str() de la clase serie.
    for(int iS = 0; iS < cantidad; iS++){
        //cout <<arrPtrSeries[iS]->str() << endl;
    }
    
} //termina método cerrar archivo



#endif /* Series_hpp */
