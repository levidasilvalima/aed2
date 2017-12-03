# include "Graph.h"
# ifndef READ_BRAIN
# define READ_BRAIN

class ReadBrain {
private:
	int input;
	int output;
    int size;
    int order;
    Graph graph;
    void insertEdge(int source, int destination, double weight);
    void createGraph(int newOrder);

public:
    ReadBrain();
    int getSize();
    int getOrder();
    double getWeight(int source, int destination);
    void readFromDefaultInput();
    int getInput();
   	int getOutput();
};

void ReadBrain::insertEdge(int source, int destination, double weight) {    
    this->graph.insertEdge(source, destination, weight);
}

void ReadBrain::createGraph(int newOrder) {
    this->graph = Graph(order);
}

ReadBrain::ReadBrain() {
    this->size = 0;
    this->order = 0;
    this->graph = Graph();
}

int ReadBrain::getSize() {
    return this->size;
}

int ReadBrain::getOrder() {
    return this->order;
}

double ReadBrain::getWeight(int source, int destination) {
    double weight = this->graph.getWeight(source, destination);
    return weight;
}


void ReadBrain::readFromDefaultInput() {
    std::cin >> this->order >> this->size;
    
    this->createGraph(this->order);

    int source, destination;
    double weight;
    for (int i = 0; i < this->size; i++) {
        std::cin >> source >> destination >> weight;
        this->insertEdge(source, destination, weight);
    }
	std::cin >> this->input >> this->output;
}   

int ReadBrain::getInput() {
	return this->input;
}

int ReadBrain::getOutput() {
	return this->output;
}

# endif
