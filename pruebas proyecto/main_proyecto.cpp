#include "Mercancia.cpp"

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
	return 0;
}
