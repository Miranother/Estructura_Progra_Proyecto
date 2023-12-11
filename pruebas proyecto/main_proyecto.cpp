#include <iostream>
#include "Mercancia.cpp"

using namespace std;

void generarCombinaciones(Datos* merca, Mercancia& dat, int* combinacionActual, int indice, int& contadorCombinaciones, double& costoTotal);

int main() {
    Mercancia dat;
    int tipos = 0, capacidadBuque = 0;
    int formasPosibles = 0;

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

    Datos* merca = new Datos[tipos];

    for (int i = 0; i < tipos; ++i) {
        cout << endl << "Dame los datos para la mercancia [" << i + 1 << "]: " << endl;
        merca[i].llenar();
    }
    dat.setMerca(merca);
    dat.escribirArchivo("Buque.dat");
    dat.imprimirArchivo("Buque.dat");

    int* combinacionActual = new int[tipos];
    int contadorCombinaciones = 0;
    double costoTotal = 0.0;

    generarCombinaciones(merca, dat, combinacionActual, 0, contadorCombinaciones, costoTotal);

    cout << "Numero total de combinaciones generadas: " << contadorCombinaciones << endl;

    delete[] merca;
    delete[] combinacionActual;

    return 0;
}

void generarCombinaciones(Datos* merca, Mercancia& dat, int* combinacionActual, int indice, int& contadorCombinaciones, double& costoTotal) {
    if (dat.getCapacidad() >= 0 && indice == dat.getTipos()) {
        // Se ha alcanzado la capacidad deseada y se ha recorrido todas las mercancías, imprimir la combinación actual
        double costoCombinacion = 0.0;
		int aux=dat.getCapacidad();
        // Imprimir el precio seguido de la capacidad de buque ocupada
        cout << merca->getCosto() << " " << aux - dat.getCapacidad() << endl;

        // Imprimir los nombres de las mercancías y cuántas unidades se ocuparon
        for (int i = 0; i < dat.getTipos(); ++i) {
            if (combinacionActual[i] > 0) {
                cout << merca[i].getNombre() << " " << combinacionActual[i] / merca[i].getVolumen() << endl;
            }
            costoCombinacion += combinacionActual[i] * merca[i].getCosto();
        }

        // Imprimir el total de combinaciones generadas
        cout << "Total de combinaciones generadas: " << contadorCombinaciones << endl;

        // Incrementar el contador de combinaciones y sumar el costo total
        contadorCombinaciones++;
        costoTotal += costoCombinacion;

        return;
    }

    if (indice < dat.getTipos() && dat.getCapacidad() - merca[indice].getVolumen() >= 0) {
        // Probar agregar la mercancía actual a la combinación y continuar generando combinaciones
        for (int cantidad = 0; cantidad <= merca[indice].getUnidades(); ++cantidad) {
            combinacionActual[indice] = cantidad * merca[indice].getVolumen();
            dat.setCapacidad(dat.getCapacidad() - combinacionActual[indice]);
            generarCombinaciones(merca, dat, combinacionActual, indice + 1, contadorCombinaciones, costoTotal);
            // Restaurar la combinación y la capacidad para probar otras combinaciones
            combinacionActual[indice] = 0;
            dat.setCapacidad(dat.getCapacidad() + combinacionActual[indice]);
        }
    }

    // Llamar recursivamente para la siguiente mercancía
    generarCombinaciones(merca, dat, combinacionActual, indice + 1, contadorCombinaciones, costoTotal);
}

/*#include <iostream>
#include "Mercancia.cpp"

using namespace std;

void generarCombinaciones(Datos* merca, Mercancia& dat, int* combinacionActual, int indice, int& contadorCombinaciones);

int main() {
    Mercancia dat;
    int tipos = 0, capacidadBuque = 0;
    int formasPosibles = 0;

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

    Datos* merca = new Datos[tipos];

    for (int i = 0; i < tipos; ++i) {
        cout << endl << "Dame los datos para la mercancia [" << i + 1 << "]: " << endl;
        merca[i].llenar();
    }

    int* combinacionActual = new int[tipos];
    int contadorCombinaciones = 0;

    generarCombinaciones(merca, dat, combinacionActual, 0, contadorCombinaciones);

    cout << "Número total de combinaciones generadas: " << contadorCombinaciones << endl;

    dat.setMerca(merca);
    dat.escribirArchivo("Buque.dat");
    dat.imprimirArchivo("Buque.dat");

    delete[] merca;
    delete[] combinacionActual;

    return 0;
}*/
/*
void generarCombinaciones(Datos* merca, Mercancia& dat, int* combinacionActual, int indice, int& contadorCombinaciones) {
    if (dat.getCapacidad() > 0) {
        // Se ha alcanzado la capacidad deseada, imprimir la combinación actual
        cout << "Combinación: ";
        for (int i = 0; i < dat.getTipos(); ++i) {
            cout << combinacionActual[i] << " ";
        }
        cout << endl;

        // Incrementar el contador de combinaciones
        contadorCombinaciones++;
       
    }

    for (int i = indice; i < dat.getTipos(); ++i) {
        if (dat.getCapacidad() - merca[i].getVolumen() >= 0) {
            // Agregar el volumen actual a la combinación y continuar generando combinaciones
            combinacionActual[i] = merca[i].getVolumen();
            dat.setCapacidad(dat.getCapacidad() - merca[i].getVolumen());
            generarCombinaciones(merca, dat, combinacionActual, i + 1, contadorCombinaciones);
            // Restaurar la combinación y la capacidad para probar otras combinaciones
            combinacionActual[i] = 0;
            dat.setCapacidad(dat.getCapacidad() + merca[i].getVolumen());
        }
    }
}
*/
/*#include <iostream>
#include "Mercancia.cpp"

using namespace std;

void generarCombinaciones(Datos* merca, Mercancia& dat, int* combinacionActual, int indice);

int main() {
    Mercancia dat;
    int tipos = 0, capacidadBuque = 0;
    int formasPosibles = 0;

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

    Datos* merca = new Datos[tipos];

    for (int i = 0; i < tipos; ++i) {
        cout << endl << "Dame los datos para la mercancia [" << i + 1 << "]: " << endl;
        merca[i].llenar();
    }

    

    dat.setMerca(merca);
    dat.escribirArchivo("Buque.dat");
    dat.imprimirArchivo("Buque.dat");
	int* combinacionActual = new int[tipos];
    generarCombinaciones(merca, dat, combinacionActual, 0);
    
    cout << endl << "Capacidad Buque: " << dat.getCapacidad() << endl;
    
    delete[] merca;
    delete[] combinacionActual;

    return 0;
}

void generarCombinaciones(Datos* merca, Mercancia& dat, int* combinacionActual, int indice) {
	cout<<endl<<"Ingresando a combinaciones"<<endl;
	
    if (dat.getCapacidad() == 0 || dat.getCapacidad()>=0) {
        // Se ha alcanzado la capacidad deseada, imprimir la combinación actual
        cout << "Combinación: ";
        for (int i = 0; i < dat.getTipos(); i++) {
            cout << combinacionActual[i] <<endl<<" ";
        }
        cout << endl;
        return;
    }

    for (int i = indice; i < dat.getTipos(); ++i) {
        if (dat.getCapacidad() - merca[i].getVolumen() >= 0) {
            // Agregar el volumen actual a la combinación y continuar generando combinaciones
            combinacionActual[i] = merca[i].getVolumen();
            dat.setCapacidad(dat.getCapacidad() - merca[i].getVolumen());
            generarCombinaciones(merca, dat, combinacionActual, i + 1);
            // Restaurar la combinación para probar otras combinaciones
            combinacionActual[i] = 0;
            dat.setCapacidad(dat.getCapacidad() + merca[i].getVolumen());
        }
    }
}*/

/*#include <iostream>
#include "Mercancia.cpp"

using namespace std;

void generarCombinaciones(Datos* merca,Mercancia dat, int* combinacionActual, int indice);

int main() {
    Mercancia dat;
    int tipos = 0, capacidadBuque = 0;
    int formasPosibles = 0;

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

    Datos* merca = new Datos[tipos];

    for (int i = 0; i < tipos; ++i) {
        cout << endl << "Dame los datos para la mercancia [" << i + 1 << "]: " << endl;
        merca[i].llenar();
    }

    int* combinacionActual = new int[tipos];
    generarCombinaciones(merca, dat, combinacionActual, 0);
	cout<<endl<<"Capacidad Buque"<<endl;
    dat.setMerca(merca);
    dat.escribirArchivo("Buque.dat");
    dat.imprimirArchivo("Buque.dat");

    delete[] merca;
    delete[] combinacionActual;

    return 0;
}

void generarCombinaciones(Datos* merca, Mercancia dat ,int* combinacionActual, int indice) {
	
    if (dat.getCapacidad() == 0) {
        // Se ha alcanzado la capacidad deseada, imprimir la combinación actual
        cout << "Combinación: ";
        for (int i = 0; i < dat.getTipos(); ++i) {
            cout << combinacionActual[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = indice; i < dat.getTipos(); ++i) {
        if (dat.getCapacidad() - merca[i].getVolumen() >= 0) {
            // Agregar el peso actual a la combinación y continuar generando combinaciones
            combinacionActual[i] = merca[i].getVolumen();
            generarCombinaciones(merca,  (dat.getCapacidad() - merca[i].getVolumen()), combinacionActual, i + 1);
            // Restaurar la combinación para probar otras combinaciones
            combinacionActual[i] = 0;
        }
    }
}
*/



/*#include "Mercancia.cpp"
void generarCombinaciones(Datos *, int capacidadBuque, int tipos, int combinacionActual);
int main()
{
	Mercancia dat;
	int tipos=0,capacidadBuque=0;
	int formasPosibles = 0;
    Datos* cargaActual = new Datos[tipos];
      int combinacionActual[tipos] = {0};

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
    generarCombinaciones(merca,  capacidadBuque, tipos, combinacionActual);
    dat.setMerca(merca);
    dat.escribirArchivo("Buque.dat");
    dat.imprimirArchivo("Buque.dat");

	//dat.FormasDeEmbarcar(capacidadBuque, merca, cargaActual, formasPosibles);
	

	return 0;
}
void generarCombinaciones(Datos *, int capacidadBuque, int tipos, int combinacionActual) {
	
    	Datos *merca = new Datos[tipos];
    
        if (capacidadBuque == 0) {
            // Se ha alcanzado la capacidad deseada, imprimir la combinación actual
            cout << "Combinación: ";
            for (int i = 0; i < tipos; ++i) {
                cout << combinacionActual[i] << " ";
            }
            cout << endl;
            return;
        }

        for (int i = indice; i < tipos; i++) {
            if (capacidadBuque - merca[i].getUnidades() >= 0) {
                // Agregar el peso actual a la combinación y continuar generando combinaciones
                combinacionActual[i] = merca[i].getUnidades();
                generarCombinaciones( merca[i++], int capacidadBuque, int tipos, int combinacionActual);
                // Restaurar la combinación para probar otras combinaciones
                combinacionActual[i] = 0;
            }
        }
    }*/
