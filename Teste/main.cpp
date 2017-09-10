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
    grafo.inserirAresta(grafo.obterIndice("A"), grafo.obterIndice("B"));
    grafo.inserirAresta(grafo.obterIndice("A"), grafo.obterIndice("D"));
    grafo.inserirAresta(grafo.obterIndice("C"), grafo.obterIndice("D"));

    grafo.imprimir();
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

