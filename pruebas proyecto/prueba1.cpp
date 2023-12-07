#include <iostream>
#include <string>
#include <fstream>
#include <iomanip> //Por si llegamos a usar setw
#include <conio.h>

#include <cstring>
#include <windows.h>

using namespace std;

const int MAX_MERCANCIAS = 100;

class Datos{
	
	private:
        string nombre;
        int volumen;
        int costo;
        int unidades;
		
    public:
    	friend class Mercancia;
    // Constructor
    Datos() {}
    // Constructor con parametros
    Datos(const string& nombre, int volumen, int costo, int unidades)
    : nombre(nombre), volumen(volumen), costo(costo), unidades(unidades) {}    
        
    //Metodos set & get
    //Nombre--------------
    void setNombre(string);
    string getNombre();
    //--------------------
    //Volumen----------
    void setVolumen(int);
	int getVolumen();
	//-------------------
	//Costo------------
	void setCosto(int);
	int getCosto();
	//-----------------
	//Unidades----------
	void setUnidades(int);
	int getUnidades();
	//------------------


    // Otros metodos
};


class Mercancia{
	private:
		int tipos_mercancias;
		int capacidad_buque;
		Datos *merca;
	public:
		//Constructor vacio
		Mercancia(){}
		//Constructor con parametros
		Mercancia(int tipos, int capacidad, Datos *merca):tipos_mercancias(tipos),capacidad_buque(capacidad),merca(merca){}
		
		//Metodos set y get
		void setTipos(int);
		int getTipos();
		void setCapacidad(int);
		int getCapacidad();
		void setMerca(Datos *);
		Datos getMerca(int);
		
};

//CLASE MERCANCIA
//Metodos set y get
void Mercancia::setTipos(int tipos)
{
	this->tipos_mercancias=tipos;		
}

int Mercancia::getTipos()
{
	return this->tipos_mercancias;
}

void Mercancia::setCapacidad(int capacidad)
{
	this->capacidad_buque=capacidad;
}

int Mercancia::getCapacidad()
{
	return this->capacidad_buque;
}

void Mercancia::setMerca(Datos *merca)
{
	this->merca=merca;
}

Datos Mercancia:: getMerca(int n)
{
	return this->merca[n];	
}
//CLASE DATOS
//Metodos get y set 
void Datos::setNombre(string nombre)
{
	this->nombre=nombre;
}

string Datos::getNombre()
{
	return this->nombre;
}

void Datos::setVolumen(int volumen)
{
	this->volumen=volumen;
}

int Datos::getVolumen()
{
	return this->volumen;
}

void Datos::setCosto(int costo)
{
	this->costo=costo;
}

int Datos::getCosto()
{
	return this->costo;
}

void Datos::setUnidades(int unidades)
{
	this->unidades=unidades;
}

int Datos::getUnidades()
{
	return this->unidades;
}
//----------------------------------------
