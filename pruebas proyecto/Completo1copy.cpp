#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class Datos {
private:
    string nombre;
    int volumen;
    float costo;
    int unidades;

public:
    // Métodos set & get
    void setNombre(string);
    string getNombre() const;
    void setVolumen(int);
    int getVolumen() const;
    void setCosto(float);
    float getCosto() const;
    void setUnidades(int);
    int getUnidades() const;

    // Otros métodos
    bool validarMinus(const string &cadena);
    void llenar();
    void imprimir();
    string getInfo() const;
};

class Mercancia {
private:
    int tipos_mercancias;
    int capacidad_buque;
    vector<Datos> merca;

public:
    // Constructor vacío
    Mercancia() {}
    // Constructor con parámetros
    Mercancia(int tipos, int capacidad) : tipos_mercancias(tipos), capacidad_buque(capacidad) {}

    // Métodos set y get
    void setTipos(int);
    int getTipos();
    void setCapacidad(int);
    int getCapacidad();
    void agregarMercancia(Datos &);
    Datos obtenerMercancia(int);

    // Otros métodos
    void escribirArchivo(const string &);
    void imprimirArchivo(const string &);
    void calcularEmbarque();
};

// Implementación de métodos de Datos

void Datos::setNombre(string nombre) {
    this->nombre = nombre;
}

string Datos::getNombre() const {
    return this->nombre;
}

void Datos::setVolumen(int volumen) {
    this->volumen = volumen;
}

int Datos::getVolumen() const {
    return this->volumen;
}

void Datos::setCosto(float costo) {
    this->costo = costo;
}

float Datos::getCosto() const {
    return this->costo;
}

void Datos::setUnidades(int unidades) {
    this->unidades = unidades;
}

int Datos::getUnidades() const{
    return this->unidades;
}

bool Datos::validarMinus(const string &cadena) {
    for (int i = 0; i < cadena.length(); ++i) {
        char caracter = cadena[i];
        if (!(caracter >= 'a' && caracter <= 'z')) {
            return false;
        }
    }
    return true;
}

void Datos::llenar() {
    do {
        cout << "Dame el nombre de la Mercancia: ";
        fflush(stdin);
        getline(cin, nombre);

        if (nombre.length() > 20) {
            cout << "Error: El nombre de la mercancia debe tener máximo 20 letras." << endl;
        } else if (!validarMinus(nombre)) {
            cout << "Error: El nombre de la mercancia debe tener letras minúsculas." << endl;
        }

    } while (nombre.length() > 20 || !validarMinus(nombre));

    do {
        cout << "Dame el volumen para la mercancia: ";
        cin >> volumen;
        if (volumen < 1)
            cout << "Volumen menor a la capacidad mínima, intentalo de nuevo.";
        else if (volumen > 99999)
            cout << "Volumen mayor a la capacidad máxima, intentalo de nuevo.";

    } while (volumen < 1 || volumen > 99999);

    do {
        cout << "Dame el costo para la mercancia: ";
        cin >> costo;
        if (costo < 1)
            cout << "Costo menor a la capacidad mínima, intentalo de nuevo.";
        else if (costo > 99999)
            cout << "Costo mayor a la capacidad máxima, intentalo de nuevo.";

    } while (costo < 1 || costo > 99999);

    do {
        cout << "Dame las unidades de la mercancia: ";
        cin >> unidades;

        if (unidades < 1)
            cout << "Unidades menores a la capacidad mínima, intentalo de nuevo.";
        else if (unidades > 99999)
            cout << "Unidades mayores a la capacidad máxima, intentalo de nuevo.";

    } while (unidades < 1 || unidades > 99999);
}

void Datos::imprimir() {
    cout << "Mercancia: " << nombre << " Volumen: " << volumen << " Costo: " << costo << " Unidades: " << unidades << endl;
}

string Datos::getInfo() const{
    return nombre + " " + to_string(volumen) + " " + to_string(costo) + " " + to_string(unidades);
}

// Implementación de métodos de Mercancia

void Mercancia::setTipos(int tipos) {
    if (tipos > 0 && tipos < 100)
        this->tipos_mercancias = tipos;
    else
        cout << "Intentalo de nuevo, tipos de mercancias inválidos" << endl;
}

int Mercancia::getTipos() {
    return this->tipos_mercancias;
}

void Mercancia::setCapacidad(int capacidad) {
    if (capacidad > 0 && capacidad < 10000)
        this->capacidad_buque = capacidad;
    else
        cout << "Intentalo de nuevo, capacidad de buque inválida" << endl;
}

int Mercancia::getCapacidad() {
    return this->capacidad_buque;
}

void Mercancia::agregarMercancia(Datos &mercancia) {
    merca.push_back(mercancia);
}

Datos Mercancia::obtenerMercancia(int n) {
    return merca[n];
}

void Mercancia::escribirArchivo(const string &nombreArchivo) {
    ofstream archivo(nombreArchivo.c_str());
    if (!archivo) {
        cerr << "Error al abrir el archivo " << nombreArchivo << endl;
        exit(1);
    }

    archivo << tipos_mercancias << endl;
    archivo << capacidad_buque << endl;

    for (int i = 0; i < tipos_mercancias; ++i) {
        archivo << merca[i].getInfo() << endl;
    }

    archivo.close();
}

void Mercancia::imprimirArchivo(const string &nombreArchivo) {
    ifstream archivo(nombreArchivo.c_str());

    if (!archivo) {
        cerr << "Error al abrir el archivo " << nombreArchivo << endl;
        exit(1);
    }

    int tiposMercancias, capacidadBuque;
    archivo >> tiposMercancias >> capacidadBuque;

    cout << endl
         << "Imprimiendo información............." << endl
         << endl;
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

void Mercancia::calcularEmbarque() {
    // Ordenar mercancias por costo en orden descendente
    sort(merca.begin(), merca.end(), [](const Datos &a, const Datos &b) {
        return a.getCosto() > b.getCosto();
    });

    ofstream salida("Buque.RES");
    int espacio_disponible = capacidad_buque;
    bool alcanzable = false;

    for (const auto &mercancia : merca) {
        if (mercancia.getVolumen() <= espacio_disponible) {
            espacio_disponible -= mercancia.getVolumen();
            salida << mercancia.getInfo() << endl;
            alcanzable = true;
        }
    }

    salida.close();

    if (!alcanzable) {
        ofstream no_alcanzable("Buque.RES");
        no_alcanzable << "INALCANZABLE" << endl;
        no_alcanzable.close();
    }

    // Imprimir forma óptima
    cout << "Forma óptima de embarque:" << endl;
    for (const auto &mercancia : merca) {
        if (mercancia.getVolumen() <= espacio_disponible) {
            cout << mercancia.getNombre() << ": " << mercancia.getUnidades() << " unidades" << endl;
        }
    }

}


int main() {
    Mercancia dat;
    int tipos = 0, capacidadBuque = 0;

    do {
        cout << "Dame el total de tipos de mercancias (1-99): ";
        cin >> tipos;
        dat.setTipos(tipos);
    } while (tipos < 1 || tipos > 99);

    do {
        cout << "Ingrese la capacidad del buque (1-9999): ";
        cin >> capacidadBuque;
        dat.setCapacidad(capacidadBuque);
    } while (capacidadBuque < 1 || capacidadBuque > 9999);

    for (int i = 0; i < tipos; ++i) {
        cout << endl
             << "Dame los datos para la mercancia [" << i + 1 << "]: " << endl;
        Datos mercancia;
        mercancia.llenar();
        dat.agregarMercancia(mercancia);
    }

    dat.escribirArchivo("Buque.dat");
    dat.imprimirArchivo("Buque.dat");

    dat.calcularEmbarque();

    return 0;
}
