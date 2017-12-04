# include "Edge.h"
# ifndef NEURON
# define NEURON

class Neuron {
private:
    Edge<int>  edge;
    bool health;

public:
    Neuron();
    Neuron(int source, int destination, double weight, bool neuronIsHealth);
    Neuron(Edge<int>  newEdge, bool neuronIsHealth);
    int getSource();
    int getDestination();
    double getWeight();
    bool isHealth();
    
    bool operator<(Neuron otherNeuron) {
        double weight = edge.getWeight();
        double otherNeuronWeight = otherNeuron.getWeight();
        
        return weight < otherNeuronWeight;
    }
    
    bool operator>(Neuron otherNeuron) {
        double weight = edge.getWeight();
        double otherNeuronWeight = otherNeuron.getWeight();
        
        return weight > otherNeuronWeight;
    }
    bool operator==(Neuron otherNeuron) {
       
        
        bool otherHealth = otherNeuron.isHealth();
        Edge<int>  otherEdge = otherNeuron.edge;
        
        if (health == otherHealth) {
            if (edge == otherEdge) {
                return true;
            }
        }

        return false;
    }


};

Neuron::Neuron() {
	
    this->health = false;    
}

Neuron::Neuron(int source, int destination, double weight, bool neuronIsHealth) {
    this->edge = Edge<int> (source, destination, weight);
    this->health = neuronIsHealth;
}

Neuron::Neuron(Edge<int>  newEdge, bool neuronIsHealth) {
    this->edge = newEdge;
    this->health = neuronIsHealth;
}

int Neuron::getSource() {
    int source = this->edge.getSource();
    return source;
}

int Neuron::getDestination() {
    int destination = this->edge.getDestination();
    return destination;
}

double Neuron::getWeight() {
    double weight = edge.getWeight();
    return weight;
}

bool Neuron::isHealth() {
    return this->health;
}

# endif
