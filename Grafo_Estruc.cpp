/*recuperacion nota Estructruas Avanzada*/

#include<iostream>
#include<conio.h>
using namespace std;

struct nodo{
            char nombre;//nombre del vertice o nodo
            struct nodo *sgte;
            struct arista *ady;//puntero hacia la primera arista del nodo
            };

struct arista{
              struct nodo *destino;//puntero al nodo de llegada
              struct arista *sgte;
              };

typedef struct nodo *Tnodo;//  Tipo Nodo

typedef struct arista *Tarista; //Tipo Arista

Tnodo p;//puntero cabeza

void menu();
void insertar_nodo();
void agrega_arista(Tnodo &, Tnodo &, Tarista &);
void insertar_arista();
void vaciar_aristas(Tnodo &);
void eliminar_nodo();
void eliminar_arista();
void mostrar_grafo();
void mostrar_aristas();


/*                        Funcion Principal
---------------------------------------------------------------------*/
int main(void)
{   p=NULL;
    int op;     // opcion del menu

    do
    {
        menu();
        cin>>op;

        switch(op)
        {
            case 1:
                    insertar_nodo();
                    break;
            case 2: insertar_arista();
                    break;
            case 3: mostrar_grafo();
                    break;

            default: cout<<"OPCION INVALIDA";
                     break;


        }

        cout<<endl<<endl;
        system("pause");  system("cls");

    }while(op!=4);
    getch();
    return 0;
}

/*                          Menu
---------------------------------------------------------------------*/
void menu()
{
    cout<<"\n\tGRAFO\n\n";
    cout<<" 1. Insertar nodo                "<<endl;
    cout<<" 2. Insertar arista              "<<endl;
    cout<<" 3. Mostrar grafo                "<<endl;
    cout<<" 4. Salir                        "<<endl;

    cout<<"\n Ingrese opcion: ";
}

/*                      INSERTAR NODO AL GRAFO
---------------------------------------------------------------------*/
void insertar_nodo()
{
    Tnodo t,nuevo=new struct nodo;
    cout<<"Ingrese nombre del nodo:";
    cin>>nuevo->nombre;
    nuevo->sgte = NULL;
    nuevo->ady=NULL;

    if(p==NULL)
     {
        p = nuevo;
        
        cout<<"Primer nodo";
      }
    else
     {
        t = p;
        while(t->sgte!=NULL)
         {
            t = t->sgte;
          }
        t->sgte = nuevo;
        cout<<"Nodo ingresado";
      }

 }

/*                      AGREGAR ARISTA
    funcion que utilizada para agregar la arista a dos nodos
---------------------------------------------------------------------*/
void agrega_arista(Tnodo &aux, Tnodo &aux2, Tarista &nuevo)
{
    Tarista q;
    if(aux->ady==NULL)
    {   aux->ady=nuevo;
        nuevo->destino=aux2;
        cout<<"Primera arista.";
    }
    else
    {   q=aux->ady;
        while(q->sgte!=NULL)
            q=q->sgte;
        nuevo->destino=aux2;
        q->sgte=nuevo;
        cout<<"Arista agregada.";
    }

}
/*                      INSERTAR ARISTA
    funcion que busca las posiciones de memoria de los nodos
    y hace llamado a agregar_arista para insertar la arista
---------------------------------------------------------------------*/
void insertar_arista()
{   char ini, fin;
    Tarista nuevo=new struct arista;
    Tnodo aux, aux2;

    if(p==NULL)
     {
         cout<<"Grafo vacio";
         return;
     }
    nuevo->sgte=NULL;
    cout<<"Ingrese nodo de inicio:";
    cin>>ini;
    cout<<"Ingrese nodo adyacente:";
    cin>>fin;
    aux=p;
    aux2=p;
    while(aux2!=NULL)
    {
        if(aux2->nombre==fin)
        {
            break;
        }

        aux2=aux2->sgte;
    }
    while(aux!=NULL)
    {
        if(aux->nombre==ini)
        {
            agrega_arista(aux,aux2, nuevo);
            return;
        }

        aux = aux->sgte;
    }
}

/*                      MOSTRAR GRAFO
    funcion que imprime un grafo en su forma enlazada
---------------------------------------------------------------------*/
void mostrar_grafo()
{   Tnodo ptr;
    Tarista ar;
    ptr=p;
    cout<<"NODO  |  LISTA DE ADYACENCIA\n";

    while(ptr!=NULL)
    {   cout<<"    "<<ptr->nombre<<" | ";
        if(ptr->ady!=NULL)
        {
            ar=ptr->ady;
            while(ar!=NULL)
            {   cout<<" "<<ar->destino->nombre;
                ar=ar->sgte;
             }

        }
        ptr=ptr->sgte;
        cout<<endl;
    }
}

