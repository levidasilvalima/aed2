# include "Edge.h"
# include "Graph.h"
# include "UnionFind.h"
# include "DoubleLinkedList.h"
# include "Adapter.h"
# include "QuickSort.h"

# ifndef KRUSKAL_H
# define KRUSKAL_H

class Kruskal {
private:
    DoubleLinkedList<Edge<int> > edgeList;
    QuickSort<Edge<int> > quickSort;
    double minSpanningTreeWeight;
    Graph graph;
	Adapter graphAdapter;	
	UnionFind unionFind;
	
	void initialize();
	
public:
    Kruskal();   	
    Kruskal(Graph newGraph);
	void execute();
	double getMinSpanningTreeWeight();
};

Kruskal::Kruskal() {

}

Kruskal::Kruskal(Graph newGraph){
	this->graph = newGraph;
	this->edgeList = DoubleLinkedList<Edge<int> >();
	this->initialize();
	
	int order = newGraph.getOrder();	
	this->unionFind = UnionFind(order);
	this->minSpanningTreeWeight = 0.0;
}

void Kruskal::initialize(){
	this->graphAdapter.getEdgeList(this->graph, this->edgeList);
}

void Kruskal::execute(){
	this->quickSort.sort(edgeList, 0, edgeList.size() - 1);

	for(int i = 0; i < edgeList.size(); i++) {
		Edge<int>  edge = edgeList.get(i);
		int source = edge.getSource();
		int destination = edge.getDestination();
		double weight = edge.getWeight();
	}

	int size = this->edgeList.size();
	for(int i = 0; i < size; i++){
		Edge<int>  edge = this->edgeList.get(i);
		int source = edge.getSource();
		int destination = edge.getDestination();
		double weight = edge.getWeight();
	
		int fatherSource = this->unionFind.find(source);
		int fatherDestination = this->unionFind.find(destination);	

		if (fatherSource != fatherDestination) {
			this->unionFind.join(source, destination);
			this->minSpanningTreeWeight += weight;
		}
	}
}

double Kruskal::getMinSpanningTreeWeight(){
	return this->minSpanningTreeWeight;
}

# endif
