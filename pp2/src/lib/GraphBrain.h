# include "../lib/Edge.h"
# ifndef GRAPH_BRAIN
# define GRAPH_BRAIN

class GraphBrain {
private:
    int size;
    int order;
    double **graph;
    
public:
    GraphBrain();
    int getSize();
    int getOrder();
    int getElement(int source, int destination);
    void readFromDefaultInput();
};

GraphBrain::GraphBrain() {
    this->size = 0;
    this->order = 0;
}

int GraphBrain::getSize() {
    return this->size;
}

int GraphBrain::getOrder() {
    return this->order;
}

int GraphBrain::getElement(int source, int destination) {
    int element = this->graph[source][destination];
    return element;
}   

void GraphBrain::readFromDefaultInput() {
    std::cin >> this->order >> this->size;
    
    int source, destination;
    double weight;
    for(int i = 0; i < this->size; i++) {
        std::cin >> source >> destination >> weight;
        Edge edge = Edge(source, destination, weight);
    }
}

# endif
