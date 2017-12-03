# include "Dictionary.h"
# include "DoubleLinkedList.h"
# include "Edge.h"

# ifndef VERTEX
# define VERTEX

class Vertex {
private:
	int id;
	DoubleLinkedList<Edge<Vertex*> > edgeList;

public:
    Vertex();
    Vertex(int newBlockId);
    DoubleLinkedList<Vertex> getNeighbors();
    void insertNeighbor(Vertex vertex, double weight);
    int getId();

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
DoubleLinkedList<Vertex> Vertex::getNeighbors() {
	DoubleLinkedList<Vertex> neighbors = DoubleLinkedList<Vertex>();
	int size = this->edgeList.size();
	
	for (int i = 0; i < size; i++) {
		Edge<Vertex*>  edge = this->edgeList.get(i);
		Vertex* destination = edge.getDestination();
		
		neighbors.insert(*destination);
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

# endif
