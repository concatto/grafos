#ifndef GRAFO_H
#define GRAFO_H
#include <vector>
#include <string>
#include <queue>
#include <QObject>
#include <QDebug>

using namespace std;

struct WashPowell {
    int id;
    int grau;
    int cor;

};

inline bool operator < (WashPowell w1, WashPowell w2){
    return w1.grau > w2.grau;
}

struct Arco {
    int peso;
    int vdestino;

    Arco(int peso, int vdestino) {
        this->peso = peso;
        this->vdestino = vdestino;
    }
};

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

struct Grafo : public QObject{
    Q_OBJECT
public slots:
    void addVertex(QString str){
        inserirVertice(str.toStdString());
    }
    void removeVertex(QString str){
        if(removerVertice(obterIndice(str.toStdString()))){
            qDebug()<<"Removido com sucesso";
        }
    }

    void addConnection(QString name1, QString name2, int weight = 1){
        qDebug()<<"Pensar";
//        inserirAresta(obterIndice(name1), obterIndice(name2), weight);
    }

    void removeConnection(QString name1, QString name2){
        removerAresta(obterIndice(name1.toStdString()), obterIndice(name2.toStdString()));
    }
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
    virtual void washPowell(int vertice = 0) = 0;
    virtual vector<int> obterVerticesNaoAdjacentes(int origem) = 0;

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
         //   cout<<"\n"<<"Vertice: "<<nomes[i]<<" - Anterior: "<<nomes[lista[i].anterior]<<" - Distancia: "<<lista[i].distancia;
        }
        //cout<<"\n";
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
        queue<int> fila;
        fila.push(origem);
        visitados[origem] = true;

        while (!fila.empty()) {
            int frente = fila.front();
            fila.pop();
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
                    fila.push(v);
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
