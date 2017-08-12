#include <iostream>
#include <vector>

using namespace std;

struct Grafo {
    vector<vector <int>> adjacencias;
    vector<string> nomes;

    void inserirVertice(string nome){
        this->nomes.push_back(nome);
        int tam = this->adjacencias.size();
        vector<int> vetor;
        for(int i=0; i<tam; i++){
            vetor.push_back(0);
        }
         this->adjacencias.push_back(vetor);

        for(int i=0; i<this->adjacencias.size(); i++){
            this->adjacencias[i].push_back(0);
        }
    }

    void inserirArco(int origem, int destino){
        this->adjacencias[origem][destino] = 1;
    }

    void imprimir(){
        for(int i=0; i<this->adjacencias.size(); i++){
            for(int j=0; j<this->adjacencias[i].size(); j++){
                cout<<this->adjacencias[i][j];
            }
            cout<<"\n";
        }
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

    grafo.imprimir();

    return 0;
}

