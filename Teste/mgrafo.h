#ifndef MGRAFO_H
#define MGRAFO_H
#include "grafo.h"
#include <iostream>

using namespace std;


struct MGrafo : public Grafo {
//public slots:
//    void addVertex(QString str){
//        qDebug()<<str;
//    }
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

    bool existeVertice(int vertice) override {
        return vertice >= 0 && vertice < adjacencias.size();
    }

    bool inserirArco(int origem, int destino, int peso) override {
        if (!existeVertice(origem) || !existeVertice(destino)) {
            return false;
        }

        this->adjacencias[origem][destino] = peso;
        return true;
    }

    void imprimir() override {
        for (int i = 0; i < this->adjacencias.size(); i++) {
            cout << "|";

            for (int j = 0; j < this->adjacencias[i].size(); j++) {
                cout << this->adjacencias[i][j] << "|";
            }

            cout << "\n";
        }

        cout << "\n";
        for (int i = 0; i < this->nomes.size(); i++) {
            cout << i << ": " << this->nomes[i] << "\n";
        }
    }

    vector<int> obterVerticesAdjacentes(int origem) override {
        vector<int> vetor;

        if (existeVertice(origem)) {
            for (int j = 0; j < this->adjacencias[origem].size(); j++) {
                if (existeArco(origem, j))
                    vetor.push_back(j);
            }
        }

        return vetor;
    }

    vector<Arco> obterVerticesAdjacentesComPeso(int origem) override {
        vector<Arco> vetor;

        for (int v : obterVerticesAdjacentes(origem)) {
            Arco arco(consultarPeso(origem, v), v);
            vetor.push_back(arco);
        }

        return vetor;
    }

    int consultarPeso(int origem, int destino) override {
        if (!existeVertice(origem) || !existeVertice(destino)) {
            return 0;
        }

        return this->adjacencias[origem][destino];
    }

    bool removerVertice(int vertice) override {
        if (!existeVertice(vertice))
            return false;

        adjacencias.erase(adjacencias.begin() + vertice);
        for (int i = 0; i < adjacencias.size(); i++) {
            adjacencias[i].erase(adjacencias[i].begin() + vertice);
        }

        nomes.erase(nomes.begin() + vertice);
        return true;
    }

    bool removerArco(int origem, int destino) override {
        return inserirArco(origem, destino, 0);
    }

    int obterGrau(int vertice) override {
        return obterVerticesAdjacentes(vertice).size();
    }


    //Possívelmente uma implementação final de dijkstraK
    void dijkstra(int origem){
        vector <Path> lista(adjacencias.size());
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
//            cout<<"\n"<<"Vertice: "<<nomes[i]<<" - Anterior: "<<nomes[lista[i].anterior]<<" - Distancia: "<<lista[i].distancia;
        }
//        cout<<"\n";

    }

    bool washAux(vector <WashPowell> listaWp, int cor, int origem){

        for(WashPowell l: listaWp){
            if(l.id != origem && consultarPeso(origem, l.id) > 0 && l.cor == cor){
                return false;
            }
        }

//        for(int adj : obterVerticesAdjacentes(origem)){
//            for(WashPowell l: listaWp){
//                if(l.id == adj && l.cor == cor){
//                    return false;
//                }
//            }
//        }

        return true;

    }

//    vector<int> obterVerticesNaoAdjacentes(int origem){
//        vector <int> lista;
//        for(int i = 0; i < adjacencias.size(); i++){
//            if(adjacencias[origem][i] == 0 && i != origem){
//                lista.push_back(i);
//            }
//        }
//        return lista;
//    }

    void washPowell(int vertice = 0){
        (void)vertice;

        vector <WashPowell> listaWp(nomes.size());
        int corAtual = 0;
        int counter = 0;

        for(int i = 0; i < listaWp.size(); i++){
            listaWp[i].id = i;
            listaWp[i].grau = obterGrau(i);
            listaWp[i].cor = -1;
        }

        sort(listaWp.begin(), listaWp.end());

        for(WashPowell &i : listaWp){
            if(counter == nomes.size())
                break;
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

//            for(int l: obterVerticesNaoAdjacentes(i.id)){
//                for(WashPowell &w: listaWp){
//                    if(w.id == l && w.cor == -1 && washAux(listaWp, corAtual, l)){
//                        w.cor = corAtual;
//                        counter++;
//                    }
//                }
//            }
        }

        for(WashPowell l: listaWp){
            qDebug()<<"Vértice: "<<QString::fromStdString(obterNome(l.id))<<" - "<<l.cor;
        }

    }

    // Primeira tentativa de dijkstra, não está correto.
/*
    void dijkstra2(int vertice){
        vector <Path> lista(adjacencias.size());

        int backup = vertice;

        //lista[vertice].aberto = false;
        lista[vertice].distancia = 0;
        lista[vertice].anterior = -1;

        for(int i = 0; i < lista.size(); i++){
            for(int j : obterVerticesAdjacentes(vertice)){
                for(int l : obterVerticesAdjacentes(vertice)){
                    if(lista[l].aberto == false)
                        continue;
                    if((lista[l].distancia == -1) || (lista[l].distancia > adjacencias[vertice][l] + lista[vertice].distancia)){
                        lista[l].anterior = vertice;
                        lista[l].distancia = adjacencias[vertice][l] + lista[vertice].distancia;
                    }
                }
                lista[vertice].aberto = false;
                vertice = j;
            }
            cout<<nomes[vertice];
        }

        for(int i = 0; i < lista.size(); i++){
            if(i == backup)
                lista[i].anterior = backup;
            cout<<"\n"<<"Vertice: "<<nomes[i]<<" - Anterior: "<<nomes[lista[i].anterior]<<" - Distancia: "<<lista[i].distancia;
        }
        cout<<"\n";

    }*/

};

#endif // MGRAFO_H
