
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
using namespace std;
/*programa que escribe archivos secuencialmente en un archivo binario*/
struct cliente{
    int cuenta;
    char nombre[50];//aviso, si su intencion es mandar a grabar los datos de un struct a un binario, no se usen el tipo string en el campo,utilice vector de char
    float monto;
};
int main(){
    string resp;
    fstream archivo;
    //apertura de archivo en modo binario para leer
    archivo.open("clientes.dat",ios::binary|ios::in);
    if(!archivo){
        cerr<<"No se puede abrir el archivo!"<<endl;
        cin.get();
        return 1;//termina el programa
    }
    cliente registro;
    int c=0;
    cout<<endl<<endl<<"La informacion es rescatada desde el archivo!";
    while(archivo.read((char*)(&registro),sizeof(cliente))){
        cout<<endl;
        cout<<endl<<"cuenta: "<<registro.cuenta;
        cout<<endl<<"Nombre: "<<registro.nombre;
        cout<<endl<<"Monto: "<<registro.monto;
        c++;
    }
    cout<<endl<<endl<<"Total de registros: "<<c;
    archivo.close();
    return 0;
    
}
