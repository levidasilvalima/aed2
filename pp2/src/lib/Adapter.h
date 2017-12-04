# include "Graph.h"
# include "DoubleLinkedList.h"
# include "Edge.h"
# include "Neuron.h"

# ifndef GRAPH_ADAPTER_H
# define GRAPH_ADAPTER_H

class Adapter {
public:
    Adapter();
	void getEdgeList(Graph graph, DoubleLinkedList<Edge<int> >& graphEdgeList);
	void getGraph(DoubleLinkedList<Neuron> graphNeuronList, Graph& graph);
};

Adapter::Adapter() {

}

void Adapter::getEdgeList(Graph graph, DoubleLinkedList<Edge<int> >& graphEdgeList){
	int graphOrder = graph.getOrder();
	for(int u=0; u < graphOrder - 1; u++){
		for(int v=u+1; v < graphOrder; v++){
			if(graph.getWeight(u, v) > 0){
				Edge<int>  newEdge = Edge<int> (u, v, graph.getWeight(u, v));
				graphEdgeList.insert(newEdge);
			}
		}
	}
}

void Adapter::getGraph(DoubleLinkedList<Neuron> graphNeuronList, Graph& graph){
	int size = graphNeuronList.size();
	Neuron neuron;
	int source, destination;
	double weight;
	for(int i = 0; i < size; i++){
		neuron = graphNeuronList.get(i);
		source = neuron.getSource();
		destination = neuron.getDestination();
		weight = neuron.getWeight();
		graph.insertEdge(source, destination, weight);
	}
}

# endif
