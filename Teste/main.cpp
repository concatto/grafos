#include <iostream>
#include <vector>

using namespace std;
using uint = unsigned int;

struct Grafo {
    vector<vector <int>> adjacencias;
    vector<string> nomes;

    bool inserirVertice(string nome){
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

    bool existeIndice(uint vertice) {
        return vertice < adjacencias.size();
    }

    bool inserirArco(uint origem, uint destino, int peso = 1){
        if (existeIndice(origem) && existeIndice(destino)) {
            this->adjacencias[origem][destino] = peso;
            return true;
        }

        return false;
    }

    void imprimir(){
        for(uint i=0; i<this->adjacencias.size(); i++){
            for(uint j=0; j<this->adjacencias[i].size(); j++){
                cout<<this->adjacencias[i][j];
            }
            cout<<"\n";
        }
    }

    bool existeAresta(uint origem, uint destino){
        if(consultarPeso(origem, destino) == 0)
            return false;
        return true;
    }

    vector<int> obterVerticesAdjacentes(uint origem){
        vector<int> vetor;

        if (existeIndice(origem)) {
            for(uint j=0; j<this->adjacencias[origem].size();j++){
                if(existeAresta(origem, j))
                    vetor.push_back(j);
            }
        }

        return vetor;
    }

    int obterIndice(string nome){
        for(uint i=0; i< nomes.size(); i++){
            if(nome == nomes[i]){
                return i;
            }
        }
        return -1;
    }

    int consultarPeso(uint origem, uint destino) {
        if (!existeIndice(origem) || !existeIndice(destino)) {
            return 0;
        }

        return this->adjacencias[origem][destino];
    }

    bool removerVertice(string nome){
        uint indice = obterIndice(nome);
        adjacencias.erase(adjacencias.begin() + indice);
        for(uint i = 0; i < adjacencias.size(); i++){
            adjacencias[i].erase(adjacencias[i].begin() + indice);
        }
        nomes.erase(nomes.begin() + indice);
    }

};



int main()
{
    Grafo grafo;

    grafo.inserirVertice("0");
    grafo.inserirVertice("1");
    grafo.inserirVertice("2");
    grafo.inserirVertice("3");

    grafo.inserirArco(0,3);
    grafo.inserirArco(3,2);
    grafo.inserirArco(1,2);
    grafo.inserirArco(2,0);

    grafo.removerVertice("2");
    grafo.removerVertice("3");

    grafo.imprimir();

    return 0;
}

