#include <iostream>
#include <vector>
#include <locale>
#include "grafo.h"
#include "mgrafo.h"

using namespace std;

void menuPrincipal(Grafo& grafo) {

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
        //...
    }

    return 0;

    MGrafo grafo;

    grafo.inserirVertice("A");
    grafo.inserirVertice("B");
    grafo.inserirVertice("C");
    grafo.inserirVertice("D");

    grafo.inserirArco(0,3);
    grafo.inserirArco(3,2);
    grafo.inserirArco(1,2);
    grafo.inserirArco(2,0);

    grafo.buscaEmProfundidade(grafo.obterIndice("D"));
//    grafo.imprimir();

    return 0;
}

