#include "Datos.h"
#include <sstream>
#include <iomanip>
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

string Datos::getInfo() 
{
	stringstream concatenar;
        concatenar << nombre << " " << volumen << " " << costo << " " << unidades;
        return concatenar.str();

}
