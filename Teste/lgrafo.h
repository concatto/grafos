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
    vector<vector <Arco> > adjacencias;

    bool inserirVertice(string nome){
        this->nomes.push_back(nome);

        vector <Arco> vertice;
        adjacencias.push_back(vertice);

        return true;
    }

    bool inserirArco(int origem, int destino, int peso){
        Arco arco(peso, destino);
        adjacencias[origem].push_back(arco);

        return true;
    }

    vector<int> obterVerticesAdjacentes(int origem){
        vector<int> copia;

        for(Arco a: adjacencias[origem]){
            copia.push_back(a.vdestino);
        }

        return copia;
    }

    bool removerArco(int origem, int destino){
        for(int i = 0; i< adjacencias[origem].size(); i++){
            if(adjacencias[origem][i].vdestino == destino){
                adjacencias[origem].erase(adjacencias[origem].begin() + i);
                return true;
            }
        }
    }

    bool removerVertice(int vertice){
        for(int i = 0; i<adjacencias.size();i++){
            if(existeArco(i, vertice))
            {
                removerArco(i, vertice);
            }
        }
        nomes.erase(nomes.begin() + vertice);
        adjacencias.erase(adjacencias.begin() + vertice);
        return true;
    }

    bool existeArco(int origem, int destino){
        for(Arco a: adjacencias[origem]){
            if(a.vdestino == destino){
                return true;
            }
        }
        return false;
    }

    void imprimir(){
        for(int i = 0; i< nomes.size(); i++){
            cout<<nomes[i]+" => ";
            for(Arco a:adjacencias[i]){
                cout<<nomes[a.vdestino]<<"("<<a.peso<<") ";
            }
            cout<<"\n";
        }

    }

    bool existeIndice(int vertice){
        return (vertice >=0 && vertice < adjacencias.size());
    }

    int consultarPeso(int origem, int destino){
        for(Arco a: adjacencias[origem]){
            if(a.vdestino == destino){
                return a.peso;
            }
        }

    }

};




#endif // LGRAFO_H
