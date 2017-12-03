# include "Neuron.h"
# include "DoubleLinkedList.h"
# ifndef BLOCK
# define BLOCK

class Block {
private:
    int size;
    int order;
    DoubleLinkedList<Neuron> neuronList;
    bool health;

public:
    Block();
    Block(int newSize, int newOrder);
    int getSize();
    int getOrder();
    DoubleLinkedList<Neuron> getNeuronList();
    Neuron getNeuron(int index);
    void insertNeuron(Neuron neuron);
    bool isHealth();
};

Block::Block() {
    this->size = 0;
    this->order = 0;
    this->neuronList = DoubleLinkedList<Neuron>();
    this->health = true;
}

Block::Block(int newSize, int newOrder) {
    this->size = newSize;
    this->order = newOrder;
    this->neuronList = DoubleLinkedList<Neuron>();
}

int Block::getSize() {
    return this->size;
}

int Block::getOrder() {
    return this->order;
}

Neuron Block::getNeuron(int index) {
    Neuron neuron = this->neuronList.get(index);
    return neuron;
}

DoubleLinkedList<Neuron> Block::getNeuronList(){
	return this->neuronList;
}

void Block::insertNeuron(Neuron neuron) {
    this->neuronList.insert(neuron);
    if (!neuron.isHealth()){
        this->health = false;
    }        
}

bool Block::isHealth() {
    return this->health;
}

# endif
