#ifndef MGRAFO_H
#define MGRAFO_H
#include "grafo.h"

using namespace std;

struct MGrafo : public Grafo {
    vector<vector<int>> adjacencias;

    bool inserirVertice(string nome) override {
        if (obterIndice(nome) >= 0) {
            //Nome já existe
            return false;
        }
        this->nomes.push_back(nome);
        int tam = this->adjacencias.size();
        vector<int> vetor;
        for (int i = 0; i < tam; i++){
            vetor.push_back(0);
        }
        //Nova linha (cresce verticalmente)
        this->adjacencias.push_back(vetor);

        //Nova coluna (cresce horizontalmente
        for (int i = 0; i < this->adjacencias.size(); i++){
            this->adjacencias[i].push_back(0);
        }

        return true;
    }

    bool existeVertice(int vertice) override {
        return vertice >= 0 && vertice < adjacencias.size();
    }

    bool inserirArco(int origem, int destino, int peso) override {
        if (!existeVertice(origem) || !existeVertice(destino)) {
            return false;
        }

        this->adjacencias[origem][destino] = peso;
        return true;
    }

    void imprimir() override {
        for (int i = 0; i < this->adjacencias.size(); i++) {
            cout << "|";

            for (int j = 0; j < this->adjacencias[i].size(); j++) {
                cout << this->adjacencias[i][j] << "|";
            }

            cout << "\n";
        }

        cout << "\n";
        for (int i = 0; i < this->nomes.size(); i++) {
            cout << i << ": " << this->nomes[i] << "\n";
        }
    }

    vector<int> obterVerticesAdjacentes(int origem) override {
        vector<int> vetor;

        if (existeVertice(origem)) {
            for (int j = 0; j < this->adjacencias[origem].size(); j++) {
                if (existeArco(origem, j))
                    vetor.push_back(j);
            }
        }

        return vetor;
    }


    int consultarPeso(int origem, int destino) override {
        if (!existeVertice(origem) || !existeVertice(destino)) {
            return 0;
        }

        return this->adjacencias[origem][destino];
    }

    bool removerVertice(int vertice) override {
        if (!existeVertice(vertice))
            return false;

        adjacencias.erase(adjacencias.begin() + vertice);
        for (int i = 0; i < adjacencias.size(); i++) {
            adjacencias[i].erase(adjacencias[i].begin() + vertice);
        }

        nomes.erase(nomes.begin() + vertice);
        return true;
    }

    bool removerArco(int origem, int destino) override {
        return inserirArco(origem, destino, 0);
    }

    int obterGrau(int vertice) override {
        return obterVerticesAdjacentes(vertice).size();
    }

};

#endif // MGRAFO_H
