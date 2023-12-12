#include <sstream>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


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
    string getInfo() const;
};
//CLASE DATOS

class Mercancia{
	private:
		int tipos_mercancias;
		int capacidad_buque;
		Datos *merca;
        void escribirResultadoEnArchivo(const vector<Datos>& seleccionados);
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
        void calcularCargaOptima();
		Datos getMerca(int);
		
		//Otros metodos
		void escribirArchivo(const string&);
		void imprimirArchivo(const string& );

};



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

void Datos::setCosto(float costo)
{
		this->costo=costo;		
}

float Datos::getCosto()
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
bool Datos::validarMinus(const string& cadena) {
    for (int i = 0; i < cadena.length(); ++i) {
        char caracter = cadena[i];
        if (!(caracter >= 'a' && caracter <= 'z')) {
            return false;
        }
    }
    return true;
}

void Datos::llenar()
{
		do
		{
			cout<<"Dame el nombre de la Mercancia : ";
			fflush(stdin);
        	getline(cin,nombre);
			
			if (nombre.length() > 20) 
			{
    			cout <<"Error: El nombre de la mercancia debe tener maximo 20 letras " << endl;
    		}
    		else if(!validarMinus(nombre))
    		{
    			cout<<"Error: El nombre de la mercancia debe tener letras minusculas"<<endl;
			}
					
		}while(nombre.length() > 20 || !validarMinus(nombre));
			
		do
		{
			cout<<endl<<"Dame el volumen para la mercancia : ";
			cin>>volumen;
			 if (volumen <1)
				cout<<endl<<"Volumen menor a la capacidad minima, intentalo de nuevo";
			else if(volumen>99999)
				cout<<endl<<"Volumen mayor a la capacidad maxima, intentalo de nuevo";	
			
		}while(volumen < 1 || volumen > 99999 );
		
		do
		{
			cout<<endl<<"Dame el costo para la mercancia : ";
			cin>>costo;
			if (costo <1)
				cout<<endl<<"Costo menor a la capacidad minima, intentalo de nuevo";
			else if(costo>99999)
				cout<<endl<<"Costo mayor a la capacidad maxima, intentalo de nuevo";
			
		}while(costo < 1 || costo > 99999 );
		
		do
		{
			cout<<endl<<"Dame las unidades de la mercancia : ";
			cin>>unidades;
			
				if (unidades <1)
					cout<<endl<<"Unidades menores a la capacidad minima, intentalo de nuevo";
				else if (unidades >99999) 
					cout<<endl<<"Unidades mayores a la capacidad maxima, intentalo de nuevo";
		
		}while(unidades < 1 || unidades > 99999 );
}

void Datos::imprimir()
{
	cout << "Mercancia " << ": " << setw(15) << left << nombre
         << "Volumen: " << setw(5) << volumen
         << "Costo: " << setw(5) << costo
         << "Unidades: " << setw(5) << unidades << endl;
}

string Datos::getInfo() const
{
	stringstream concatenar;
        concatenar << nombre << " " << volumen << " " << costo << " " << unidades;
        return concatenar.str();

}

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


// Implementacion del metodo escribirArchivo
void Mercancia::escribirArchivo(const string& nombreArchivo){
    ofstream archivo(nombreArchivo.c_str());
    if (!archivo) {
        cerr << "Error al abrir el archivo " << nombreArchivo << endl;
        exit(1);
    }

    archivo << tipos_mercancias << endl;
    archivo << capacidad_buque << endl;

    // Supongamos que la clase Datos tiene un metodo getInfo que devuelve una cadena con la informacion
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

void Mercancia::escribirResultadoEnArchivo(const vector<Datos>& seleccionados) {
    ofstream archivo("Buque.RES");
    if (!archivo) {
        cerr << "Error al abrir el archivo para escribir resultados." << endl;
        return;
    }

    for (const auto& item : seleccionados) {
        archivo << item.getInfo() << endl;
    }

    archivo.close();
}

void Mercancia::calcularCargaOptima() {
    // Ordenar las mercancías por su valor por volumen (de mayor a menor)
    vector<pair<float, int>> valorPorVolumen; // Par de valor por volumen y el índice de la mercancía
    for (int i = 0; i < tipos_mercancias; ++i) {
        valorPorVolumen.push_back({merca[i].getCosto() / merca[i].getVolumen(), i});
    }
    sort(valorPorVolumen.rbegin(), valorPorVolumen.rend()); // Ordenar en orden descendente

    // Seleccionar las mercancías
    vector<Datos> seleccionados;
    int capacidadRestante = capacidad_buque;
    for (const auto& vp : valorPorVolumen) {
        int idx = vp.second;
        int cantidadPosible = min(merca[idx].getUnidades(), capacidadRestante / merca[idx].getVolumen());
        if (cantidadPosible > 0) {
            Datos item = merca[idx];
            item.setUnidades(cantidadPosible);
            seleccionados.push_back(item);
            capacidadRestante -= cantidadPosible * item.getVolumen();
        }
    }

    // Escribir los resultados en el archivo "Buque.RES"
    escribirResultadoEnArchivo(seleccionados);
}

int main()
{
	Mercancia dat;
	int tipos=0,capacidadBuque=0;


	do{
	cout<<"Dame el total de tipos de mercancias (1-99): ";		
	cin>>tipos;
	dat.setTipos(tipos);
	}while(tipos < 1 || tipos > 99);
		
	do{
        cout << "Ingrese la capacidad del buque (1-9999): ";
        cin >> capacidadBuque;
        dat.setCapacidad(capacidadBuque);
    } while (capacidadBuque < 1 || capacidadBuque > 9999);
    
    	Datos *merca = new Datos[tipos];
    
    for (int i = 0; i < tipos; ++i) 
	{
		cout<<endl<<"Dame los datos para la mercancia ["<<i+1<<"]: "<<endl;
		merca[i].llenar();
    }
    
    dat.setMerca(merca);
    
    dat.escribirArchivo("Buque.dat");
    dat.imprimirArchivo("Buque.dat");

    // Procesar la carga óptima y escribir el resultado en "Buque.RES"
    dat.calcularCargaOptima();

    // Limpieza
    delete[] merca;

    cout << "Proceso completado. Verifique el archivo 'Buque.RES' para los resultados." << endl;

	return 0;
}
