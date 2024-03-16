#include <iostream>
#include <malloc.h>
using namespace std;
int dias;

float pd;
struct temp{
double val;
temp * datos;
};

struct clima{
char fechas[10];
    temp manana;
temp tarde;
temp noche;
clima *sig;
};
clima *cab, *aux, *aux2;

int resgistros_de_datos(){

    cout<<"Ingrese el numero de dias a registrar: ";
                cin>>dias;
       aux = (struct clima*) malloc (dias * sizeof(struct clima));
for( int i =0;i < dias;++i) {
cout<<"Dia " << i+1 << endl;
cout<<"fecha: ";
cin>>aux[i].fechas;
 cout<<"Temperatura de la manana: ";
                    cin>>aux[i].manana.val;
                    cout<<"Temperatura de la tarde: ";
                    cin>>aux[i].tarde.val;
                    cout<<"Temperatura de la noche: ";
                    cin>>aux[i].noche.val;
aux->sig = NULL;
   if(!cab){
    cab = aux;
   } else {
    aux2 = cab;
    while(aux2->sig!=NULL)
        aux2 = aux2->sig;
    aux2->sig = aux;
   }

};
}
int mostrar_registros(){
    
  cout<<"\nRegistros de temperatura:\n";
                    for (int i= 0; i < dias; ++i) {
                        cout<<"Dia " << i+1 << ": " << aux[i].fechas << endl;
                        cout<<"   morning:"<< aux[i].manana.val<<"C ";
                        cout<<"   Tarde: "<<aux[i].tarde.val<<"C ";
                        cout<<"   Noche: "<<aux[i].noche.val<<"C "<<endl;
                    }

}  

int promedios(){
for (int i= 0; i < dias; ++i) {
 pd = (aux[i].manana.val+aux[i].tarde.val+aux[i].noche.val)/3;
cout<<"Dia " << i+1 <<":" << pd << " C" <<endl;
}



}
int promedios_total(){
    float ptotal =0;
    float temptotal;
for (int i= 0; i < dias; ++i) {

ptotal += (aux[i].manana.val+aux[i].tarde.val+aux[i].noche.val) ;

 temptotal=ptotal/(pd*3);
cout<<"promedio total de las temperaturas : " <<temptotal <<endl;
}

}
int main (){
    int opc=0;
    

    do {
      cout<<"\nMenu:\n";
        cout<<"1. Registrar Datos\n";
        cout<<"2. Mostrar registros ingresados \n";
        cout<<"3.  promedio de temperatura del dia\n";
        cout<<"4.  promedio total de las temperaturas\n";
        cout<<"5.  Salir\n";
        cin>>opc;
        cout<<endl;

        switch (opc)
        {
        case 1:resgistros_de_datos();
        
            break;

        case 2: mostrar_registros();
                    
                
            break;
        
        case 3:promedios() ;
                    
                
            break;
             case 4:promedios_total() ;
                    
                
            break;
            
case 5:cout << "Saliendo del programa..." << endl;
                    
                
            break;
             default:
                cout << "Opción inválida. Por favor, ingrese una opción válida." << endl;
                break;
        }


    } while(opc!=5);
};
