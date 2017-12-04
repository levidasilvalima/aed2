# include "DoubleLinkedList.h"
# include "PriorityQueue.h"
# include "Graph.h"

# ifndef DIJKSTRA_H
# define DIJKSTRA_H

class Dijkstra {
private:
	const int INF = (1 << 30) - 1;
	
	Graph graph;
	int source;
	int destination;	
	
    DoubleLinkedList<double> distance;
    DoubleLinkedList<int> parent;
	PriorityQueue<BrainEdge> priorityQueue;
	DoubleLinkedList<int> path;
	
	void initialize();
    void buildPath();
	
public:
    Dijkstra();
	Dijkstra(Graph graph, int source, int destination);
    void execute();
	DoubleLinkedList<int> getPath();
};

Dijkstra::Dijkstra() {

}

Dijkstra::Dijkstra(Graph newGraph, int newSource, int newDestination) {
	this->graph = newGraph;
	this->source = newSource;
	this->destination = newDestination;
	this->parent = DoubleLinkedList<int>();
	this->distance = DoubleLinkedList<double>();
	this->priorityQueue = PriorityQueue<BrainEdge>();
	this->path = DoubleLinkedList<int>();
}

void Dijkstra::initialize() {
	int order = this->graph.getOrder();
	
	for(int i = 0; i < order; i++) {
		this->parent.insert(-1);
		this->distance.insert(INF);
	}
}

void Dijkstra::execute() {
	this->initialize();
	
	BrainEdge sourceBrainEdge = BrainEdge(this->source, 0.0);
	this->priorityQueue.push(sourceBrainEdge);	
	this->distance.update(this->source, 0.0);	
	this->parent.update(this->source, this->source);
	
	DoubleLinkedList<BrainEdge> neighbors;
	while(!this->priorityQueue.empty()) {
		BrainEdge brainEdge = this->priorityQueue.front();
		this->priorityQueue.pop();
		
		int actualId = brainEdge.getId();
		neighbors = this->graph.getNeighbors(actualId);
		double actualDistance = this->distance.get(actualId);
		
		int size = neighbors.size();
		for(int i = 0; i < size; i++) {
			BrainEdge neighbor = neighbors.get(i);
			double imediateDistance = neighbor.getWeight();
			int neighborId = neighbor.getId();
			
			double alt = actualDistance + imediateDistance;
			if (alt < this->distance.get(neighborId)) {
				this->parent.update(neighborId, actualId);
				this->distance.update(neighborId, alt);

				BrainEdge tempBrainEdge = BrainEdge(neighborId, alt); 
				this->priorityQueue.push(tempBrainEdge);
			}
		}
	}
	
	this->buildPath();
 	
}

void Dijkstra::buildPath() {
	int actualId = this->destination;
	while(actualId != this->source) {
		this->path.insert(actualId);
		actualId = this->parent.get(actualId);
	}
	this->path.insert(this->source);
}

DoubleLinkedList<int> Dijkstra::getPath() {
	return this->path;
}
# endif

