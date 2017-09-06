#ifndef GRAFO_H
#define GRAFO_H
#include <vector>
#include <string>

using namespace std;

struct Grafo {
    vector<string> nomes;

    virtual bool inserirVertice(string nome) = 0;
    virtual bool existeIndice(int vertice) = 0;
    virtual bool inserirArco(int origem, int destino, int peso = 1) = 0;
    virtual void imprimir() = 0;
    virtual bool existeArco(int origem, int destino) = 0;
    virtual vector<int> obterVerticesAdjacentes(int origem) = 0;
    virtual bool removerArco(int origem, int destino) = 0;
    virtual int consultarPeso(int origem, int destino) = 0;
    virtual bool removerVertice(string nome) = 0;

    //Remove o arco origem -> destino e o arco destino -> origem
    bool removerAresta(int origem, int destino){
        if(removerArco(origem, destino)){
            removerArco(destino, origem);
            return true;
        }
        return false;
    }

    //Descobre o índice do vértice a partir de um nome. Caso não exista, retorna -1
    int obterIndice(string nome) {
        for(int i = 0; i < nomes.size(); i++){
            if(nome == nomes[i]){
                return i;
            }
        }
        return -1;
    }

    //Insere um arco origem -> destino e um arco destino -> origem, ambos com o peso especificado
    bool inserirAresta(int origem, int destino, int peso) {
        if (inserirArco(origem, destino, peso)) {
            inserirArco(destino, origem, peso);
            return true;
        }
        return false;
    }

    void dfs_aux2(int vertice, vector <bool> &visitados){
        vector <int> adj = obterVerticesAdjacentes(vertice);

        for(int i = 0; i < adj.size(); i++){
            if(visitados[adj[i]] == false){
                cout<<nomes[adj[i]]<<"\n";
                visitados[adj[i]] = true;
                dfs_aux2(adj[i], visitados);
            }
        }
    }

    //Realiza uma busca em profundidade (DFS) sem destino.
    void buscaEmProfundidade(int origem) {
        if(!existeIndice(origem))
            return;

        vector <bool> visitados;

        for(int i = 0; i < nomes.size(); i++){
            visitados.push_back(false);
        }

        visitados[origem] = true;
        cout<<nomes[origem]<<"\n";

        dfs_aux2(origem, visitados);

        for(int i = 0; i < visitados.size(); i++){
            if(visitados[i] == false){
                cout<<nomes[i]<<"\n";
                visitados[i] = true;
                dfs_aux2(i, visitados);
            }
        }
    }

    //Realiza uma busca em largura (BFS) sem destino.
    void buscaEmLargura(int origem) {
        //TODO
    }
};

#endif // GRAFO_H
