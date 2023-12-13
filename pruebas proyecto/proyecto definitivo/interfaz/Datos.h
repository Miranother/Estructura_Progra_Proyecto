#ifndef DATOS_H
#define DATOS_H

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Datos{
	
	private:
        string nombre;
        int volumen;
        float costo;
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

    void setNombre(string );
    string getNombre();
    //--------------------
    //Volumen----------
    void setVolumen(int);
	int getVolumen();
	//-------------------
	//Costo------------
	void setCosto(float);
	float getCosto();
	//-----------------
	//Unidades----------
	void setUnidades(int);
	int getUnidades();
	//------------------


    // Otros metodos
    bool validarMinus(const string& cadena);
    void llenar();
    void imprimir();
    string getInfo();
};
class Dato2:public Datos{
	private:
		
	public:
		void titulo();
		virtual void copia_datos()=0;
		
};



#endif
