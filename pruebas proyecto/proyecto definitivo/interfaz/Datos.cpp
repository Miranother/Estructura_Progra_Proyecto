#include "Datos.h"
#include <sstream>
#include <iomanip>
#include <string>
#include "interfaz.h"
// Metodos get y set
void Datos::setNombre(string nombre)
{
    this->nombre = nombre;
}

string Datos::getNombre()
{
    return this->nombre;
}

void Datos::setVolumen(int volumen)
{
    this->volumen = volumen;
}

int Datos::getVolumen()
{
    return this->volumen;
}

void Datos::setCosto(float costo)
{
    this->costo = costo;
}

float Datos::getCosto()
{
    return this->costo;
}

void Datos::setUnidades(int unidades)
{
    this->unidades = unidades;
}

int Datos::getUnidades()
{
    return this->unidades;
}

//----------------------------------------
//Valida que el nombre de la mercancia sean minusculas, y no exista ninguna mayusscula
bool Datos::validarMinus(const string &cadena)
{
    for (int i = 0; i < cadena.length(); ++i)
    {
        char caracter = cadena[i];
        if (!(caracter >= 'a' && caracter <= 'z'))
        {
            return false;
        }
    }
    return true;
}

// Solicitar los datos de la mercancia al usuario
void Datos::llenar(){
	 CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleInfo);
    int consoleWidth = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1;
    int consoleHeight = consoleInfo.srWindow.Bottom - consoleInfo.srWindow.Top + 1;
	
	 const int anchoMarco = 100;
    const int altoMarco = 42;
    
    // Calcular la posición de inicio para centrar la pantalla
    int startX = (consoleWidth - anchoMarco) / 2;
    int startY = (consoleHeight - altoMarco) / 6;
		
    do
    {
    	textcolor(1);
	
    		cout << "Dame el nombre de la Mercancia : ";
        fflush(stdin);
        getline(cin, nombre);

        if (nombre.length() > 20)
        {
            cout << "Error: El nombre de la mercancia debe tener maximo 20 letras " << endl;
        }
        else if (!validarMinus(nombre))
        {
        cout << "Error: El nombre de la mercancia debe tener letras minusculas" << endl;
        }

    } while (nombre.length() > 20 || !validarMinus(nombre));

    do
    {
    	
      cout << endl
             << "Dame el volumen para la mercancia : ";
        cin >> volumen;
        if (volumen < 1)
             cout << endl
                 << "Volumen menor a la capacidad minima, intentalo de nuevo";
        else if (volumen > 99999)
              cout << endl
                 << "Volumen mayor a la capacidad maxima, intentalo de nuevo";

    } while (volumen < 1 || volumen > 99999);

    do
    {
        cout << endl
             << "Dame el costo para la mercancia : ";
        cin >> costo;
        if (costo < 1)
           cout << endl
                 << "Costo menor a la capacidad minima, intentalo de nuevo";
        else if (costo > 99999)
              cout << endl
                 << "Costo mayor a la capacidad maxima, intentalo de nuevo";

    } while (costo < 1 || costo > 99999);

    do
    {
        cout << endl
             << "Dame las unidades de la mercancia : ";
        cin >> unidades;

        if (unidades < 1)
            cout << endl
                 << "Unidades menores a la capacidad minima, intentalo de nuevo";
        else if (unidades > 99999)
            cout << endl
                 << "Unidades mayores a la capacidad maxima, intentalo de nuevo";

    } while (unidades < 1 || unidades > 99999);
}


//Imprimir datos de la mercancia
void Datos::imprimir()
{
		textcolor(3);
	
    cout << "Mercancia "
         << ": " << setw(15) << left << nombre
         << "Volumen: " << setw(5) << volumen
         << "Costo: " << setw(5) << costo
         << "Unidades: " << setw(5) << unidades << endl;
}


//Concatena las palabras para mandarla al archivo
string Datos::getInfo() 
{
    stringstream concatenar;
    concatenar << nombre << " " << volumen << " " << costo << " " << unidades;
    return concatenar.str();
}


