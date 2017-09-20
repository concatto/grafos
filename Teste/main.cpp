#include <iostream>
#include <vector>
#include <locale>
#include <cstdlib>
#include <limits>
#include "grafo.h"
#include "mgrafo.h"
#include "lgrafo.h"
#include "terminal_ui.h"
//#include "userInterface/graphicsview.h"
#include <QApplication>
#include "controller.h"

using namespace std;

void limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void aguardarTecla() {
    cout << "\nPressione qualquer tecla para continuar...\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
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

void menuPrincipal(Grafo& grafo) {
    cout << "Deseja carregar o grafo de testes?\n";
    bool teste = exibirMenu({"Sim", "Nao"}) == 0;
    if (teste) {
        grafo.inserirVertice("A");
        grafo.inserirVertice("B");
        grafo.inserirVertice("C");
        grafo.inserirVertice("D");
        grafo.inserirVertice("E");
        grafo.inserirVertice("F");
        grafo.inserirVertice("G");
        grafo.inserirVertice("H");
        grafo.inserirVertice("I");
        grafo.inserirVertice("J");
        grafo.inserirVertice("K");
        grafo.inserirVertice("L");
        grafo.inserirVertice("M");
        grafo.inserirAresta(0, 1);
        grafo.inserirAresta(0, 10);
        grafo.inserirAresta(1, 2);
        grafo.inserirAresta(1, 4);
        grafo.inserirAresta(1, 10);
        grafo.inserirAresta(2, 3);
        grafo.inserirAresta(2, 4);
        grafo.inserirAresta(3, 4);
        grafo.inserirAresta(4, 5);
        grafo.inserirAresta(4, 7);
        grafo.inserirAresta(4, 10);
        grafo.inserirAresta(5, 6);
        grafo.inserirAresta(6, 7);
        grafo.inserirAresta(7, 8);
        grafo.inserirAresta(7, 10);
        grafo.inserirAresta(8, 9);
        grafo.inserirAresta(8, 12);
        grafo.inserirAresta(9, 10);
        grafo.inserirAresta(9, 11);
        grafo.inserirAresta(9, 10);
    }

    cout << "Escolha a orientacao do grafo\n";
    bool orientado = exibirMenu({"Orientado", "Nao orientado"}) == 0;
    cout << "Escolha o tipo de grafo\n";
    bool ponderado = exibirMenu({"Ponderado", "Nao ponderado"}) == 0;

    bool finalizado = false;
    do {
        cout << "Selecione a operacao desejada.\n";
        int opcao = exibirMenu({
            "Inserir vertice",
            "Inserir " + string(orientado ? "arco" : "aresta"),
            "Remover vertice",
            "Remover " + string(orientado ? "arco" : "aresta"),
            "Consultar vertices adjacentes",
            "Busca em Largura",
            "Busca em Profundidade",
            "Imprimir",
            "Sair"
        });

        switch (opcao) {
        case 0:
            inserirVertice(grafo);
            break;
        case 1:
            inserirLigacao(grafo, orientado, ponderado);
            break;
        case 2:
            removerVertice(grafo);
            break;
        case 3:
            removerLigacao(grafo, orientado);
            break;
        case 4:
            consultarAdjacentes(grafo);
            break;
        case 5:
            buscaEmLargura(grafo);
            break;
        case 6:
            buscaEmProfundidade(grafo);
            break;
        case 7:
            grafo.imprimir();
            break;
        default:
            finalizado = true;
            break;
        }

        if (!finalizado) {
            aguardarTecla();
            limparTela();
        }
    } while (!finalizado);
}

int main(int argc, char *argv[]) {
    /*
    LGrafo grafo;
    grafo.inserirVertice("A");
    grafo.inserirVertice("B");
    grafo.inserirVertice("C");
    grafo.inserirVertice("D");
    grafo.inserirVertice("E");
    grafo.inserirVertice("F");
    grafo.inserirVertice("G");
    grafo.inserirVertice("H");
    grafo.inserirVertice("I");
    grafo.inserirAresta(grafo.obterIndice("A"), grafo.obterIndice("D"), 6);

    grafo.inserirAresta(grafo.obterIndice("A"), grafo.obterIndice("E"), 8);

    grafo.inserirAresta(grafo.obterIndice("E"), grafo.obterIndice("B"), 1);

    grafo.inserirAresta(grafo.obterIndice("C"), grafo.obterIndice("E"), 4);

    grafo.inserirAresta(grafo.obterIndice("B"), grafo.obterIndice("D"), 5);

    grafo.inserirAresta(grafo.obterIndice("B"), grafo.obterIndice("C"), 2);

    grafo.inserirAresta(grafo.obterIndice("C"), grafo.obterIndice("F"), 10);
    grafo.inserirAresta(grafo.obterIndice("F"), grafo.obterIndice("G"), 30);
    grafo.inserirAresta(grafo.obterIndice("F"), grafo.obterIndice("H"), 10);
    grafo.inserirAresta(grafo.obterIndice("H"), grafo.obterIndice("I"), 10);
    grafo.inserirAresta(grafo.obterIndice("G"), grafo.obterIndice("I"), 5);

    grafo.imprimir();
    grafo.dijkstra(0);

    return 0;

    cout << "Boas vindas a interface de grafos.\n";
    cout << "Selecione o tipo de estrutura desejada.\n";
    int estrutura = exibirMenu({"Matriz de Adjacencias", "Lista de Adjacencias"});

    if (estrutura == 0) {
        MGrafo g;
        menuPrincipal(g);
    } else if (estrutura == 1) {
        LGrafo g;
        menuPrincipal(g);
    }*/

    QApplication a(argc, argv);
    Controller controller;

    return a.exec();
}

