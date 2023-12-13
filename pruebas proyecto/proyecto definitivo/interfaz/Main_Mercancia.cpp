#include "Mercancia.cpp"
#include"interfaz.h"
#include <windows.h>

int main()
{
    Mercancia dat;
    int opcion = 0, totalCombinaciones;
    
    HWND hwnd = GetConsoleWindow();
	ShowWindow(hwnd, SW_MAXIMIZE);
	
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleInfo);
    int consoleWidth = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1;
    int consoleHeight = consoleInfo.srWindow.Bottom - consoleInfo.srWindow.Top + 1;
	Datos* datos=new Datos("Papas",200,200,5);	
	
	 const int anchoMarco = 100;
    const int altoMarco = 42;
    
    int startX = (consoleWidth - anchoMarco) / 2;
    int startY = (consoleHeight - altoMarco) / 6;
    
	maximizarVentana();
    primeraPantalla();
    do
    {
    	opcion=menu();

			system("cls"); 
		
		gotoxy(0,0);
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
        	
            break;
        }
        system("pause");
    } while (opcion != 5);
    //system("cls");

    return 0;
}
