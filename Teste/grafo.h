#ifndef GRAFO_H
#define GRAFO_H
#include <vector>
#include <string>
#include <QDebug>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct Dsatur {
    int id;
    int grau;
    int sat;
    int cor;
};

struct WashPowell {
    int id;
    int grau;
    int cor;

};

struct Path{
    //int vertice;
    int distancia;
    int anterior;
    bool aberto;
//    int ordem = -1;

    Path(){
        anterior = -1;
        distancia = -1;
        aberto = true;
    }
};

struct ComparePair {
    bool operator()(pair <int, int> p1, pair <int, int> p2){
        return p1.first > p2.first;
    }
};

inline bool operator > (Dsatur d1, Dsatur d2){
    if(d1.sat > d2.sat)
        return true;
    else if(!(d1.sat > d2.sat))
        return false;
    else
        return d1.grau > d2.grau;
}

inline bool operator < (Dsatur d1, Dsatur d2){
    return d1.grau > d2.grau;
}

inline bool operator < (WashPowell w1, WashPowell w2){
    return w1.grau > w2.grau;
}

inline bool compareWelshSort(WashPowell w1, WashPowell w2){
    return w1.id < w2.id;
}

inline bool compareDsatur(Dsatur d1, Dsatur d2){
    return d1.id < d2.id;
}

struct Arco {
    int peso;
    int vdestino;

    Arco(int peso, int vdestino) {
        this->peso = peso;
        this->vdestino = vdestino;
    }
};


struct Grafo{
public:
    vector<string> nomes;

    virtual bool inserirVertice(string nome) = 0;
    virtual bool existeVertice(int vertice) = 0;
    virtual bool inserirArco(int origem, int destino, int peso = 1) = 0;
    virtual void imprimir() = 0;
    virtual vector<int> obterVerticesAdjacentes(int origem) = 0;
    virtual vector<Arco> obterVerticesAdjacentesComPeso(int origem) = 0;
    virtual bool removerArco(int origem, int destino) = 0;
    virtual int consultarPeso(int origem, int destino) = 0;
    virtual bool removerVertice(int vertice) = 0;
    virtual int obterGrau(int vertice) = 0;

    void dsaturAumentaSat(vector <Dsatur> &listaDsatur, int origem){
        for(Dsatur &l: listaDsatur){
            if(l.id != origem && consultarPeso(origem, l.id) > 0){
                l.sat++;
            }
        }
    }

    int pegaProximoDsatur(const vector <Dsatur> &listaDsatur){
        Dsatur v;
        v.sat = -1;
        v.grau = 0;

        for(int i = 0; i < listaDsatur.size(); i++){
            if(listaDsatur[i] > v && listaDsatur[i].cor == -1){
                v.id = i;
                v.grau = listaDsatur[i].grau;
                v.sat = listaDsatur[i].sat;
            }
        }

        return v.id;
    }

    bool analisaVizinhosDsatur(const vector <Dsatur> &listaDsatur, int origem, int cor){
        for(Dsatur l: listaDsatur){
            if(l.id != origem && consultarPeso(origem, l.id) > 0 && l.cor == cor){
                return false;
            }
        }
        return true;
    }

    vector<Dsatur> dsatur(){
        vector <Dsatur> listaDsatur(nomes.size());

        int counter = 0;
        int corAtual = 0;
        int verticeAtual = 0;

        for(int i = 0; i < listaDsatur.size(); i++){
            listaDsatur[i].id = i;
            listaDsatur[i].cor = -1;
            listaDsatur[i].sat = 0;
            listaDsatur[i].grau = obterGrau(i);
        }

        sort(listaDsatur.begin(), listaDsatur.end());

        listaDsatur[0].cor = corAtual;
        dsaturAumentaSat(listaDsatur, listaDsatur[0].id);
        counter = 1;

        while(counter < listaDsatur.size()){

            verticeAtual = pegaProximoDsatur(listaDsatur);

            while(!analisaVizinhosDsatur(listaDsatur, listaDsatur[verticeAtual].id, corAtual)){
                corAtual++;
            }

            listaDsatur[verticeAtual].cor = corAtual;
            dsaturAumentaSat(listaDsatur, listaDsatur[verticeAtual].id);

            counter++;
            corAtual = 0;

        }

//        for(Dsatur l: listaDsatur){
//            qDebug()<<"Vértice: "<<QString::fromStdString(obterNome(l.id))<<" - "<<l.cor;
//        }

        return listaDsatur;
    }

    vector<int> dsatur_2() {
        imprimir();

        vector<int> cores(nomes.size(), -1);
        vector<int> saturacao(nomes.size(), 0);
        vector<int> graus;

        for (int i = 0; i < nomes.size(); i++) {
            graus.push_back(obterGrau(i));
        }

        while (true) {
            int maior = -1;
            for (int i = 0; i < nomes.size(); i++) {
                if (cores[i] == -1) {
                    if (maior == -1 || saturacao[i] > saturacao[maior]) {
                        maior = i;
                    } else if (saturacao[i] == saturacao[maior] && graus[i] > graus[maior]) {
                        maior = i;
                    }
                }
            }

            if (maior == -1) {
                break;
            }

            int cor;
            for (cor = 0; cor < nomes.size(); cor++) {
                bool invalido = false;
                for (int vizinho : obterVerticesAdjacentes(maior)) {
                    if (cores[vizinho] == cor) {
                        invalido = true;
                    }
                }

                if (!invalido) {
                    break;
                }
            }

            cores[maior] = cor;
            for (int vizinho : obterVerticesAdjacentes(maior)) {
                bool invalida = false;
                for (int vizinho2 : obterVerticesAdjacentes(vizinho)) {
                    if (vizinho2 != maior && cores[vizinho2] == cor) {
                        invalida = true;
                    }
                }

                if (!invalida) {
                    saturacao[vizinho]++;
                }
            }
        }

        for (int i = 0; i < cores.size(); i++) {
            qDebug() << cores[i];
        }

        return cores;
    }

    bool washAux(vector <WashPowell> listaWp, int cor, int origem){

        for(WashPowell l: listaWp){
            if(l.id != origem && consultarPeso(origem, l.id) > 0 && l.cor == cor){
                return false;
            }
        }
        return true;
    }

    vector<int> washPowell(){
        vector <WashPowell> listaWp(nomes.size());
        vector <int> cores;
        int corAtual = 0;
        int counter = 0;

        for(int i = 0; i < listaWp.size(); i++){
            listaWp[i].id = i;
            listaWp[i].grau = obterGrau(i);
            listaWp[i].cor = -1;
        }

        sort(listaWp.begin(), listaWp.end());

        for(WashPowell &i : listaWp) {
            if(counter == nomes.size())
                break;

            if(i.cor != -1)
                continue;

            while(!washAux(listaWp, corAtual, i.id)){
                corAtual++;
            }

            i.cor = corAtual;
            counter++;

            for(WashPowell &w : listaWp){
                if(w.id != i.id && w.cor == -1 && consultarPeso(i.id, w.id) == 0 && washAux(listaWp, corAtual, w.id)){
                    w.cor = corAtual;
                    counter++;
                }
            }

        }

        for(WashPowell l: listaWp){
            cores.push_back(l.cor);
        }

        return cores;

    }
//    virtual vector<int> obterVerticesNaoAdjacentes(int origem) = 0;

    //Acho que agora foi, rapazeada, esperando o aval do mestre Fernando.
    vector <Path> dijkstra(int origem, int destino = -1){
        vector <Path> lista(nomes.size());
        priority_queue <pair<int, int>, std::vector<pair<int, int>>, ComparePair> pq;

        int backup = origem;

        lista[origem].distancia = 0;
        lista[origem].anterior = -1;

        pq.push(make_pair(lista[origem].distancia, origem));

        while(!pq.empty()){
            origem = pq.top().second;
            if(origem == destino){
                for(int i = 0; i < lista.size(); i++){
                    if(i == backup)
                        lista[i].anterior = backup;
                    cout<<"\n"<<"Vertice: "<<nomes[i]<<" - Anterior: "<<nomes[lista[i].anterior]<<" - Distancia: "<<lista[i].distancia;
                }

                cout<<"\n";
                return lista;
            }
            pq.pop();
            lista[origem].aberto = false;
            for(int adj : obterVerticesAdjacentes(origem)){
                if((lista[adj].distancia == -1) || (lista[adj].distancia > consultarPeso(origem, adj) + lista[origem].distancia)){
                    lista[adj].distancia = consultarPeso(origem, adj) + lista[origem].distancia;
                    lista[adj].anterior = origem;
                }
                if(lista[adj].aberto == true){
                    pq.push(make_pair(lista[adj].distancia, adj));
//                    lista[adj].ordem = counter;
//                    counter++;
                }
            }
        }

        for(int i = 0; i < lista.size(); i++){
            if(i == backup)
                lista[i].anterior = backup;
            cout<<"\n"<<"Vertice: "<<nomes[i]<<" - Anterior: "<<nomes[lista[i].anterior]<<" - Distancia: "<<lista[i].distancia;
        }

        cout<<"\n";
        return lista;
    }

    //Recupera o nome do vértice desejado. Se não existir, retorna a string vazia.
    string obterNome(int vertice) {
        if (!existeVertice(vertice)) {
            return string();
        }

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
        if (existeAresta(origem, destino)) {
            return false;
        }

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

    //Verifica se existe uma aresta entre o vértice origem e o vértice destino.
    bool existeAresta(int origem, int destino) {
        return existeArco(origem, destino) && existeArco(destino, origem);
    }

    //Procedimento que executa a busca em profundidade propriamente dita.
    vector<int> buscaEmProfundidadePrincipal(int vertice, vector <bool> &visitados, int destino) {
        visitados[vertice] = true;

        //A sequência de vértices visitados desta invocação começa com o próprio vértice
        vector<int> sequencia{vertice};
        if (vertice == destino) {
            return sequencia;
        }

        vector<int> adj = obterVerticesAdjacentes(vertice);

        for (int i = 0; i < adj.size(); i++) {
            if (visitados[adj[i]] == false) {
                vector<int> adicoes = buscaEmProfundidadePrincipal(adj[i], visitados, destino);

                //Insere os vértices visitados pela chamada recursiva na própria sequência
                sequencia.insert(sequencia.end(), adicoes.begin(), adicoes.end());

                //Se o destino foi atingido, parar
                if (sequencia.back() == destino) {
                    return sequencia;
                }
            }
        }

        return sequencia;
    }

    //Realiza uma busca em profundidade (DFS). Um destino igual a -1 indica nenhum destino.
    vector<int> buscaEmProfundidade(int origem, int destino = -1) {
        if (!existeVertice(origem))
            return vector<int>();

        vector<bool> visitados(nomes.size(), false);
        vector<int> sequencia = buscaEmProfundidadePrincipal(origem, visitados, destino);

        //Sem destino?
        if (destino == -1) {
            for (int i = 0; i < visitados.size(); i++) {
                if (visitados[i] == false){
                    vector<int> extra = buscaEmProfundidadePrincipal(i, visitados, destino);
                    sequencia.insert(sequencia.end(), extra.begin(), extra.end());
                }
            }
        }

        return sequencia;
    }

    //Procedimento que executa a busca em largura propriamente dita.
    vector<int> buscaEmLarguraPrincipal(int origem, vector<bool> &visitados, int destino) {
        if (!existeVertice(origem))
            return vector<int>();

        vector<int> sequencia;
        deque<int> fila;
        fila.push_back(origem);
        visitados[origem] = true;

        while (!fila.empty()) {
            int frente = fila.front();
            fila.pop_front();
            sequencia.push_back(frente);

            //Destino foi atingido; parar o algoritmo.
            if (destino == frente) {
                break;
            }

            vector<int> adj = obterVerticesAdjacentes(frente);

            for (int v : adj) {
                if (visitados[v] == false) {
                    //Marcar como visitado assim que inserir na fila.
                    visitados[v] = true;
                    fila.push_back(v);
                }
            }
        }

        return sequencia;
    }

    //Realiza uma busca em largura (BFS). Um destino igual a -1 indica nenhum destino.
    vector<int> buscaEmLargura(int origem, int destino = -1) {
        vector<bool> visitados(nomes.size(), false);
        vector<int> sequencia = buscaEmLarguraPrincipal(origem, visitados, destino);

        //Se não há destino, reiniciar a busca em componentes não atingidos
        if (destino == -1) {
            for (int i = 0; i < visitados.size(); i++) {
                if (visitados[i] == false) {
                    vector<int> extra = buscaEmLarguraPrincipal(i, visitados, destino);

                    sequencia.insert(sequencia.end(), extra.begin(), extra.end());
                }
            }
        }

        return sequencia;
    }

};

#endif // GRAFO_H
