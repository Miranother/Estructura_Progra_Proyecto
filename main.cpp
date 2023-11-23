#include <iostream>
#include <string>
#include <fstream>
#include <iomanip> //Por si llegamos a usar setw

struct Mercancia {
    string nombre;
    int volumen;
    int costo;
    int unidades;
};

using namespace std;


int main(int argc, char const *argv[]){
    fstream archivo;

    archivo.open("Buque.dat",ios::binary|ios::out|ios::app);
    if(!archivo){
        cout << "No se pudo abrir el archivo!" << endl;
        cin.get();
        return 1; //Terminar el programa
    }

    // Mercancia mercancias[MAX_MERCANCIAS];
    // int numTiposMercancias, capacidadBuque;

    // Fase 1: Leer datos desde el archivo
    //leerDatos("BUQUE.DAT", mercancias, numTiposMercancias, capacidadBuque);

    // Fase 1: Mostrar información en pantalla
    //imprimirDatos(mercancias, numTiposMercancias, capacidadBuque);

    // Fase 2: Calculo de la forma más óptima (Implementar)

    // Fase 2: Escribir resultados en el archivo "Buque.RES"
    // escribirResultados(solucion);

    // Fase 3: Formas posibles de embarcar la carga (Implementar)
    // formasPosiblesDeEmbarcar(mercancias, numTiposMercancias, capacidadBuque);

    return 0;
}
