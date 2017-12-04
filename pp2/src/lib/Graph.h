# include "Dictionary.h"
# include "BrainEdge.h"
# include "DoubleLinkedList.h"

# ifndef GRAPH_H
# define GRAPH_H

class Graph{
private:
	int order;
	int size;
	Dictionary<int, double> **adj;
    void initialize(int newOrder);
    bool validateVertices(int source, int destination);

public:
	Graph();
	Graph(int order);
	int getOrder();
	int getSize();
	void insertEdge(int source, int destination, double weight);
    double getWeight(int source, int destination);
    void setWeight(int source, int destination, double weight);
	void print();
	DoubleLinkedList<BrainEdge> getNeighbors(int id);
};

Graph::Graph(){
	this->size = 0;
    this->order = 0;
	this->adj = NULL;
}

Graph::Graph(int newOrder){
    this->size = 0;
    this->order = 0;
	this->adj = NULL;

	initialize(newOrder);
}

int Graph::getOrder(){
	return this->order;
}

int Graph::getSize(){
	return this->size;
}

void Graph::initialize(int newOrder){
	this->order = newOrder;
    this->adj = new Dictionary<int, double>*[newOrder];
	
	for(int i=0; i < newOrder; i++) {
        this->adj[i] = new Dictionary<int, double>[newOrder];
    }
    for(int i = 0; i < newOrder; i++){
    	for(int j = 0; j < newOrder; j++){
    		adj[i][j] = Dictionary<int, double>(-1, -1);
    	}
    }
}

bool Graph::validateVertices(int source, int destination){
  if(0 <= source && source < this->order){
    if(0 <= destination && destination < this->order){
      return true;
    }
    return false;
  }
  return false;
}

void Graph::insertEdge(int source, int destination, double weight){
    if (this->validateVertices(source, destination) ) {    
        Dictionary<int, double> dictionary = Dictionary<int, double>(this->size, weight);
        this->adj[source][destination] = dictionary;
        this->adj[destination][source] = dictionary;
	    this->size++;
    }
}

double Graph::getWeight(int source, int destination){
  if(this->validateVertices(source, destination)){
    Dictionary<int, double> dictionary = this->adj[source][destination];
    double weight = dictionary.getValue();

    return weight;
  }

  return 0;
}

void Graph::setWeight(int source, int destination, double weight){
  if(validateVertices(source, destination)){
    Dictionary<int, double> dictionary = this->adj[source][destination];
    int key = dictionary.getKey();
    this->adj[source][destination] = Dictionary<int, double>(key, weight);
  }
}

void Graph::print(){
	for(int u=0; u < this->order; u++){
		std::cout << "adj[" << u << "] = ";
		for(int v=u+1; v < this->order; v++){
            std::cout << this->adj[u][v].getValue() << ' ';
        }
        std::cout << std::endl;
	}
}

DoubleLinkedList<BrainEdge> Graph::getNeighbors(int id) {
	DoubleLinkedList<BrainEdge> neighbors = DoubleLinkedList<BrainEdge>();
	for(int i = 0; i < this->order; i++) {
		double weight = this->getWeight(id, i);
		if (weight > 0) {	
			BrainEdge brainEdge = BrainEdge(i, weight);	
			neighbors.insert(brainEdge);
		}
	}
	
	return neighbors;
}

# endif
