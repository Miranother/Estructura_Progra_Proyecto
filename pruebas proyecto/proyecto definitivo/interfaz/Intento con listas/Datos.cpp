#include "Datos.h"
#include <sstream>
#include <iomanip>
#include <string>
#include "interfaz.h"
void ListaDatos:: imprimir() 
{
    Datos* actual = cabeza;
    while (actual != NULL) 
	{
        cout << "Nombre: " << actual->nombre
        << "Volumen: " << actual->volumen
        << "Costo: " << actual->costo
        << "Unidades: " << actual->unidades << endl;
        actual = actual->sig;
    }
}


bool ListaDatos::validarMinus(const string &cadena)
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


void ListaDatos::llenar() 
{
    string nombre;
    int volumen;
    float costo;
    int unidades;

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

void ListaDatos::agregarElemento(const string& nombre, int volumen, float costo, int unidades)
{
    Datos* nuevo = new Datos;
    nuevo->nombre = nombre;
    nuevo->volumen = volumen;
    nuevo->costo = costo;
    nuevo->unidades = unidades;
    nuevo->sig = cabeza;
    cabeza = nuevo;	
}


string ListaDatos::getInfo() 
{
    stringstream concatenar;
    Datos* actual = cabeza;
    while (actual != NULL) 
	{
        concatenar << actual->nombre << " " 
    	<< actual->volumen << " " 
        << actual->costo << " " 
        << actual->unidades << "\n";
        actual = actual->sig;
	}
        return concatenar.str();
}





ListaDatos::~ListaDatos() 
{
    Datos* actual = cabeza;
    while (actual != NULL) 
	{
        Datos* aBorrar = actual;
        actual = actual->sig;
        delete aBorrar;
    }
}
