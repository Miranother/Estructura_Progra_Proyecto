#include <sstream>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//Información de la mercancia
class Datos
{

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
    Datos(const string &nombre, int volumen, int costo, int unidades)
        : nombre(nombre), volumen(volumen), costo(costo), unidades(unidades) {}

    // Metodos set & get
    // Nombre--------------

    void setNombre(string);
    string getNombre();
    //--------------------
    // Volumen----------
    void setVolumen(int);
    int getVolumen();
    //-------------------
    // Costo------------
    void setCosto(float);
    float getCosto();
    //-----------------
    // Unidades----------
    void setUnidades(int);
    int getUnidades();
    //------------------

    // Otros metodos
    bool validarMinus(const string &cadena);
    void llenar();
    void imprimir();
    string getInfo() const;
}; // CLASE DATOS




//Información del buque
class Mercancia
{
private:
    int tipos_mercancias;
    int capacidad_buque;
    Datos *merca;
    void escribirRES(const vector<Datos> &seleccionados);

public:
    string archivo;
    // Constructor vacio
    Mercancia() {}
    // Constructor con parametros
    Mercancia(int tipos, int capacidad, Datos *merca) : tipos_mercancias(tipos), capacidad_buque(capacidad), merca(merca) {}

    // Metodos set y get
    void setTipos(int);
    int getTipos();
    void setCapacidad(int);
    int getCapacidad();
    void setMerca(Datos *);
    Datos getMerca(int);

    // Otros metodos
    bool leerDatos();
    int combinaciones();
    void calcularCargaOptima();
    void ingresarDatos();
    void mostrarResultados();
    void escribirArchivo(const string &);
    void imprimirArchivo(const string &);

    //Destructor
    ~Mercancia() {
        //usamos delete[] para liberar la memoria asignada al arreglo merca
        delete[] merca;
    }
};

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
void Datos::llenar()
{
    do
    {
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
    cout << "Mercancia "
         << ": " << setw(15) << left << nombre
         << "Volumen: " << setw(5) << volumen
         << "Costo: " << setw(5) << costo
         << "Unidades: " << setw(5) << unidades << endl;
}


//Concatena las palabras para mandarla al archivo
string Datos::getInfo() const
{
    stringstream concatenar;
    concatenar << nombre << " " << volumen << " " << costo << " " << unidades;
    return concatenar.str();
}


// CLASE MERCANCIA


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

void Mercancia::setMerca(Datos *merca)
{
    this->merca = merca;
}

Datos Mercancia::getMerca(int n)
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
    if (!archivo)
    {
        cerr << "Error: No se pudo abrir el archivo 'Buque.dat'. Por favor, ingrese los datos primero." << endl;
        return false;
    }

    archivo >> tipos_mercancias >> capacidad_buque;
    merca = new Datos[tipos_mercancias];
    for (int i = 0; i < tipos_mercancias; ++i)
    {
        string nombre;
        int volumen, costo, unidades;
        archivo >> nombre >> volumen >> costo >> unidades;
        merca[i] = Datos(nombre, volumen, costo, unidades);
    }

    archivo.close();
    return true;
}


//Escribe el resultado de la carga optima en un archivo .RES
void Mercancia::escribirRES(const vector<Datos> &seleccionados)
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
    for (int i = 1; i <= tipos_mercancias; ++i)
    {
        for (int j = 1; j <= capacidad_buque; ++j)
        {
            dp[i][j] = dp[i - 1][j]; // No incluir la mercancía i
            if (merca[i - 1].getVolumen() <= j)
            {
                for (int k = 1; k <= merca[i - 1].getUnidades(); ++k)
                {
                    if (k * merca[i - 1].getVolumen() <= j)
                    {
                        // Agregar combinaciones incluyendo k unidades de la mercancía i
                        dp[i][j] += dp[i - 1][j - k * merca[i - 1].getVolumen()];
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
    // Crear un vector de pares para el valor por volumen y el índice de la mercancía
	vector<float> valores;
	vector<int> indices;

	for (int i = 0; i < tipos_mercancias; ++i)
	{
	    valores.push_back(merca[i].getCosto() / merca[i].getVolumen());
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

    // Seleccionar las mercancías
    vector<Datos> seleccionados;
    int capacidadRestante = capacidad_buque;

    for (size_t i = 0; i < valores.size(); ++i)
    {
        const int idx = indices[i];
        int capacidadParaUnaUnidad = merca[idx].getVolumen();

        // Verificar si hay capacidad para al menos una unidad
        if (capacidadParaUnaUnidad <= capacidadRestante)
        {
            int cantidadMaxima = min(merca[idx].getUnidades(), capacidadRestante / capacidadParaUnaUnidad);
            int cantidadPosible = max(1, cantidadMaxima); // Asegurarse de que al menos una unidad sea seleccionada

            Datos item = merca[idx];
            item.setUnidades(cantidadPosible);
            seleccionados.push_back(item);
            capacidadRestante -= cantidadPosible * item.getVolumen();

            // Imprimir informaci�n de depuraci�n
            cout << "Seleccionado: " << item.getNombre() << ", Unidades: " << cantidadPosible << ", Capacidad restante ahora: " << capacidadRestante << endl;
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

    cout << "Ingrese el total de tipos de mercancias (1-99): ";
    cin >> tipos;
    setTipos(tipos);

    cout << "Ingrese la capacidad del buque (1-9999): ";
    cin >> capacidadBuque;
    setCapacidad(capacidadBuque);

    Datos *merca = new Datos[tipos];

    for (int i = 0; i < tipos; ++i)
    {
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

int main()
{
    Mercancia dat;
    int opcion = 0, totalCombinaciones;

    do
    {
        cout << "\nMenu de Opciones:\n";
        cout << "1. Ingresar Datos de Mercancias\n";
        cout << "2. Calcular Carga Optima\n";
        cout << "3. Mostrar Carga Optima\n";
        cout << "4. Imprimir combinaciones totales\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            dat.ingresarDatos();
            break;
        case 2:
            if (dat.leerDatos())
            { // Intenta leer datos de "Buque.dat, si hay datos o existe el .dat, procede a calcular la carga optima
                dat.calcularCargaOptima();
                cout << "Carga optima calculada. Verifique el archivo 'Buque.RES' para los resultados." << endl;
            }
            else
            {
                cout << "Por favor, ingrese los datos primero utilizando la opcion 1." << endl;
            }
            break;
        case 3:
            dat.mostrarResultados();
            break;
        case 4:
            if (dat.leerDatos())
            {
                totalCombinaciones = dat.combinaciones();
                cout << "Total de combinaciones posibles: " << totalCombinaciones << endl;
            }
            else
            {
                cout << "Por favor, ingrese los datos primero utilizando la opcion 1." << endl;
            }
            break;
        case 5:
            cout << "Saliendo del programa...\n";
            break;
        default:
            cout << "Opcion no valida. Por favor, intente de nuevo.\n";
        }
    } while (opcion != 5);

    return 0;
}
