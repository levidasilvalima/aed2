# include "Neuron.h"
# include "DoubleLinkedList.h"
# ifndef GRAPH_BLOCK_INPUT
# define GRAPH_BLOCK_INPUT

class GraphBlockInput {
private:
    int blockIndex;
    DoubleLinkedList<int> diseaseNeuronList;
    int size;
    int order;
    bool health;
    DoubleLinkedList<Neuron> neuronList;
    void insertNeuron(Neuron neuron);
    void readDiseaseNeurons();
    void readNeurons();

public:
    GraphBlockInput();
    int getSize();
    int getOrder();
    bool isHealth();
    Neuron getNeuron(int index);
    void readFromDefaultInput();
};

void GraphBlockInput::insertNeuron(Neuron neuron) {
    this->neuronList.insert(neuron);
}

void GraphBlockInput::readDiseaseNeurons() {
    int numberDiseaseNeurons;

    std::cin >> this->order >> this->size;
    std::cin >> numberDiseaseNeurons;
    
    int diseaseNeuron;
    for (int i = 0; i < numberDiseaseNeurons; i++) {
        std::cin >> diseaseNeuron;
        this->diseaseNeuronList.insert(diseaseNeuron);        
    }
}

void GraphBlockInput::readNeurons() {
    int source, destination;
    double weight;

    Neuron neuron;
    bool result;
    for (int i = 0; i < this->size; i++) {
        std::cin >> source >> destination >> weight;
        // TODO improve performance check disease neurons
        
        result = this->diseaseNeuronList.contain(source);
        neuron = Neuron(source, destination, weight, result);

        this->neuronList.insert(neuron);

        result = this->diseaseNeuronList.contain(destination);
        neuron = Neuron(destination, source, weight, result);

        this->neuronList.insert(neuron);
    }
}

GraphBlockInput::GraphBlockInput() {
    this->blockIndex = 0;
    this->diseaseNeuronList = DoubleLinkedList<int>();
    this->size = 0;
    this->order = 0;
    this->neuronList = DoubleLinkedList<Neuron>();
}

int GraphBlockInput::getSize() {
    return this->size;
}

int GraphBlockInput::getOrder() {
    return this->order;
}

bool GraphBlockInput::isHealth() {
    return this->health;
}

Neuron GraphBlockInput::getNeuron(int index) {
    Neuron neuron = this->neuronList.get(index);
    return neuron;
}

void GraphBlockInput::readFromDefaultInput() {
    this->readDiseaseNeurons();
    this->readNeurons();     
}

# endif
