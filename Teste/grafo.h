#ifndef GRAFO_H
#define GRAFO_H
#include <vector>
#include <string>
#include <QDebug>
#include <iostream>
#include <stack>
#include <queue>
#include <set>
#include <limits>
#include <algorithm>
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

struct Arco {
    int peso;
    int origem;
    int destino;

    Arco() : Arco(-1, -1, 0) {}

    Arco(int origem, int destino, int peso = 1) {
        this->peso = peso;
        this->origem = origem;
        this->destino = destino;
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
    virtual Grafo* clonar() = 0;

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
        int lastVisited = 0;

        int backup = origem;

        lista[origem].distancia = 0;
        lista[origem].anterior = -1;

        pq.push(make_pair(lista[origem].distancia, origem));

        while(!pq.empty()){
            origem = pq.top().second;
            lastVisited = origem;
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
                }
            }
        }

        // Este bloco está causando violação de segmentação às vezes!
        // Aparentemente apenas quando o vértice é isolado (nenhum out-arco).

        for(int i = 0; i < lista.size(); i++){
            if(i == backup)
                lista[i].anterior = backup;
            //cout<<"\n"<<"Vertice: "<<nomes[i]<<" - Anterior: "<<nomes[lista[i].anterior]<<" - Distancia: "<<lista[i].distancia;
        }

        cout<<"\n";

        int navegador = destino;

        // Violação de segmentação (aparentemente quando o destino não é atingível)
        // O problema é que lista[naoAlcançavel].anterior era -1, isso causava index out of range
        // Pra resolver isso, criei uma variavel chamada lastVisited que guarda o ultimo vértice visitado
        // e caso o vértice destino não seja alcançado, ela é utilizada como anterior
        while(navegador != backup){
            if(lista[navegador].aberto == true){
                retorno.insert(retorno.begin(), Arco(lastVisited, navegador));
                navegador = lastVisited;
                continue;
            }
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
    vector<int> buscaEmProfundidadePrincipal(int vertice, vector <bool> &visitados, int destino, bool caminho = false) {
        visitados[vertice] = true;

        //A sequência de vértices visitados desta invocação começa com o próprio vértice
        vector<int> sequencia{vertice};

        vector<int> adj = obterVerticesAdjacentes(vertice);
        cout << "Adjacentes de " << nomes[vertice] << ":\n";
        for (int a : adj) {
            cout << nomes[a] << ", ";
        }
        cout << "\n";

        if (vertice == destino) {
            return sequencia;
        }

        for (int i = 0; i < adj.size(); i++) {
            if (visitados[adj[i]] == false) {
                vector<int> adicoes = buscaEmProfundidadePrincipal(adj[i], visitados, destino, caminho);

                bool atingiuDestino = adicoes.back() == destino;

                if (!caminho || (caminho && atingiuDestino)) {
                    //Insere os vértices visitados pela chamada recursiva na própria sequência
                    sequencia.insert(sequencia.end(), adicoes.begin(), adicoes.end());
                }

                //Se o destino foi atingido, parar
                if (atingiuDestino) {
                    return sequencia;
                }
            }
        }

        return sequencia;
    }

    // Realiza uma busca em profundidade (DFS). Um destino igual a -1 indica nenhum destino.
    // Se houver um destino e o
    vector<int> buscaEmProfundidade(int origem, int destino = -1, bool caminho = false) {
        if (!existeVertice(origem))
            return vector<int>();

        vector<bool> visitados(nomes.size(), false);
        vector<int> sequencia = buscaEmProfundidadePrincipal(origem, visitados, destino, caminho);

        //Sem destino?
        if (destino == -1) {
            // Reiniciar se não conseguiu atingir alguém
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

    // Obtém todas as arestas do grafo, sem repetições. A sequência origem-destino não é especificada.
    vector<Arco> obterArestas() {
        vector<Arco> resultado;

        for (Arco a : obterArcos()) {
            auto it = find_if(resultado.begin(), resultado.end(), [&](Arco b) {
                return (a.origem == b.origem && a.destino == b.destino) ||
                       (a.origem == b.destino && a.destino == b.origem);
            });

            // Se resultado não contém o arco
            if (it == resultado.end()) {
                resultado.push_back(a);
            }
        }

        return resultado;
    }

    // Obtém todos os arcos do grafo. Em um grafo não dirigido, o resultado possuirá dois
    // elementos para cada par de vértices conectados.
    vector<Arco> obterArcos() {
        vector<Arco> resultado;

        for (int i = 0; i < nomes.size(); i++) {
            for (Arco a : obterVerticesAdjacentesComPeso(i)) {
                resultado.push_back(a);
            }
        }

        return resultado;
    }

    // Obtém todos os vértices que possuem uma aresta com destino em v.
    vector<int> obterAdjacentesEntrantes(int v) {
        vector<int> resultado;

        for (int i = 0; i < nomes.size(); i++) {
            if (existeArco(i, v)) {
                resultado.push_back(i);
            }
        }

        return resultado;
    }

    // Encontra o grafo residual com fluxo maximizado.
    // O valor do fluxo máximo pode ser obtido com a soma dos pesos dos arcos da fonte.
    Grafo* aplicarFordFulkerson(int fonte, int sorvedouro) {
        Grafo* copia = this->clonar();

        int temp;
        int solucao = 0;
        vector<int> caminho;


        do {
            int menor = numeric_limits<int>::max();
            caminho = copia->buscaEmProfundidade(fonte, sorvedouro, true);
            if (sorvedouro != caminho.back()){
                break;
            }

            for(int i=0; i< caminho.size()-1; i++){
                temp = copia->consultarPeso(caminho[i], caminho[i+1]);
                cout << nomes[i] << " -> " << nomes[i+1] << " (" << temp << "), ";
                if(temp < menor ){
                    menor = temp;
                }
            }
            cout << "\n";
             solucao += menor;

             for(int i=0; i<caminho.size()-1;i++){
                 int u = caminho[i];
                 int v = caminho[i+1];
                 temp = copia->consultarPeso(u,v);
                 copia->inserirArco(u, v, temp-menor);
                 cout << "Arco (" << nomes[u] << ", " << nomes[v] << ") alterado de " << temp << " para " << (temp - menor) << "\n";
                 if(copia->existeArco(v,u)){
                    temp = copia->consultarPeso(v,u);
                    copia->inserirArco(v,u, temp+menor);
                    cout << "Arco (" << nomes[v] << ", " << nomes[u] << ") alterado de " << temp << " para " << (temp + menor) << "\n";
                 }
                 else{
                     copia->inserirArco(v,u,menor);
                     cout << "Arco (" << nomes[v] << ", " << nomes[u] << ") criado com peso " << menor << "\n";
                 }

             }

        }while(true);


        return copia;
    }

    // Descobre o primeiro vértice que não possui adjacentes entrantes.
    int encontrarFonte() {
        // TODO

        for(int i=0; i< nomes.size(); i++){
            if (obterAdjacentesEntrantes(i).empty()){
                return i;
            }
        }

        return -1;
    }

    // Descobre o primeiro vértice que não possui vértices adjacentes de saída.
    int encontrarSorvedouro() {
        // TODO

        for(int i=0; i<nomes.size(); i++){
            if (obterVerticesAdjacentes(i).empty()){
                return i;
            }
        }

        return -1;
    }

    // Computa a árvore geradora mínima por meio do Algoritmo de Prim.
    // Retorna a sequência de arestas adicionadas, onde o índice 0 corresponde à primeira aresta adicionada.
    vector<Arco> prim(int inicial) {
        int intmax = numeric_limits<int>::max();

        vector<Arco> retorno;
        vector<int> S;
        vector<int> Q;

        for(int i=0; i<nomes.size();i++){
            if(i!= inicial){
                Q.push_back(i);
            }
        }

       Arco menor;

       S.push_back(inicial);

        while(Q.size() != 0){
            menor.peso = intmax;

            for (int e : S){
                for (Arco k : obterVerticesAdjacentesComPeso(e)){
                    if(k.peso < menor.peso){
                        if(find(Q.begin(), Q.end(), k.destino) != Q.end()){
                                menor = k;
                          }
                    }
                }
            }

            Q.erase(remove(Q.begin(), Q.end(), menor.destino), Q.end());
            S.push_back(menor.destino);
            retorno.push_back(menor);

        }

        return retorno;
    }

    int buscar(vector<int> ciclo, int i){
        if(ciclo[i] == -1)
            return i;
        return buscar(ciclo, ciclo[i]);
    }

    // Computa a AGM a partir do Algoritmo de Kruskal. Similar ao Prim.
    vector<Arco> kruskal() {
        vector<Arco> arestas;
        vector<Arco> solucao;
        int total = 0;

        vector<int> ciclo(nomes.size(), -1);

        arestas = obterArestas();
        sort(arestas.begin(), arestas.end(), CompareArco());

        while (solucao.size() < nomes.size() - 1) {
            int g1 = buscar(ciclo, arestas.front().origem);
            int g2 = buscar(ciclo, arestas.front().destino);

            if(g1 != g2){
                if (ciclo[g1] != -1) {
                    ciclo[g2] = g1;
                } else {
                    ciclo[g1] = g2;
                }
                total += arestas.front().peso;
                solucao.push_back(arestas.front());
            }


            arestas.erase(arestas.begin());
        }

        for (Arco a : solucao){
            std::cout<<obterNome(a.origem)<<" , "<<obterNome(a.destino)<<"\n";
        }

        std::cout<<"Total: "<<total<<"\n";

        return solucao;
    }

    bool temCiclo3(){
        for (int i = 0; i < nomes.size(); i++) {
            for (int v : obterVerticesAdjacentes(i)) {
                for (int v2 : obterVerticesAdjacentes(v)) {
                    for (int v3 : obterVerticesAdjacentes(v2)) {
                        if (v3 == i){
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }

    bool checkPlanarity() {
        if (nomes.size() <= 2)
            return true;

        if (temCiclo3()) {
            return obterArestas().size() <= 3*nomes.size() - 6;
        } else {
            return obterArestas().size() <= 2*nomes.size() - 4;
        }
    }

};

#endif // GRAFO_H
