#include "Mercancia.cpp"
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
