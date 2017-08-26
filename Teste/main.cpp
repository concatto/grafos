#include <iostream>
#include <vector>
#include "mgrafo.h"

using namespace std;




int main()
{
    MGrafo grafo;

    grafo.inserirVertice("0");
    grafo.inserirVertice("1");
    grafo.inserirVertice("2");
    grafo.inserirVertice("3");

    grafo.inserirArco(0,3);
    grafo.inserirArco(3,2);
    grafo.inserirArco(1,2);
    grafo.inserirArco(2,0);

    grafo.removerVertice("2");
    grafo.removerVertice("3");

    grafo.imprimir();

    return 0;
}

