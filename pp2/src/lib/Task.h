# include "ReadBrain.h"
# include "ReadBlocks.h"
# include "DoubleLinkedList.h"
# include "Vertex.h"
# include "Adapter.h"
# include "Block.h"
# include "Kruskal.h"
# include "Dijkstra.h"

# ifndef TASK
# define TASK

class Task {
private:
    ReadBrain readsBrain;
    ReadBlocks readsBlocks;
    DoubleLinkedList<int> shortestPathVertexList;

public:
    Task();
    void execute();
};

Task::Task() {
    this->readsBrain = ReadBrain();
    this->shortestPathVertexList = DoubleLinkedList<int>();
}

void Task::execute() {
    this->readsBrain.readFromDefaultInput();

  	int amountBlocks = this->readsBrain.getOrder();
    this->readsBlocks = ReadBlocks(amountBlocks);
    this->readsBlocks.readFromDefaultInput();
    
    // http://graphonline.ru/en/?graph=hkjsoujcLmznDfSb
	
	Graph graph = this->readsBrain.getGraph();
	int source = this->readsBrain.getInput();
	int destination = this->readsBrain.getOutput();
	
	Dijkstra dijkstra = Dijkstra(graph, source, destination);
	dijkstra.execute();
	this->shortestPathVertexList = dijkstra.getPath();
    
    double totalCost = 0.0;
    
    int size = this->shortestPathVertexList.size();
    
    for(int i = 0; i < size; i++) {
    	int vertexId = this->shortestPathVertexList.get(i);
    	
    	Block block = this->readsBlocks.getBlock(vertexId);
    	bool isHealth = block.isHealth();
    	
    	if (!isHealth) {
    		Graph graphBlock = this->readsBlocks.getGraph(vertexId);
    		Kruskal kruskal = Kruskal(graphBlock);
			kruskal.execute();
			
			double cost = kruskal.getMinSpanningTreeWeight();
			std::cout << cost << std::endl;
			totalCost += cost;
    	}
    }
    
    std::cout << totalCost << std::endl;

}

# endif

