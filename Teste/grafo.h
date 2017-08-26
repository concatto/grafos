#ifndef GRAFO_H
#define GRAFO_H
#include <vector>
#include <string>

using namespace std;
using uint = unsigned int;

struct Grafo {
    vector<string> nomes;

    virtual bool inserirVertice(string nome) = 0;
    virtual bool existeIndice(uint vertice) = 0;
    virtual bool inserirArco(uint origem, uint destino, int peso = 1) = 0;
    virtual void imprimir() = 0;
    virtual bool existeArco(uint origem, uint destino) = 0;
    virtual vector<int> obterVerticesAdjacentes(uint origem) = 0;
    virtual bool removerArco(uint origem, uint destino) = 0;

    bool removerAresta(uint origem, uint destino){
        if(removerArco(origem, destino)){
            removerArco(destino, origem);
            return true;
        }
        return false;
    }

    int obterIndice(string nome){
        for(uint i=0; i< nomes.size(); i++){
            if(nome == nomes[i]){
                return i;
            }
        }
        return -1;
    }

    virtual int consultarPeso(uint origem, uint destino) = 0;
    virtual bool removerVertice(string nome) = 0;

    bool inserirAresta(uint origem, uint destino, int peso){
        if(inserirArco(origem, destino, peso)){
            inserirArco(destino, origem, peso);
            return true;
        }
        return false;
    }
};

#endif // GRAFO_H
