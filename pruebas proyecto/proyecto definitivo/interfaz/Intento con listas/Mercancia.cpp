#include "Mercancia.h"
// CLASE MERCANCIA
#include <sstream>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include"interfaz.h"

// Implementacion de metodos set y get
void Mercancia::setTipos(int tipos)
{
    if (tipos > 0 && tipos < 100)
        this->tipos_mercancias = tipos;
    else
        cout << "Intentalo de nuevo, tipos de mercancias invalidos" << endl;
}

int Mercancia::getTipos()
{
    return this->tipos_mercancias;
}

void Mercancia::setCapacidad(int capacidad)
{
    if (capacidad > 0 && capacidad < 10000)
        this->capacidad_buque = capacidad;
    else
        cout << "Intentalo de nuevo, capacidad de buque invalida" << endl;
}

int Mercancia::getCapacidad()
{
    return this->capacidad_buque;
}

void Mercancia::setMerca(ListaDatos *merca)
{
    this->merca = merca;
}

ListaDatos Mercancia::getMerca(int n)
{
    return this->merca[n];
}



// Escribe la informacion de la mercancia (tipos de mercancia,volumen del buque, nombre de la mercancia, volumen, precio y unidades)
void Mercancia::escribirArchivo(const string &nombreArchivo)
{
    ofstream archivo(nombreArchivo.c_str());
    if (!archivo)
    {
        cerr << "Error al abrir el archivo " << nombreArchivo << endl;
        exit(1);
    }

    archivo << tipos_mercancias << endl;
    archivo << capacidad_buque << endl;

    // Supongamos que la clase Datos tiene un metodo getInfo que devuelve una cadena con la informacion
    for (int i = 0; i < tipos_mercancias; ++i)
    {
        archivo << merca[i].getInfo() << endl;
    }

    archivo.close();
}


//Imprime el contenido del archivo .dat
void Mercancia::imprimirArchivo(const string &nombreArchivo)
{
    ifstream archivo(nombreArchivo.c_str());

    if (!archivo)
    {
        cerr << "Error al abrir el archivo " << nombreArchivo << endl;
        exit(1);
    }

    int tiposMercancias, capacidadBuque;
    archivo >> tiposMercancias >> capacidadBuque;
		textcolor(2);
	
    cout << endl
         << "Imprimiendo informacion............." << endl
         << endl;
    cout << "Tipos de mercancias: " << tiposMercancias << endl;
    cout << "Capacidad del buque: " << capacidadBuque << endl;

    for (int i = 0; i < tiposMercancias; ++i)
    {
        string nombre;
        int volumen, costo, unidades;

        archivo >> nombre >> volumen >> costo >> unidades;
        merca[i].imprimir();
    }

    archivo.close();
}


//Lee los datos que están en el archivo .dat y los asigna a variables para poder utilizarlas
bool Mercancia::leerDatos()
{
    ifstream archivo("Buque.dat");
    if (!archivo) {
        cerr << "Error: No se pudo abrir el archivo 'Buque.dat'. Por favor, ingrese los datos primero." << endl;
        return false;
    }

    archivo >> tipos_mercancias >> capacidad_buque;
    merca = new ListaDatos[tipos_mercancias];
    for (int i = 0; i < tipos_mercancias; ++i) {
        string nombre;
        int volumen, costo, unidades;
        while (archivo >> nombre >> volumen >> costo >> unidades) {
            merca[i].agregarElemento(nombre, volumen, costo, unidades);
        }
    }

    archivo.close();
    return true;
}


//Escribe el resultado de la carga optima en un archivo .RES
void Mercancia::escribirRES(vector<ListaDatos> &seleccionados)
{
    ofstream archivo("Buque.RES");
    if (!archivo)
    {
        cerr << "Error al abrir el archivo para escribir resultados." << endl;
        return;
    }

    for (size_t i = 0; i < seleccionados.size(); ++i)
    {
        archivo << seleccionados[i].getInfo() << endl;
    }

    archivo.close();
}


//Calcula las combinaciones totales posibles de embarcar 
int Mercancia::combinaciones()
{
    // Crear una matriz de programación dinámica
    int dp[tipos_mercancias + 1][capacidad_buque + 1];

    // Inicializar la primera fila (ninguna mercancía) con 1
    for (int j = 0; j <= capacidad_buque; ++j)
    {
        dp[0][j] = 1;
    }

    // Inicializar la primera columna (capacidad 0) con 1
    for (int i = 1; i <= tipos_mercancias; ++i)
    {
        dp[i][0] = 1;
    }

    // Llenar la matriz
    for (int i = 1; i <= tipos_mercancias; ++i) {
        for (int j = 1; j <= capacidad_buque; ++j) {
            dp[i][j] = dp[i - 1][j];
            int volumen = merca[i - 1].getTotalVolumen();
            int unidades = merca[i - 1].getTotalUnidades();

            if (volumen <= j) {
                for (int k = 1; k <= unidades; ++k) {
                    if (k * volumen <= j) {
                        dp[i][j] += dp[i - 1][j - k * volumen];
                    }
                }
            }
        }
    }
    return dp[tipos_mercancias][capacidad_buque];
}

//Calcula la carga optima a embarcar
void Mercancia::calcularCargaOptima()
{
    vector<float> valores;
    vector<int> indices;

    for (int i = 0; i < tipos_mercancias; ++i) {
        float valorTotal = 0;
        int volumenTotal = merca[i].getTotalVolumen();
        int unidadesTotal = merca[i].getTotalUnidades();

        Datos* actual = merca[i].getCabeza();
        while (actual != NULL) {
            valorTotal += actual->costo * actual->unidades;
            actual = actual->sig;
        }

        float valorPorVolumen = volumenTotal > 0 ? valorTotal / volumenTotal : 0;
        valores.push_back(valorPorVolumen);
        indices.push_back(i);
    }


    // Ordenamiento por burbuja
    for (size_t i = 0; i < valores.size() - 1; i++)
    {
        for (size_t j = 0; j < valores.size() - i - 1; j++)
        {
            if (valores[j] < valores[j + 1])
            {
                // Intercambiar los elementos
                swap(valores[j], valores[j + 1]);
                swap(indices[j], indices[j + 1]);
            }
        }
    }

    vector<ListaDatos> seleccionados;
    int capacidadRestante = capacidad_buque;

for (size_t i = 0; i < valores.size(); ++i) {
    const int idx = indices[i];
    Datos* actual = merca[idx].getCabeza();
    while (actual != NULL && capacidadRestante > 0) {
        int capacidadParaUnaUnidad = actual->volumen;

        if (capacidadParaUnaUnidad <= capacidadRestante) {
            int cantidadMaxima = min(actual->unidades, capacidadRestante / capacidadParaUnaUnidad);
            int cantidadPosible = max(1, cantidadMaxima);

            ListaDatos listaSeleccionada;
            Datos item = *actual;
            item.unidades = cantidadPosible;
            listaSeleccionada.agregarElemento(item.nombre, item.volumen, item.costo, item.unidades);

            seleccionados.push_back(listaSeleccionada);
            capacidadRestante -= cantidadPosible * item.volumen;

            cout << " Mercancia seleccionada: " << item.nombre << ", Unidades: " << cantidadPosible << ", Capacidad del buque restante: " << capacidadRestante << endl;
        }

        actual = actual->sig;
    }
}

    // Escribir los resultados en el archivo "Buque.RES"
    escribirRES(seleccionados);
}


// Si ya existe un archivo .dat, preguntamos si se desea sobreescribir, si la respuesta es si, se pide al usuario los datos de la mercancia
//y se sobreescribe el archivo ya existente con los datos nuevos.
void Mercancia::ingresarDatos()
{
    // Comprobación para evitar la sobreescritura accidental del archivo "Buque.dat"
    ifstream testArchivo("Buque.dat");
    if (testArchivo)
    {
        cout << "Advertencia: El archivo 'Buque.dat' ya existe. Desea sobrescribirlo? (s/n): ";
        char respuesta;
        cin >> respuesta;
        if (respuesta != 's' && respuesta != 'S')
        {
            cout << "Operacion cancelada. Los datos no han sido guardados." << endl;
            return;
        }
    }
    testArchivo.close();

    // Pedir al usuario que ingrese los datos de las mercancías y la capacidad del buque
    int tipos = 0, capacidadBuque = 0;
		textcolor(9);
	
    cout << "Ingrese el total de tipos de mercancias (1-99): ";
    cin >> tipos;
    setTipos(tipos);

    cout << "Ingrese la capacidad del buque (1-9999): ";
    cin >> capacidadBuque;
    setCapacidad(capacidadBuque);

    ListaDatos *merca = new ListaDatos[tipos];

    for (int i = 0; i < tipos; ++i)
    {
    		textcolor(1);
        cout << endl
        
	
             << "Dame los datos para la mercancia [" << i + 1 << "]: " << endl;
        merca[i].llenar();
    }

    setMerca(merca);

    escribirArchivo("Buque.dat");
    cout << "Datos guardados exitosamente en 'Buque.dat'." << endl;

    delete[] merca; // Liberar memoria
}


//Imprime en pantalla la carga óptima
void Mercancia::mostrarResultados()
{
    cout << endl
         << "Mostrando resultados del archivo 'Buque.RES':" << endl;
    ifstream archivo("Buque.RES");
    if (archivo.is_open())
    {
        string linea;
        while (getline(archivo, linea))
        {
            cout << linea << endl;
        }
        archivo.close();
    }
    else
    {
        cout << "No se pudo abrir el archivo 'Buque.RES'." << endl;
    }
}

