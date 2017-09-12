#include <iostream>
#include <vector>
#include <locale>
#include "grafo.h"
#include "mgrafo.h"
#include "lgrafo.h"

using namespace std;

void menuPrincipal(Grafo& grafo) {
    grafo.inserirVertice("A");
    grafo.inserirVertice("B");
    grafo.inserirVertice("C");
    grafo.inserirVertice("D");
    grafo.inserirVertice("E");
    grafo.inserirVertice("F");
    grafo.inserirAresta(grafo.obterIndice("A"), grafo.obterIndice("D"), 6);

    grafo.inserirAresta(grafo.obterIndice("A"), grafo.obterIndice("E"), 8);

    grafo.inserirAresta(grafo.obterIndice("E"), grafo.obterIndice("B"), 1);

    grafo.inserirAresta(grafo.obterIndice("C"), grafo.obterIndice("E"), 4);

    grafo.inserirAresta(grafo.obterIndice("B"), grafo.obterIndice("D"), 5);

    grafo.inserirAresta(grafo.obterIndice("B"), grafo.obterIndice("C"), 2);

    grafo.imprimir();
    grafo.dijkstra(0);
}

int exibirMenu(vector<string> opcoes) {
    for (int i = 0; i < opcoes.size(); i++) {
        cout << (i + 1) << " - " << opcoes[i] << "\n";
    }

    int opcao;
    bool valida;
    do {
        cout << "Opcao: ";
        cin >> opcao;

        opcao--;
        valida = opcao >= 0 && opcao < opcoes.size();
        if (!valida) {
            cout << "Opcao invalida.\n";
        }
    } while (!valida);

    return opcao;
}

int main()
{
    cout << "Boas vindas a interface de grafos.\n";
    cout << "Selecione o tipo de estrutura desejada.\n";
    int estrutura = exibirMenu({"Matriz de Adjacencias", "Lista de Adjacencias"});

    if (estrutura == 0) {
        MGrafo g;
        menuPrincipal(g);
    } else if (estrutura == 1) {
        LGrafo g;
        menuPrincipal(g);
    }

    return 0;
}

