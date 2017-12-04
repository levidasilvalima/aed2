# include "Dictionary.h"
# include "DoubleLinkedList.h"
# include "Edge.h"
# include "Graph.h"

# ifndef VERTEX
# define VERTEX

class Vertex {
private:
	int id;
	DoubleLinkedList<Edge<Vertex*> > edgeList;

public:
    Vertex();
    Vertex(int newBlockId);
    DoubleLinkedList<Vertex> getNeighbors(Graph graph);
    void insertNeighbor(Vertex vertex, double weight);
    int getId();
    Edge<Vertex*> getEdge(int neighborId);

};

Vertex::Vertex() {
	this->id = -1;
	this->edgeList = DoubleLinkedList<Edge<Vertex*> >();
}

Vertex::Vertex(int newBlockId) {
	this->id = newBlockId;
	this->edgeList = DoubleLinkedList<Edge<Vertex*> >();	
}

// TODO review neighbors
DoubleLinkedList<Vertex> Vertex::getNeighbors(Graph graph) {
	DoubleLinkedList<Vertex> neighbors = DoubleLinkedList<Vertex>();
	this->edgeList = DoubleLinkedList<Edge<Vertex*> >();
	
	int order = graph.getOrder();
	for(int i = 0; i < order; i++) {
		double weight = graph.getWeight(this->id, i);
		if (weight > 0) {
			Vertex vertexNeighbor1 = Vertex(i);
			neighbors.insert(vertexNeighbor1);
			
			Vertex* vertexNeighbor = new Vertex(i);
			Edge<Vertex*> edge = Edge<Vertex*>(this, vertexNeighbor, weight);
			
			this->edgeList.insert(edge);
		}
	}

	return neighbors;
}

void Vertex::insertNeighbor(Vertex vertex, double weight) {	
	Vertex* vertexSource = new Vertex(this->id); 
	Vertex* vertexDestination = new Vertex(vertex.getId());	
	Edge<Vertex*> edge = Edge<Vertex*> (vertexSource, vertexDestination, weight);
	this->edgeList.insert(edge);
}

int Vertex::getId() {
	return this->id;
}

Edge<Vertex*> Vertex::getEdge(int neighborId) {
	Edge<Vertex*> edge = this->edgeList.get(neighborId);
	return edge;
}

# endif
