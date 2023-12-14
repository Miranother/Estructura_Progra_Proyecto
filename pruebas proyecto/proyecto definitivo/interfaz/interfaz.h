#ifndef INTERFAZ_GRAFICA_H
#define INTERFAZ_GRAFICA_H

#include <iostream>
#include <iomanip>
#include <cstring>
#include <windows.h>
#include <ctime>
#include <conio.h>
#include <string>
using namespace std;

void gotoxy(int x, int y)
{
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwpos;
	dwpos.X = x;
	dwpos.Y = y;
	SetConsoleCursorPosition(hcon,dwpos);
}
void textcolor(int n){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), n); 
}
void maximizarVentana() {

    HWND hwnd = GetConsoleWindow();
    keybd_event(VK_MENU, 0, 0, 0); 
    keybd_event(VK_SPACE, 0, 0, 0);
    keybd_event(VK_SPACE, 0, KEYEVENTF_KEYUP, 0); 
    keybd_event(VK_MENU, 0, KEYEVENTF_KEYUP, 0);
    keybd_event('X', 0, 0, 0); 
    keybd_event('X', 0, KEYEVENTF_KEYUP, 0); 
}

void titulo(int startX, int startY ){
	int matriz[25][80]={{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,2,4,0,0,0,0,0,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,2,4,0,0,0,0,0,3,3,3,3,4,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,2,4,0,0,0,0,0,0,0,0,3,3,4,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,2,4,0,0,0,0,0,0,5,0,0,3,4,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,2,4,0,0,0,0,0,5,0,6,0,3,4,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,2,4,0,0,0,0,5,0,6,0,0,3,4,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,2,4,0,0,0,5,0,6,0,0,0,3,4,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,2,4,0,0,5,0,6,0,0,0,0,3,4,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,2,4,4,0,0,6,0,0,0,0,0,3,4,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,1,1,1,0,1,1,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,2,4,4,4,0,0,0,0,0,0,0,3,4,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,2,2,4,4,4,4,0,0,0,0,3,4,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,4,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};


    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 75; j++) {
            if (matriz[i][j] == 1 || matriz[i][j] == 2 || matriz[i][j] == 3 || matriz[i][j] == 4 || matriz[i][j] == 5 || matriz[i][j] == 6) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
                gotoxy( startX+ j+15, startY + 2 + i);
                cout << char(219);
                if (matriz[i][j] == 2 || matriz[i][j] == 3) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
                    gotoxy( startX+ j+15, startY + 2 + i);
                    cout << char(219);
                }
                if (matriz[i][j] == 4) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
                    gotoxy( startX + j+15, startY +2 + i);
                    cout << char(219);
                }
                if (matriz[i][j] == 5) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                    gotoxy( startX+ j+15, startY +2 + i);
                    cout << char(219);
                }
                if (matriz[i][j] == 6) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    gotoxy( startX+ j+15, startY +2 + i);
                    cout << char(219);
                }
            }
            else {
                cout << " ";
            }
        }
        cout << endl;
    }
}
void primeraPantalla() {
    system("cls");
    // Tama�o del marco
    const int anchoMarco = 100;
    const int altoMarco = 42;

    // Texto de la pantalla
    string carrera = "<< I N G E N E R I A  E N  S I S T E M A S  C O M P U T A C I O N A L E S  >>";
    string materia = "PROGRAMACION 2";
    string nombreSistema = "---BUQUE---";
    string integrantes = "INTEGRANTES: ";
    string nom1="-Becerra Rodriguez Paola Guadalupe";
    string nom2="-Borjon Munoz Dulce Maria";
    string nom3="-Blanco Ortiz Carlos Enrique";
    string nom4="-Ortega de Luna Juan Damian";
    string profesor = "Profesora: Blanca Gudalupe Estrada Renteria";
    string fecha = "13 de Diciembre de 2023";

    // Obtener el ancho y alto de la consola
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleInfo);
    int consoleWidth = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1;
    int consoleHeight = consoleInfo.srWindow.Bottom - consoleInfo.srWindow.Top + 1;

    // Calcular la posici�n de inicio para centrar la pantalla
    int startX = (consoleWidth - anchoMarco) / 2;
    int startY = (consoleHeight - altoMarco) / 6;

    // Imprimir marco centrado
    for (int i = 0; i < startY; i++) {
        cout << endl;
    }
    for (int i = 0; i < altoMarco; i++) {
        for (int j = 0; j < startX; j++) {
            cout << " ";
        }
        for (int j = 0; j < anchoMarco; j++) {
            if (i == 0 || i == altoMarco - 1 || j == 0 || j == anchoMarco - 1) {
                // Cambiar el color del marco en cada iteraci�n
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
                cout << char(178);
            } else {
                cout<<" ";
            }
        }
        cout << endl;
    }
    titulo( startX-3,startY );
    gotoxy(startX, 17); cout << char(178);
    gotoxy(startX+10, startY+20 );cout<<carrera;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    gotoxy(startX+30, startY+22);cout<<"-----------------------------------";
    gotoxy(startX+40, startY+23); cout<<materia;
    gotoxy(startX+30, startY +24);cout<<"-----------------------------------";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
    gotoxy(startX+45, startY +26);cout<<nombreSistema;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    gotoxy(startX+40, startY +28);cout<<integrantes;
    gotoxy(startX+30, startY+30);cout<<nom1;
    gotoxy(startX+30, startY +31);cout<<nom2;
    gotoxy(startX+30, startY +32);cout<<nom3;
    gotoxy(startX+30, startY +33);cout<<nom4;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    gotoxy(startX+30, startY +35);cout<<profesor;
    gotoxy(startX+35, startY +37);cout<<fecha;
    cout << endl;
    cout << endl;
    //gotoxy(0,45); cout << "Presiona 'S' para pasar a la segunda pantalla o cualquier otra tecla para salir...";
   //char opcion = _getch(); // Esperar la entrada de una tecla (funci�n espec�fica de Windows)
	 gotoxy(startX+35, startY +42);
	 system("pause");
	 
   

   
}
int  menu(){
	system("cls");
    string opciones[] = {"1. INGRESAR DATOS DE MERCANCIA", "2. CALCULAR CARGA OPTIMA", "3. MOSTRAR CARGA OPTIMA",
	 "4. IMPRIMIR COMBINACIONES TOTALES" , "5. SALIR"};
    int tecla;
    int opcion;
    int escoger;	
	 
	const int anchoMarco = 100;
    const int altoMarco = 42;
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleInfo);
    int consoleWidth = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1;
    int consoleHeight = consoleInfo.srWindow.Bottom - consoleInfo.srWindow.Top + 1;
	int opc;
    // Calcular la posici�n de inicio para centrar la pantalla
    int startX = (consoleWidth - anchoMarco) / 2;
    int startY = (consoleHeight - altoMarco) / 6;

	 
    //menu
    for (int i = 0; i < startY; i++) {
        cout << endl;
    }
    for (int i = 0; i < altoMarco; i++) {
        for (int j = 0; j < startX; j++) {
            cout << " ";
        }
        for (int j = 0; j < anchoMarco; j++) {
            if (i == 0 || i == altoMarco - 1 || j == 0 || j == anchoMarco - 1) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                cout <<char(177);
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }

        
	do 
	{   
    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
        gotoxy(startX+10, 5);cout << " _  _   _                _    _   ___         _  ___   _            " ;
        gotoxy(startX+10, 6);cout << " |\\/|  |_  |\\ |  | |    |_)  |_)   |   |\\ |  /    |   |_)   /\\   |  " ;
        gotoxy(startX+10, 7);cout << " |  |  |_  | \\|  |_|    |    | \\  _|_  | \\|  \\_  _|_  |    /--\\  |_ " ;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
        int n=0;
        for (int i = 0; i < 5; i++) 
		{
			gotoxy(startX+25,startY+ 13+n);
            // Cambiar el color de la opci�n seleccionada
            if (i == opcion) 
			{
             SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            }else 
			{
                 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);// Blanco
            }

            cout << opciones[i];
 			n+=2;
        }
        Beep(200,200);
        tecla = _getch();

        if (tecla == 80)//Flecha abajo 
		{ 
            opcion = (opcion + 1) % 5;
        } else if (tecla == 72)// Flecha arriba
		{
        	opcion = (opcion - 1 + 5) % 5;
        }

        if (tecla == 13)// Enter
		{
            system("cls");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Blanco
            return opcion + 1; 
        }        
    }while (true);       
	    
}

#endif
