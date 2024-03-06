#include <iostream>
using namespace std;
  
/*                Estructura de los nodos de la cola      
------------------------------------------------------------------------*/
struct nodo
{
    int nro;
    struct nodo *sgte;
};
 
 
/*                      Estructura de la cola      
------------------------------------------------------------------------*/
struct cola
{
    nodo *delante;
    nodo *atras  ;
};
 
 
/*                        Encolar elemento      
------------------------------------------------------------------------*/
void encolar( struct cola &q, int valor )
{
     struct nodo *aux = new(struct nodo);
     
     aux->nro = valor;
     aux->sgte = NULL;
     
     if( q.delante == NULL)
         q.delante = aux;   // encola el primero elemento
     else
         (q.atras)->sgte = aux;
         
     q.atras = aux;        // puntero que siempre apunta al ultimo elemento
     
}
 
/*                        Desencolar elemento      
------------------------------------------------------------------------*/
int desencolar( struct cola &q )
{
     int num ;
     struct nodo *aux ;
     
     aux = q.delante;      // aux apunta al inicio de la cola
     num = aux->nro;
     q.delante = (q.delante)->sgte;
     delete(aux);          // libera memoria a donde apuntaba aux
     
     return num;
}
 
/*                        Mostrar Cola      
------------------------------------------------------------------------*/
void muestraCola( struct cola q )
{
     struct nodo *aux;
     
     aux = q.delante;
         
     while( aux != NULL )
     {
            cout<<"   "<< aux->nro ;
            aux = aux->sgte;
     }    
}
 
/*              Eliminar todos los elementos de la Cola      
------------------------------------------------------------------------*/
void vaciaCola( struct cola &q)
{
     struct nodo *aux;
     
     while( q.delante != NULL)
     {
            aux = q.delante;
            q.delante = aux->sgte;
            delete(aux);
     }
     q.delante = NULL;
     q.atras   = NULL;
     
}

/*             Mostrar el primer elemento a desencolar      
------------------------------------------------------------------------*/
void muestraPrimerDesencolar( struct cola q )
{
     if (q.delante != NULL) {
        cout << "Primer elemento a desencolar: " << q.delante->nro << endl;
     } else {
        cout << "La cola está vacía." << endl;
     }
}

/*             Mostrar el ultimo elemento a desencolar      
------------------------------------------------------------------------*/
void muestraUltimoDesencolar( struct cola q )
{
     if (q.atras != NULL) {
        cout << "Ultimo elemento a desencolar: " << q.atras->nro << endl;
     } else {
        cout << "La cola está vacía." << endl;
     }
}

/*             Contar el numero de elementos en la cola      
------------------------------------------------------------------------*/
int numElementosCola( struct cola q )
{
    int contador = 0;
    struct nodo *aux = q.delante;
         
    while( aux != NULL )
    {
        contador++;
        aux = aux->sgte;
    }

    return contador;
}


/*                        Menu de opciones    
------------------------------------------------------------------------*/
void menu()
{
    cout<<"\n\t IMPLEMENTACION DE COLAS EN C++\n\n";
    cout<<" 1. ENCOLAR                               "<<endl;
    cout<<" 2. DESENCOLAR                            "<<endl;
    cout<<" 3. MOSTRAR COLA                          "<<endl;
    cout<<" 4. VACIAR COLA                           "<<endl;
    cout<<" 5. MOSTRAR PRIMER ELEMENTO A DESENCOLAR "<<endl;
    cout<<" 6. MOSTRAR ULTIMO ELEMENTO A DESENCOLAR "<<endl;
    cout<<" 7. MOSTRAR NUMERO DE ELEMENTOS EN LA COLA"<<endl;
    cout<<" 8. SALIR                                 "<<endl;
 
    cout<<"\n INGRESE OPCION: ";
}

/*                        Funcion Principal        
------------------------------------------------------------------------*/
int main()
{
    struct cola q;
   
    q.delante = NULL;
    q.atras   = NULL;
   
   
    int dato;  // numero a encolar
    int op;    // opcion del menu
    int x ;    // numero que devuelve la funcon pop
   
    system("color e1");
 
    do
    {
        menu();  
		cin>> op;
 
        switch(op)
        {
            case 1:
 
                 cout<< "\n NUMERO A ENCOLAR: "; 
				 cin>> dato;
                 encolar( q, dato );
                 cout<<"\n\n\t\tNumero " << dato << " encolado...\n\n";
            break;
 
 
            case 2:
 
                 x = desencolar( q );
                 cout<<"\n\n\t\tNumero "<< x <<" desencolado...\n\n";
            break;
                 
 
            case 3:
 
                 cout << "\n\n MOSTRANDO COLA\n\n";
                 if(q.delante!=NULL) muestraCola( q );
                 else   cout<<"\n\n\tCola vacia...!"<<endl;
            break;
 
 
            case 4:
 
                 vaciaCola( q );
                 cout<<"\n\n\t\tHecho...\n\n";
            break;

            case 5:
            	
                 muestraPrimerDesencolar(q);
            break;
            
            case 6:
            	
    			muestraUltimoDesencolar(q);
    		break;
    		
    		case 7:
    			cout << "Numero de elementos en la cola: " << numElementosCola(q) << endl;
   			break;
           
         }
 
        cout<<endl<<endl;
        system("pause");  system("cls");
 
    }while(op!=8);
   
   
    return 0;
}
