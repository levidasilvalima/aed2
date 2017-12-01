# ifndef GRAPH_H
# define GRAPH_H

class Graph{
private:
	int order;
	int size;
	double **adj;
    void initialize(int newOrder);
    bool validateVertices(int source, int destination);

public:
	Graph();
	Graph(int order);
	void insertEdge(int source, int destination, double weight);
    double getWeight(int source, int destination);
    void setWeight(int source, int destination, double weight);
	void print();

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

	initialize(newOrder + 1);
}

void Graph::initialize(int newOrder){
    newOrder++;
	this->order = newOrder;
    this->adj = new double*[newOrder];
	
	for(int i=0; i <= newOrder; i++) {
        this->adj[i] = new double[newOrder];
    }
}

bool Graph::validateVertices(int source, int destination){
  if(0 <= source && source <= this->order){
    if(0 <= destination && destination <= this->order){
      return true;
    }
    return false;
  }
  return false;
}

void Graph::insertEdge(int source, int destination, double weight){
    this->adj[source][destination] = weight;
    this->adj[source][destination] = weight;
	this->size++;
}

double Graph::getWeight(int source, int destination){
  if(validateVertices(source, destination)){
    return this->adj[source][destination];
  }
  return 0;
}

void Graph::setWeight(int source, int destination, double weight){
  if(validateVertices(source, destination)){
    this->adj[source][destination] = weight;
  }
}

void Graph::print(){
	for(int u=1; u < this->order; u++){
		std::cout << "adj[" << u << "] = ";
		for(int v=1; v <= this->order; v++){
            std::cout << this->adj[u][v] << ' ';
        }
        std::cout << std::endl;
	}
}

# endif
