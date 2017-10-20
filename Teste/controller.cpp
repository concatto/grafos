#include "controller.h"
#include "graphdialog.h"
#include <QDebug>
#include <QStack>

Controller::Controller()
{
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

        if (dialog.getStructure() == GraphDialog::GraphType::AdjacencyList) {
            graph = new LGrafo();
        } else {
            graph = new MGrafo();
        }

        window = new MainWindow(weighted, directed);
        GraphicsView& view = window->getView();

        QObject::connect(&view, &GraphicsView::addVertex, [&](QString nome) {
            if (graph->inserirVertice(nome.toStdString())) {
                view.createVertex(nome);
            } else {
                window->showError("Já existe um vértice com esse nome");
            }
        });

        QObject::connect(&view, &GraphicsView::removeVertex, [&](int id){
            graph->removerVertice(id);
        });

        QObject::connect(&view, &GraphicsView::addConnection, [&](int origem, int destino, int peso){
            bool result = false;

            if(view.isGraphDirected()){
                result = graph->inserirArco(origem, destino, peso);
            }else{
                result = graph->inserirAresta(origem, destino, peso);
            }

            if (result) {
                view.createConnection(origem, destino, peso);
            } else {
                window->showError("Falha ao inserir conexão");
            }
        });

        QObject::connect(&view, &GraphicsView::removeConnection, [&](int id1, int id2) {
            if(view.isGraphDirected()){
                graph->removerArco(id1, id2);
            }else {
                graph->removerAresta(id1, id2);
            }

        });

        QObject::connect(&view, &GraphicsView::performDsatur, [&](){
            vector<int> cores = graph->dsatur();
            view.paintVertices(QVector<int>::fromStdVector(cores));
        });

        QObject::connect(&view, &GraphicsView::performWelshPowell, [&](){
            vector<int> cores = graph->washPowell();
            view.paintVertices(QVector<int>::fromStdVector(cores));
        });

        QObject::connect(&view, &GraphicsView::performDijkstra, [&](int origem, int destino){
            QStack <int> stack;

            vector <Path> lista = graph->dijkstra(origem, destino);

            int vertice = destino;

            do{
                stack.push(vertice);
                vertice = lista[vertice].anterior;
            }while(stack.top() != origem);

            view.paintDijkstra(stack);

        });
        window->show();
    }

    return a.exec();
}
