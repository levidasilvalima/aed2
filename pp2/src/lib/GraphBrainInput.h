# include "Graph.h"
# ifndef GRAPH_BRAIN_INPUT
# define GRAPH_BRAIN_INPUT

class GraphBrainInput {
private:
    int size;
    int order;
    Graph graph;
    void insertEdge(int source, int destination, double weight);
    void createGraph(int newOrder);

public:
    GraphBrainInput();
    int getSize();
    int getOrder();
    double getWeight(int source, int destination);
    void readFromDefaultInput();
};

void GraphBrainInput::insertEdge(int source, int destination, double weight) {    
    this->graph.insertEdge(source, destination, weight);
}

void GraphBrainInput::createGraph(int newOrder) {
    this->graph = Graph(order);
}

GraphBrainInput::GraphBrainInput() {
    this->size = 0;
    this->order = 0;
    this->graph = Graph();
}

int GraphBrainInput::getSize() {
    return this->size;
}

int GraphBrainInput::getOrder() {
    return this->order;
}

double GraphBrainInput::getWeight(int source, int destination) {
    double weight = this->graph.getWeight(source, destination);
    return weight;
}


void GraphBrainInput::readFromDefaultInput() {
    std::cin >> this->order >> this->size;
    
    this->createGraph(this->order);

    int source, destination;
    double weight;
    for (int i = 0; i < this->size; i++) {
        std::cin >> source >> destination >> weight;
        this->insertEdge(source, destination, weight);
    }

}   

# endif
