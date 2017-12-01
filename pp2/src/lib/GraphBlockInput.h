# include "../lib/Neuron.h"
# include "../lib/DoubleLinkedList.h"
# ifndef GRAPH_BLOCK_INPUT
# define GRAPH_BLOCK_INPUT

class GraphBlockInput {
private:
    int size;
    int order;
    bool isHealth;
    DoubleLinkedList<Neuron> neuronList;

public:
    GraphBlockInput();
    int getSize();
    int getOrder();
    bool isHealth();
    Neuron getNeuron(int index);

}

GraphBlockInput::GraphBlockInput() {
    this->size = 0;
    this->order = 0;
}

# endif
