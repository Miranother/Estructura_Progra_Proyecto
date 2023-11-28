#include <iostream>
#include <string>
#include <fstream>
#include <iomanip> //Por si llegamos a usar setw

using namespace std;

const int MAX_MERCANCIAS = 100;

class Mercancia {
    public:
        string nombre;
        int volumen;
        int costo;
        int unidades;

    // Constructor
    Mercancia() {}

    // Constructor con parametros
    Mercancia(const string& nombre, int volumen, int costo, int unidades)
        : nombre(nombre), volumen(volumen), costo(costo), unidades(unidades) {}

    // Otros metodos
};


//FUNCIONES

//Función para validar si la cadena es de minúsculas
bool validarMinus(const string& cadena);

// Función para leer los datos desde la entrada del usuario
void leerArchivo(Mercancia mercancias[], int& tiposMercancias, int& capacidadBuque);

// Función para escribir los datos en el archivo "Buque.dat"
void escribirArchivo(const string& nombreArchivo, const Mercancia mercancias[], int tiposMercancias, int capacidadBuque);

//Función para imprimir el contenido del archivo (para verificar si se estan guardando los datos)
void imprimirArchivo(const string& nombreArchivo);




int main() {
    Mercancia mercancias[MAX_MERCANCIAS];
    int tiposMercancias, capacidadBuque;

    //Leer datos desde la entrada del usuario
    leerArchivo(mercancias, tiposMercancias, capacidadBuque);

    //Escribir datos en el archivo "Buque.dat"
    escribirArchivo("Buque.dat", mercancias, tiposMercancias, capacidadBuque);

    imprimirArchivo("Buque.dat");

    // Mercancia mercancias[MAX_MERCANCIAS];
    // int tiposMercancias, capacidadBuque;

    
    // Fase 2: Calculo de la forma más óptima (Implementar)

    // Fase 2: Escribir resultados en el archivo "Buque.RES"
    // escribirArchivo(solucion);

    // Fase 3: Formas posibles de embarcar la carga (Implementar)
    // formasDeEmbarcar(mercancias, tiposMercancias, capacidadBuque);

    return 0;
}


//IMPLEMENTACION

void escribirArchivo(const string& nombreArchivo, const Mercancia mercancias[], int tiposMercancias, int capacidadBuque) {
    ofstream archivo(nombreArchivo.c_str());

    if (!archivo) {
        cerr << "Error al abrir el archivo " << nombreArchivo << endl;
        exit(1);
    }

    archivo << tiposMercancias << endl;
    archivo << capacidadBuque << endl;

    for (int i = 0; i < tiposMercancias; ++i) {
        archivo << mercancias[i].nombre << " " << mercancias[i].volumen << " " << mercancias[i].costo << " " << mercancias[i].unidades << endl;
    }

    archivo.close();
}

bool validarMinus(const string& cadena) {
    for (int i = 0; i < cadena.length(); ++i) {
        char caracter = cadena[i];
        if (!(caracter >= 'a' && caracter <= 'z')) {
            return false;
        }
    }
    return true;
}

// Función para leer los datos desde la entrada del usuario
void leerArchivo(Mercancia mercancias[], int& tiposMercancias, int& capacidadBuque) {
	
	do{
		cout << "Ingrese la cantidad de tipos de mercancias (1-99): ";
    	cin >> tiposMercancias;
    	if(tiposMercancias<1 || tiposMercancias>100){
    		cout<<endl<<"Validacion invalida, intentalo de nuevo";
		}
	}while(tiposMercancias<1 || tiposMercancias>100);

	do{
    	cout << "Ingrese la capacidad del buque (1-9999): ";
    	cin >> capacidadBuque;
    	if(capacidadBuque<1 || capacidadBuque>9999){
    		cout<<endl<<"Validacion invalida, intentalo de nuevo";
		}
	}while(capacidadBuque<1 || capacidadBuque>9999);
	


    //Ciclo for para solicitar al usuario las mercancias
    for (int i = 0; i < tiposMercancias; ++i) {
        string nombre;
        int volumen, costo, unidades;

        cout << "Ingrese los datos para la mercancia " << i + 1 << ": ";
        cin >> nombre >> volumen >> costo >> unidades;

        // Validaciones para las minusculas y el rango de cantidades 
        if (nombre.length() > 20 || !validarMinus(nombre)) {
            cerr << "Error: El nombre de la mercancia debe tener maximo 20 letras minusculas!" << endl;
            exit(1);
        }

        if (volumen < 1 || volumen > 99999 || costo < 1 || costo > 99999 || unidades < 1 || unidades > 99999) {
            cerr << "Error: Las cantidades deben ser enteros entre 1 y 99999" << endl;
            exit(1);
        }

        mercancias[i] = Mercancia(nombre, volumen, costo, unidades);
    }
}

void imprimirArchivo(const string& nombreArchivo) {
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

        cout << "Mercancia " << i + 1 << ": " << setw(15) << left << nombre
             << "Volumen: " << setw(5) << volumen
             << "Costo: " << setw(5) << costo
             << "Unidades: " << setw(5) << unidades << endl;
    }

    archivo.close();
}
