#ifndef LGRAFO_H
#define LGRAFO_H
#include "grafo.h"
#include <vector>

using namespace std;

struct Arco{
    int peso;
    int vdestino;

    Arco(int peso, int vdestino) {
        this->peso = peso;
        this->vdestino = vdestino;
    }
};


struct LGrafo : public Grafo {
    vector<vector<Arco>> adjacencias;

    bool inserirVertice(string nome) override {
        if (obterIndice(nome) >= 0) {
            //Existe
            return false;
        }

        this->nomes.push_back(nome);

        vector<Arco> vertice;
        adjacencias.push_back(vertice);

        return true;
    }

    bool inserirArco(int origem, int destino, int peso) override {
        if (!existeVertice(origem) || !existeVertice(destino)) {
            return false;
        }

        Arco arco(peso, destino);
        adjacencias[origem].push_back(arco);

        return true;
    }

    vector<int> obterVerticesAdjacentes(int origem) override {
        vector<int> copia;

        if (existeVertice(origem)) {
            for (Arco a : adjacencias[origem]) {
                copia.push_back(a.vdestino);
            }
        }

        return copia;
    }

    bool removerArco(int origem, int destino) override {
        if (!existeVertice(origem) || !existeVertice(destino)) {
            return false;
        }

        for (int i = 0; i < adjacencias[origem].size(); i++){
            if (adjacencias[origem][i].vdestino == destino) {
                adjacencias[origem].erase(adjacencias[origem].begin() + i);
                return true;
            }
        }

        return false;
    }

    bool removerVertice(int vertice) override {
        if (!existeVertice(vertice)) {
            return false;
        }

        for (int i = 0; i < adjacencias.size(); i++) {
            if (existeArco(i, vertice)) {
                removerArco(i, vertice);
            }
        }

        adjacencias.erase(adjacencias.begin() + vertice);
        nomes.erase(nomes.begin() + vertice);

        return true;
    }

    void imprimir() override {
        for (int i = 0; i < adjacencias.size(); i++) {
            cout << nomes[i] << " => ";

            for (int j = 0; j < adjacencias[i].size(); j++) {
                if (j > 0) {
                    cout << ", ";
                }

                Arco a = adjacencias[i][j];
                cout << nomes[a.vdestino] << "(" << a.peso << ")";
            }

            cout<<"\n";
        }
    }

    bool existeVertice(int vertice) override {
        return vertice >=0 && vertice < adjacencias.size();
    }

    int consultarPeso(int origem, int destino) override {
        if (!existeVertice(origem) || !existeVertice(destino)) {
            return 0;
        }

        for (Arco a : adjacencias[origem]) {
            if (a.vdestino == destino) {
                return a.peso;
            }
        }

        return 0;
    }

    int obterGrau(int vertice) override {
        return adjacencias[vertice].size();
    }

    void dijkstra(int vertice){
        //TODO
        (void)vertice;
    }

};




#endif // LGRAFO_H