#ifndef GRAFO_H
#define GRAFO_H
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct Path{
    //int vertice;
    int distancia;
    int anterior;
    bool aberto;

    Path(){
        anterior = -1;
        distancia = -1;
        aberto = true;
    }

};


struct Grafo {
    vector<string> nomes;

    virtual bool inserirVertice(string nome) = 0;
    virtual bool existeVertice(int vertice) = 0;
    virtual bool inserirArco(int origem, int destino, int peso = 1) = 0;
    virtual void imprimir() = 0;
    virtual vector<int> obterVerticesAdjacentes(int origem) = 0;
    virtual bool removerArco(int origem, int destino) = 0;
    virtual int consultarPeso(int origem, int destino) = 0;
    virtual bool removerVertice(int vertice) = 0;
    virtual int obterGrau(int vertice) = 0;

    //Acho que agora foi, rapazeada, esperando o aval do mestre Fernando.
    void dijkstra(int origem){
        vector <Path> lista(nomes.size());
        priority_queue <pair<int, int>> pq;

        int backup = origem;

        //lista[vertice].aberto = false;
        lista[origem].distancia = 0;
        lista[origem].anterior = -1;

        pq.push(make_pair(lista[origem].distancia, origem));

        while(!pq.empty()){
            origem = pq.top().second;
            pq.pop();
            lista[origem].aberto = false;
            for(int adj : obterVerticesAdjacentes(origem)){
                if(lista[adj].aberto == true){
                    pq.push(make_pair(lista[adj].distancia, adj));
                }
                if((lista[adj].distancia == -1) || (lista[adj].distancia > consultarPeso(origem, adj) + lista[origem].distancia)){
                    lista[adj].distancia = consultarPeso(origem, adj) + lista[origem].distancia;
                    lista[adj].anterior = origem;
                }
            }
        }

        for(int i = 0; i < lista.size(); i++){
            if(i == backup)
                lista[i].anterior = backup;
            cout<<"\n"<<"Vertice: "<<nomes[i]<<" - Anterior: "<<nomes[lista[i].anterior]<<" - Distancia: "<<lista[i].distancia;
        }
        cout<<"\n";
    }

    string obterNome(int vertice) {
        return this->nomes[vertice];
    }

    //Remove o arco origem -> destino e o arco destino -> origem
    bool removerAresta(int origem, int destino) {
        if (removerArco(origem, destino)) {
            removerArco(destino, origem);
            return true;
        }
        return false;
    }

    //Descobre o índice do vértice a partir de um nome. Caso não exista, retorna -1
    int obterIndice(string nome) {
        for (int i = 0; i < nomes.size(); i++) {
            if (nome == nomes[i]) {
                return i;
            }
        }
        return -1;
    }

    //Insere um arco origem -> destino e um arco destino -> origem, ambos com o peso especificado
    bool inserirAresta(int origem, int destino, int peso = 1) {
        if (inserirArco(origem, destino, peso)) {
            inserirArco(destino, origem, peso);
            return true;
        }
        return false;
    }

    //Descobre se existe um arco origem -> destino através do peso entre os mesmos
    bool existeArco(int origem, int destino) {
        if (consultarPeso(origem, destino) == 0)
            return false;

        return true;
    }

    bool existaAresta(int origem, int destino) {
        return existeArco(origem, destino) && existeArco(destino, origem);
    }

    bool buscaEmProfundidadePrincipal(int vertice, vector <bool> &visitados, int destino) {
        vector<int> adj = obterVerticesAdjacentes(vertice);

        for (int i = 0; i < adj.size(); i++) {
            if (visitados[adj[i]] == false) {
                cout << nomes[adj[i]] << "\n";
                visitados[adj[i]] = true;

                if (adj[i] == destino) {
                    return true;
                }

                if (buscaEmProfundidadePrincipal(adj[i], visitados, destino)) {
                    return true;
                }
            }
        }

        return false;
    }

    //Realiza uma busca em profundidade (DFS) sem destino.
    void buscaEmProfundidade(int origem, int destino = -1) {
        if (!existeVertice(origem))
            return;

        vector<bool> visitados(nomes.size(), false);

        visitados[origem] = true;
        cout << nomes[origem] << "\n";

        buscaEmProfundidadePrincipal(origem, visitados, destino);

        if (destino != -1) return;

        for (int i = 0; i < visitados.size(); i++) {
            if (visitados[i] == false){
                cout << nomes[i] << "\n";
                visitados[i] = true;
                buscaEmProfundidadePrincipal(i, visitados, destino);
            }
        }
    }

    void buscaEmLarguraPrincipal(int origem, vector<bool> &visitados, int destino) {
        if(!existeVertice(origem))
            return;

        queue<int> fila;
        fila.push(origem);

        while(!fila.empty()) {
            int frente = fila.front();
            fila.pop();
            visitados[frente] = true;
            cout << nomes[frente] << "\n";

            if (destino == frente) {
                return;
            }

            vector<int> adj = obterVerticesAdjacentes(frente);

            for (int v : adj){
                if (visitados[v] == false){
                    fila.push(v);
                }
            }
        }
    }

    //Realiza uma busca em largura (BFS) sem destino.
    void buscaEmLargura(int origem, int destino = -1) {
        vector<bool> visitados(nomes.size(), false);
        buscaEmLarguraPrincipal(origem, visitados, destino);

        if (destino != -1) return;

        for (int i = 0; i < visitados.size(); i++) {
            if (visitados[i] == false) {
                buscaEmLarguraPrincipal(i, visitados, destino);
            }
        }
    }
};

#endif // GRAFO_H
