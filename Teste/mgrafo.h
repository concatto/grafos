#ifndef MGRAFO_H
#define MGRAFO_H
#include "grafo.h"

using namespace std;

struct MGrafo: public Grafo {
    vector<vector <int>> adjacencias;

    bool inserirVertice(string nome) override{
        if (obterIndice(nome) >= 0) {
            //Nome já existe
            return false;
        }
        this->nomes.push_back(nome);
        uint tam = this->adjacencias.size();
        vector<int> vetor;
        for(uint i=0; i<tam; i++){
            vetor.push_back(0);
        }
        //Nova linha (cresce verticalmente)
        this->adjacencias.push_back(vetor);

        //Nova coluna (cresce horizontalmente
        for(uint i=0; i<this->adjacencias.size(); i++){
            this->adjacencias[i].push_back(0);
        }

        return true;
    }

    bool existeIndice(uint vertice) override{
        return vertice < adjacencias.size();
    }

    bool inserirArco(uint origem, uint destino, int peso = 1) override{
        if (existeIndice(origem) && existeIndice(destino)) {
            this->adjacencias[origem][destino] = peso;
            return true;
        }

        return false;
    }

    void imprimir() override{
        for(uint i=0; i<this->adjacencias.size(); i++){
            for(uint j=0; j<this->adjacencias[i].size(); j++){
                cout<<this->adjacencias[i][j];
            }
            cout<<"\n";
        }
    }

    bool existeArco(uint origem, uint destino) override{
        if(consultarPeso(origem, destino) == 0)
            return false;
        return true;
    }

    vector<int> obterVerticesAdjacentes(uint origem) override{
        vector<int> vetor;

        if (existeIndice(origem)) {
            for(uint j=0; j<this->adjacencias[origem].size();j++){
                if(existeArco(origem, j))
                    vetor.push_back(j);
            }
        }

        return vetor;
    }


    int consultarPeso(uint origem, uint destino) override{
        if (!existeIndice(origem) || !existeIndice(destino)) {
            return 0;
        }

        return this->adjacencias[origem][destino];
    }

    bool removerVertice(string nome) override{
        uint indice = obterIndice(nome);
        if(!existeIndice(indice))
            return false;
        adjacencias.erase(adjacencias.begin() + indice);
        for(uint i = 0; i < adjacencias.size(); i++){
            adjacencias[i].erase(adjacencias[i].begin() + indice);
        }
        nomes.erase(nomes.begin() + indice);
        return true;
    }

    bool removerArco(uint origem, uint destino) override{
        return inserirArco(origem, destino, 0);
    }

    void dfs_aux(string nome, vector <bool> &visitados){
        for(uint i = 0; i < nomes.size(); i++){
            if(adjacencias[obterIndice(nome)][i] > 0 && visitados[i] == false){
                cout<<nomes[i]<<"\n";
                visitados[i] = true;
                dfs_aux(nomes[i], visitados);
            }
        }
    }

    void dfs_aux2(string nome, vector <bool> &visitados){
        vector <int> adj = obterVerticesAdjacentes(obterIndice(nome));

        for(uint i = 0; i < adj.size(); i++){
            if(visitados[adj[i]] == false){
                cout<<nomes[adj[i]]<<"\n";
                visitados[adj[i]] = true;
                dfs_aux2(nomes[adj[i]], visitados);
            }
        }
    }

    void dfs(string nome){
        int indice = obterIndice(nome);

        if(indice == -1)
            return;

        vector <bool> visitados;

        for(uint i = 0; i < nomes.size(); i++){
            visitados.push_back(false);
        }

        visitados[indice] = true;
        cout<<nomes[indice]<<"\n";

        dfs_aux2(nome, visitados);

        for(uint i = 0; i < visitados.size(); i++){
            if(visitados[i] == false){
                cout<<nomes[i]<<"\n";
                visitados[i] = true;
                dfs_aux2(nome, visitados);
            }
        }

    }

};

#endif // MGRAFO_H
