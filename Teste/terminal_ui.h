#ifndef TERMINAL_UI_H
#define TERMINAL_UI_H

#include <iostream>
#include "grafo.h"
using namespace std;

void inserirVertice(Grafo& grafo) {
    cout << "Digite o nome do vertice: ";
    string nome;
    cin >> nome;
    if (grafo.inserirVertice(nome)) {
        cout << "Inserido com sucesso\n";
    } else {
        cout << "Falha ao inserir o vertice\n";
    }
}

void inserirLigacao(Grafo& grafo, bool orientado, bool ponderado) {
    string origem, destino;
    cout << "Digite o nome do vertice de origem: ";
    cin >> origem;
    cout << "Digite o nome do vertice de destino: ";
    cin >> destino;

    int peso = 1;
    if (ponderado) {
        cout << "Digite o peso da ligacao: ";
        cin >> peso;
    }

    bool sucesso;
    if (orientado) {
        sucesso = grafo.inserirArco(grafo.obterIndice(origem), grafo.obterIndice(destino), peso);
    } else {
        sucesso = grafo.inserirAresta(grafo.obterIndice(origem), grafo.obterIndice(destino), peso);
    }

    if (sucesso) {
        cout << "Ligacao inserida com sucesso.\n";
    } else {
        cout << "Falha ao inserir a ligacao.\n";
    }
}

void removerVertice(Grafo& grafo) {
    string nome;
    cout << "Insira o nome do vertice a ser removido: ";
    cin >> nome;

    if (grafo.removerVertice(grafo.obterIndice(nome))) {
        cout << "Vertice removido com sucesso.\n";
    } else {
        cout << "Falha ao remover o vertice.\n";
    }
}

void removerLigacao(Grafo& grafo, bool orientado) {
    string origem, destino;
    cout << "Digite o nome do vertice de origem: ";
    cin >> origem;
    cout << "Digite o nome do vertice de destino: ";
    cin >> destino;

    bool sucesso;
    if (orientado) {
        sucesso = grafo.removerArco(grafo.obterIndice(origem), grafo.obterIndice(destino));
    } else {
        sucesso = grafo.removerAresta(grafo.obterIndice(origem), grafo.obterIndice(destino));
    }

    if (sucesso) {
        cout << "Ligacao removida com sucesso.\n";
    } else {
        cout << "Falha ao remover a ligacao.\n";
    }
}

void consultarAdjacentes(Grafo& grafo) {
    cout << "Informe o nome do vertice desejado: ";
    string nome;
    cin >> nome;

    int indice = grafo.obterIndice(nome);
    if (grafo.existeVertice(indice)) {
        for (int v : grafo.obterVerticesAdjacentes(indice)) {
            cout << grafo.obterNome(v) << "\n";
        }
    } else {
        cout << "O vertice nao existe.\n";
    }
}

void buscaEmLargura(Grafo& grafo) {
    cout << "Informe o nome do vertice de origem: ";
    string origem;
    cin >> origem;

    int indiceOrigem = grafo.obterIndice(origem);
    if (!grafo.existeVertice(indiceOrigem)) {
        cout << "O vertice nao existe.\n";
        return;
    }

    int destino = -1;
    cout << "A busca possui destino? (s/n): ";
    char op;
    cin >> op;
    if (op == 's' || op == 'S') {
        cout << "Informe o nome do vertice de destino: ";
        string destino;
        cin >> destino;
        destino = grafo.obterIndice(destino);
    }

    grafo.buscaEmLargura(indiceOrigem, destino);
}

void buscaEmProfundidade(Grafo& grafo) {
    cout << "Informe o nome do vertice de origem: ";
    string origem;
    cin >> origem;

    int indiceOrigem = grafo.obterIndice(origem);
    if (!grafo.existeVertice(indiceOrigem)) {
        cout << "O vertice nao existe.\n";
        return;
    }

    int destino = -1;
    cout << "A busca possui destino? (s/n): ";
    char op;
    cin >> op;
    if (op == 's' || op == 'S') {
        cout << "Informe o nome do vertice de destino: ";
        string destino;
        cin >> destino;
        destino = grafo.obterIndice(destino);
    }

    grafo.buscaEmProfundidade(indiceOrigem, destino);
}

#endif // TERMINAL_UI_H
