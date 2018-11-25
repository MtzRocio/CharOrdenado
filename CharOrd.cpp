#include <iostream>
//#include <cstdlib>
using namespace std;

struct nodo{
     char raiz;
     struct nodo *izq, *der;
};

typedef struct nodo *ABB;
/* es un puntero de tipo nodo, que ulitizaremos
   para mayor facilidad de creacion de variables */

ABB crearNodo(char x)
{
     ABB nuevoNodo = new(struct nodo);
     nuevoNodo->raiz = x;
     nuevoNodo->izq = NULL;
     nuevoNodo->der = NULL;

     return nuevoNodo;
}
void insertar(ABB &arbol, char x)
{
     if(arbol==NULL)
     {
           arbol = crearNodo(x);
     }
     else if(x < arbol->raiz)
          insertar(arbol->izq, x);
     else if(x > arbol->raiz)
          insertar(arbol->der, x);
}

void preOrden(ABB arbol)
{
     if(arbol!=NULL)
     {
          cout << arbol->raiz <<" ";
          preOrden(arbol->izq);
          preOrden(arbol->der);
     }
}

void enOrden(ABB arbol)
{
     if(arbol!=NULL)
     {
          enOrden(arbol->izq);
          cout << arbol->raiz << " ";
          enOrden(arbol->der);
     }
}

void postOrden(ABB arbol)
{
     if(arbol!=NULL)
     {
          postOrden(arbol->izq);
          postOrden(arbol->der);
          cout << arbol->raiz << " ";
     }
}

void verArbol(ABB arbol, int n)
{
     if(arbol==NULL)
          return;
     verArbol(arbol->der, n+1);

     for(int i=0; i<n; i++)
         cout<<"   ";

     cout<< arbol->raiz <<endl;

     verArbol(arbol->izq, n+1);
}

int main()
{
 /* struct arbolB [10];
  for (int i=0;i<5;i++)*/

    ABB arbol = NULL;   // creado Arbol

    int n;  // numero de nodos del arbol
    char x; // elemento a insertar en cada nodo

    cout << "ARBOL BINARIO QUE INSERTA LETRAS:\n\n";

    cout << " Numero de nodos del arbol:  ";
    cin >> n;
    cout << endl;

    for(int i=0; i<n; i++)
    {
        cout << " Letra del nodo " << i+1 << ": ";
        cin >> x;
        insertar( arbol, x);
    }

   cout << "\n Mostrando ABB \n\n";
    verArbol( arbol, 0);

    cout << "\n Recorridos del ABB";

    cout << "\n\n En orden   :  ";   enOrden(arbol);
    cout << "\n\n Pre Orden  :  ";   preOrden(arbol);
    cout << "\n\n Post Orden :  ";   postOrden(arbol);

    cout << endl << endl;

    system("pause");
    return 0;
}
