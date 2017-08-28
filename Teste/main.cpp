#include <iostream>
#include <vector>
#include "mgrafo.h"

using namespace std;




int main()
{
    MGrafo grafo;

    grafo.inserirVertice("A");
    grafo.inserirVertice("B");
    grafo.inserirVertice("C");
    grafo.inserirVertice("D");

    grafo.inserirArco(0,3);
    grafo.inserirArco(3,2);
    grafo.inserirArco(1,2);
    grafo.inserirArco(2,0);

    grafo.dfs("D");
//    grafo.imprimir();

    return 0;
}

