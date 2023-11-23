
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
    //apertura de archivo en modo binario para escritura y agregar
    archivo.open("clientes.dat",ios::binary|ios::out|ios::app);
    if(!archivo){
        cerr<<"No se puede abrir el archivo!"<<endl;
        cin.get();
        return 1;//termina el programa
    }
    cliente registro;
    resp="si";
    while(resp=="si"){
        cout<<endl<<"Dame la cuenta: ";
        cin>>registro.cuenta;
        fflush(stdin);
        cout<<endl<<"Dame el nombre: ";
        //se puede capturar nombre con apellidos y espacios en blanco
        cin.getline(registro.nombre,50);
        cout<<endl<<"Dame el monto: ";
        cin>>registro.monto;
        cout<<endl<<"Grabando en el archivo...";
        cout<<endl<<" "<<registro.cuenta;
        cout<<endl<<" "<<registro.nombre;
        cout<<endl<<" "<<registro.monto;
        archivo.write((char*)(&registro),sizeof(cliente));
        cout<<endl<<endl<<"Desea ingresar mas datos si/no: ";
        fflush(stdin);
        getline(cin,resp);//recordar que asi se leen las variables del tipo string
    }
    archivo.close();
    return 0;
}
