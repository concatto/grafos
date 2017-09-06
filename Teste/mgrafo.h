#ifndef MGRAFO_H
#define MGRAFO_H
#include "grafo.h"

using namespace std;

struct MGrafo: public Grafo {
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

    bool existeIndice(int vertice) override {
        return vertice >= 0 && vertice < adjacencias.size();
    }

    bool inserirArco(int origem, int destino, int peso = 1) override {
        if (existeIndice(origem) && existeIndice(destino)) {
            this->adjacencias[origem][destino] = peso;
            return true;
        }

        return false;
    }

    void imprimir() override {
        for (int i = 0; i < this->adjacencias.size(); i++) {
            for (int j = 0; j < this->adjacencias[i].size(); j++) {
                cout<<this->adjacencias[i][j];
            }
            cout<<"\n";
        }
    }

    bool existeArco(int origem, int destino) override {
        if (consultarPeso(origem, destino) == 0)
            return false;
        return true;
    }

    vector<int> obterVerticesAdjacentes(int origem) override {
        vector<int> vetor;

        if (existeIndice(origem)) {
            for (int j = 0; j < this->adjacencias[origem].size(); j++) {
                if(existeArco(origem, j))
                    vetor.push_back(j);
            }
        }

        return vetor;
    }


    int consultarPeso(int origem, int destino) override {
        if (!existeIndice(origem) || !existeIndice(destino)) {
            return 0;
        }

        return this->adjacencias[origem][destino];
    }

    bool removerVertice(string nome) override {
        int indice = obterIndice(nome);
        if (!existeIndice(indice))
            return false;
        adjacencias.erase(adjacencias.begin() + indice);
        for (int i = 0; i < adjacencias.size(); i++) {
            adjacencias[i].erase(adjacencias[i].begin() + indice);
        }
        nomes.erase(nomes.begin() + indice);
        return true;
    }

    bool removerArco(int origem, int destino) override{
        return inserirArco(origem, destino, 0);
    }

//    void dfs_aux(string nome, vector <bool> &visitados){
//        for(int i = 0; i < nomes.size(); i++){
//            if(adjacencias[obterIndice(nome)][i] > 0 && visitados[i] == false){
//                cout<<nomes[i]<<"\n";
//                visitados[i] = true;
//                dfs_aux(nomes[i], visitados);
//            }
//        }
//    }
};

#endif // MGRAFO_H
