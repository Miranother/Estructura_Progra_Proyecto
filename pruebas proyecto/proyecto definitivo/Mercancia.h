#ifndef MERCANCIA_DATOS_H
#define MERCANCIA_DATOS_H
#include <sstream>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "Datos.cpp"
//Informacionn del buque
class Mercancia
{
private:
    int tipos_mercancias;
    int capacidad_buque;
    Datos *merca;
    void escribirRES(vector<Datos> &seleccionados);

public:
    string archivo;
    // Constructor vacio
    Mercancia() {}
    // Constructor con parametros
    Mercancia(int tipos, int capacidad, Datos *merca) : tipos_mercancias(tipos), capacidad_buque(capacidad), merca(merca) {}

    // Metodos set y get
    void setTipos(int);
    int getTipos();
    void setCapacidad(int);
    int getCapacidad();
    void setMerca(Datos *);
    Datos getMerca(int);

    // Otros metodos
    bool leerDatos();
    int combinaciones();
    void calcularCargaOptima();
    void ingresarDatos();
    void mostrarResultados();
    void escribirArchivo(const string &);
    void imprimirArchivo(const string &);

    //Destructor
    ~Mercancia() {
        //usamos delete[] para liberar la memoria asignada al arreglo merca
        delete[] merca;
    }
};

#endif

