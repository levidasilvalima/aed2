# include "Neuron.h"
# include "DoubleLinkedList.h"
# include "Block.h"
# ifndef GRAPH_BRAIN_INPUT
# define GRAPH_BRAIN_INPUT

class GraphBrainInput {
private:
    int size;
    int order;
    DoubleLinkedList<Edge> edgeList;
    
public:
    GraphBrainInput();
    int getSize();
    int getOrder();
    double getWeight(int source, int destination);
    void insertEdge(Edge edge);
    void readFromDefaultInput();
};

GraphBrainInput::GraphBrainInput() {
    this->size = 0;
    this->order = 0;
    this->edgeList = DoubleLinkedList<Edge>();
}

int GraphBrainInput::getSize() {
    return this->size;
}

int GraphBrainInput::getOrder() {
    return this->order;
}

double GraphBrainInput::getWeight(int source, int destination) {
    Edge edge = this->edgeList.get(source * this->order + destination);
    double weight = edge.getWeight();
    return weight;
}   

void GraphBrainInput::insertEdge(Edge edge) {
    this->edgeList.insert(edge);
}

void GraphBrainInput::readFromDefaultInput() {
    std::cin >> this->order >> this->size;
    
    int source, destination;
    double weight;
    for(int i = 0; i < this->size; i++) {
        std::cin >> source >> destination >> weight;
        Edge edge = Edge(source, destination, weight);
        this->edgeList.insert(edge);
    }
}

# endif
