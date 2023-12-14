#ifndef DATOS_H
#define DATOS_H

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

struct Datos{
	    string nombre;
        int volumen;
        float costo;
        int unidades;
		Datos *sig;
};


class ListaDatos {
private:
    Datos* cabeza; // Puntero al primer nodo de la lista

public:
    ListaDatos() : cabeza(NULL) {} // Constructor que inicializa la cabeza de la lista como nula

	void agregarElemento(const string& nombre, int volumen, float costo, int unidades);
	void llenar();
    bool validarMinus(const string& cadena);
    void imprimir();
    int getTotalVolumen();
    int getTotalUnidades();  
    string getInfo();    
    ~ListaDatos();
};

#endif
