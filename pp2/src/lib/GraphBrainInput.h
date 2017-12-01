# include "Neuron.h"
# include "DoubleLinkedList.h"
# ifndef GRAPH_BRAIN_INPUT
# define GRAPH_BRAIN_INPUT

class GraphBrainInput {
private:
    int size;
    int order;
    // TODO Change to list of blocks
    DoubleLinkedList<Neuron> blockList;
    
public:
    GraphBrainInput();
    int getSize();
    int getOrder();
    int getElement(int source, int destination);
    void readFromDefaultInput();
};

GraphBrainInput::GraphBrainInput() {
    this->size = 0;
    this->order = 0;
    this->blockList = DoubleLinkedList<Neuron>();
}

int GraphBrainInput::getSize() {
    return this->size;
}

int GraphBrainInput::getOrder() {
    return this->order;
}

int GraphBrainInput::getElement(int source, int destination) {
    Neuron element = this->blockList.get(source * this->order + destination);
    return 0;
}   

void GraphBrainInput::readFromDefaultInput() {
    std::cin >> this->order >> this->size;
    
    int source, destination;
    double weight;
    for(int i = 0; i < this->size; i++) {
        std::cin >> source >> destination >> weight;
        Edge edge = Edge(source, destination, weight);
    }
}

# endif
