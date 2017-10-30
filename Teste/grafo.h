#ifndef GRAFO_H
#define GRAFO_H
#include <vector>
#include <string>
#include <QDebug>
#include <iostream>
#include <stack>
#include <queue>
#include <set>
#define INF 9999999

using namespace std;

struct WashPowell {
    int id;
    int grau;
    int cor;

};

struct Path{
    int distancia;
    int anterior;
    bool aberto;

    Path(){
        anterior = -1;
        distancia = -1;
        aberto = true;
    }
};

struct Prim {
    int id;
    int key;
    bool adicionado;

    Prim(int id){
        adicionado = false;
        this->id = id;
        this->key = INF;
    }

};

struct ComparePair {
    bool operator()(pair <int, int> p1, pair <int, int> p2){
        return p1.first > p2.first;
    }
};

inline bool operator < (WashPowell w1, WashPowell w2){
    return w1.id < w2.id;
}

inline bool welshPowellGreaterDegree (WashPowell w1, WashPowell w2){
    return w1.grau > w2.grau;
}



struct ComparePrim {
    bool operator()(Prim p1, Prim p2){
        return p1.key < p1.key;
    }
};

struct Arco {
    int peso;
    int vorigem;
    int vdestino;

    Arco() : Arco(-1, -1, 0) {}

    Arco(int vorigem, int vdestino, int peso = 1) {
        this->peso = peso;
        this->vorigem = vorigem;
        this->vdestino = vdestino;
    }
};

struct CompareArco {
    bool operator()(Arco a1, Arco a2){
        return a1.peso < a2.peso;
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

    vector<int> dsatur() {
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

    vector<int> welshPowell(){
        vector <WashPowell> listaWp(nomes.size());
        vector <int> cores;
        int corAtual = 0;
        int counter = 0;

        for(int i = 0; i < listaWp.size(); i++){
            listaWp[i].id = i;
            listaWp[i].grau = obterGrau(i);
            listaWp[i].cor = -1;
        }

        sort(listaWp.begin(), listaWp.end(), welshPowellGreaterDegree);

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

        sort(listaWp.begin(), listaWp.end());

        for(WashPowell l: listaWp){
            cores.push_back(l.cor);
        }

        return cores;

    }

    //Acho que agora foi, rapazeada, esperando o aval do mestre Fernando.
    vector <Arco> dijkstra(int origem, int destino = -1){
        vector <Path> lista(nomes.size());
        priority_queue <pair<int, int>, std::vector<pair<int, int>>, ComparePair> pq;
        vector <Arco> retorno;

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
                break;
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

        // Este bloco está causando violação de segmentação às vezes!
        // Aparentemente apenas quando o vértice é isolado (nenhum out-arco).
        for(int i = 0; i < lista.size(); i++){
            if(i == backup)
                lista[i].anterior = backup;
            cout<<"\n"<<"Vertice: "<<nomes[i]<<" - Anterior: "<<nomes[lista[i].anterior]<<" - Distancia: "<<lista[i].distancia;
        }

        cout<<"\n";

        int navegador = destino;

        // Violação de segmentação (aparentemente quando o destino não é atingível)
        while(navegador != backup){
            retorno.insert(retorno.begin(), Arco(lista[navegador].anterior, navegador));
            navegador = lista[navegador].anterior;
        }

        return retorno;
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
        if (existeAresta(origem, destino) || origem == destino) {
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


    vector<Arco> obterConexoes() {
        vector<Arco> resultado;

        for (int i = 0; i < nomes.size(); i++) {
            for (Arco a : obterVerticesAdjacentesComPeso(i)) {
                bool contemInverso = false;

                // Verifica se as conexões encontradas até o momento contém a conexão atual ou sua irmã
                for (Arco b : resultado) {
                    if ((a.vorigem == b.vorigem && a.vdestino == b.vdestino) ||
                        (a.vdestino == b.vorigem && a.vorigem == b.vdestino)) {
                        contemInverso = true;
                        break;
                    }
                }

                if (!contemInverso) {
                    resultado.push_back(a);
                }
            }
        }

        return resultado;
    }


    // Computa a árvore geradora mínima por meio do Algoritmo de Prim.
    // Retorna a sequência de arestas adicionadas, onde o índice 0 corresponde à primeira aresta adicionada.
    vector<Arco> prim(int inicial) {
        vector<Arco> arestas;

        // TODO implementar

        return arestas;
    }

    // Compute a AGM a partir do Algoritmo de Kruskal. Similar ao Prim.
    vector<Arco> kruskal() {
        vector<Arco> arestas;
        vector<Arco> solucao;

        vector<int> ciclo(nomes.size(), -1);

        arestas = obterConexoes();
        sort(arestas.begin(), arestas.end(), CompareArco());


        while(solucao.size() < nomes.size() - 1){
            if(ciclo[arestas.front().vorigem] != ciclo[arestas.front().vdestino]
                    || (ciclo[arestas.front().vorigem] == -1 && ciclo[arestas.front().vdestino] == -1)){

                for(int &a: ciclo){
                    if(a != -1 && (a == ciclo[arestas.front().vdestino])){
                        a = ciclo[arestas.front().vorigem];
                    }
                }

                ciclo[arestas.front().vorigem] = arestas.front().vorigem;
                ciclo[arestas.front().vdestino] = arestas.front().vorigem;
                solucao.push_back(arestas.front());
            }
            arestas.erase(arestas.begin());
        }

        for(Arco a: solucao){
            std::cout<<obterNome(a.vorigem)<<" , "<<obterNome(a.vdestino)<<"\n";
        }

        return solucao;
    }

    bool temCiclo3(){
        for(int i = 0; i < nomes.size(); i++){
            for(int v: obterVerticesAdjacentes(i)){
                for(int v2: obterVerticesAdjacentes(v)){
                    for(int v3: obterVerticesAdjacentes(v2)){
                        if(v3 == i){
                            return true;
                        }
                    }
                }
            }
        }
    }

    bool checkPlanarity(){

        if(nomes.size() <= 2)
            return true;

        if(temCiclo3()){
            return obterConexoes().size() <= 3*nomes.size() - 6;
        }else {
            return obterConexoes().size() <= 2*nomes.size() - 4;
        }

    }

};

#endif // GRAFO_H
