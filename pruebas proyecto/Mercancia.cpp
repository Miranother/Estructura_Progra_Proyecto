#include "Mercancia.h"
//CLASE MERCANCIA
//Metodos set y get
void Mercancia::setTipos(int tipos)
{
	if(tipos>0 && tipos<100)
		this->tipos_mercancias=tipos;
	else
		cout<<"Intentalo de nuevo, tipos de mercancias invalidos"<<endl;		
}

int Mercancia::getTipos()
{
	return this->tipos_mercancias;
}

void Mercancia::setCapacidad(int capacidad)
{
	if(capacidad>0 && capacidad<10000)
		this->capacidad_buque=capacidad;
	else
		cout<<"Intentalo de nuevo, capacidad de buque invalida"<<endl;
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


// Implementación del método escribirArchivo
void Mercancia::escribirArchivo(const string& nombreArchivo){
    ofstream archivo(nombreArchivo.c_str());
    if (!archivo) {
        cerr << "Error al abrir el archivo " << nombreArchivo << endl;
        exit(1);
    }

    archivo << tipos_mercancias << endl;
    archivo << capacidad_buque << endl;

    // Supongamos que la clase Datos tiene un método getInfo que devuelve una cadena con la información
    for (int i = 0; i < tipos_mercancias; ++i) {
        archivo << merca[i].getInfo()<<endl;
    }

    archivo.close();
}

void Mercancia::imprimirArchivo(const string& nombreArchivo){
    ifstream archivo(nombreArchivo.c_str());

    if (!archivo) {
        cerr << "Error al abrir el archivo " << nombreArchivo << endl;
        exit(1);
    }

    int tiposMercancias, capacidadBuque;
    archivo >> tiposMercancias >> capacidadBuque;


    cout << endl << "Imprimiendo informacion............." << endl << endl;
    cout << "Tipos de mercancias: " << tiposMercancias << endl;
    cout << "Capacidad del buque: " << capacidadBuque << endl;

    for (int i = 0; i < tiposMercancias; ++i) {
        string nombre;
        int volumen, costo, unidades;

        archivo >> nombre >> volumen >> costo >> unidades;
		merca[i].imprimir();

    }

    archivo.close();
}


