#ifndef MERCANCIA_DATOS_H
#define MERCANCIA_DATOS_H

#include "Datos.cpp"


class Mercancia{
	private:
		int tipos_mercancias;
		int capacidad_buque;
		Datos *merca;
	public:
		string archivo;
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
		
		//Otros metodos
		void escribirArchivo(const string&);
		void imprimirArchivo(const string& );

};

#endif

