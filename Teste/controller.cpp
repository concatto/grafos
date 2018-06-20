#include "controller.h"
#include <QDebug>
#include <algorithm>
#include <QStack>

Controller::Controller()
{
}

Grafo* Controller::instantiateGraph(GraphDialog::GraphType structure) {
    if (structure == GraphDialog::GraphType::AdjacencyList) {
        return new LGrafo();
    } else {
        return new MGrafo();
    }
}

int Controller::exec(QApplication& a)
{
    GraphDialog dialog;
    if (dialog.exec() == GraphDialog::Accepted) {
        bool directed = dialog.isDirected();
        bool weighted = dialog.isWeighted();

        qDebug() << "Tipo: " << dialog.getStructure() << "\n";
        qDebug() << "Ponderado: " << weighted << "\n";
        qDebug() << "Dirigido: " << directed << "\n";

        graph = instantiateGraph(dialog.getStructure());

        window = new MainWindow(weighted, directed);
        GraphicsView& view = window->getView();

        connect(&view, &GraphicsView::addVertex, [&](QString nome) {
            if (graph->inserirVertice(nome.toStdString())) {
                view.createVertex(nome);
            } else {
                window->showError("Já existe um vértice com esse nome.");
            }
        });

        connect(&view, &GraphicsView::performPlanarityCheck, [&](){
           if(graph->checkPlanarity()){
               view.displayMessageBox("O Grafo pode ser planar!");
           }else{
               view.displayMessageBox("O Grafo não é planar");
           }
        });

        connect(&view, &GraphicsView::removeVertex, [&](int id){
            if (graph->removerVertice(id)) {
                view.destroyVertex(id);
            } else {
                window->showError("Impossível remover o vértice.");
            }
        });

        connect(&view, &GraphicsView::addConnection, [&](int origem, int destino, int peso){
            bool result = false;

            if(directed){
                if (!graph->existeArco(origem, destino)) {
                    result = graph->inserirArco(origem, destino, peso);
                }
            }else{
                if (!graph->existeAresta(origem, destino)) {
                    result = graph->inserirAresta(origem, destino, peso);
                }
            }

            if (result) {
                view.createConnection(origem, destino, peso);
            } else {
                view.cancelConnection();
                window->showError("Falha ao inserir conexão");
            }
        });

        connect(&view, &GraphicsView::removeConnection, [&](int id1, int id2) {
            bool result = false;

            if(directed){
                result = graph->removerArco(id1, id2);
            }else {
                result = graph->removerAresta(id1, id2);
            }

            if (result) {
                view.destroyConnection(id1, id2);
            } else {
                window->showError("Impossível remover a conexão.");
            }
        });

        connect(&view, &GraphicsView::performDsatur, [&](){
            vector<int> cores = graph->dsatur();
            view.paintVertices(QVector<int>::fromStdVector(cores));

            //Testing
            graph->kruskal();

        });

        connect(&view, &GraphicsView::performWelshPowell, [&](){
            vector<int> cores = graph->welshPowell();
            view.paintVertices(QVector<int>::fromStdVector(cores));
        });

        connect(&view, &GraphicsView::performDijkstra, [&](int origem, int destino){
            vector <Arco> list = graph->dijkstra(origem, destino);

            for(Arco a: list){
                qDebug()<<a.origem;
            }

            view.paintPath(QVector<Arco>::fromStdVector(list));
        });

        connect(&view, &GraphicsView::performKruskal, [&](){
            vector <Arco> list = graph->kruskal();
            view.paintPath(QVector<Arco>::fromStdVector(list));
        });

        connect(&view, &GraphicsView::performPrim, [&](int id){
            vector<Arco> list = graph->prim(id);

            int total = 0;
            for (Arco a : list) {
                total += a.peso;
            }

            qDebug() << "Total: " << total;

            view.paintPath(QVector<Arco>::fromStdVector(list));
        });

        connect(&view, &GraphicsView::printGraph, [&]() {
            graph->imprimir();
        });

        connect(&view, &GraphicsView::performBFS, [&](int id) {
            vector<int> vertices = graph->buscaEmLargura(id);

            view.paintSequence(QVector<int>::fromStdVector(vertices));
        });

        connect(&view, &GraphicsView::performDFS, [&](int id) {
            vector<int> vertices = graph->buscaEmProfundidade(id);

            view.paintSequence(QVector<int>::fromStdVector(vertices));
        });

        connect(&view, &GraphicsView::computeMaxFlow, [&]() {
            int source = graph->encontrarFonte();
            int sink = graph->encontrarSorvedouro();
            Grafo* g = graph->aplicarFordFulkerson(source, sink);
            g->imprimir();

            view.displayFlow(QVector<Arco>::fromStdVector(g->obterArcos()));
        });

        connect(&view, &GraphicsView::performTravelingSalesman, [&](){
//           std::vector<int> r = graph->obterPopulacaoInicial(5);
//           for(const auto &p : r)
//           {
//               for(const auto &v : p)
//               {
//                std::cout<<v<<" - ";
//               }
//               std::cout<<std::endl;
//           }

        });

        window->show();
    }

    // Bloqueia até que a aplicação termine
    return a.exec();
}
