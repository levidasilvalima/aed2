# include "ReadBrain.h"
# include "ReadBlocks.h"
# include "DoubleLinkedList.h"
# include "Vertex.h"
# include "Adapter.h"
# include "Block.h"
# include "Kruskal.h"

# ifndef TASK
# define TASK

class Task {
private:
    ReadBrain readsBrain;
    ReadBlocks readsBlocks;
    DoubleLinkedList<Vertex> shortestPathVertexList;

public:
    Task();
    void execute();
};

Task::Task() {
    this->readsBrain = ReadBrain();
    this->shortestPathVertexList = DoubleLinkedList<Vertex>();
}

void Task::execute() {
    this->readsBrain.readFromDefaultInput();

  	int amountBlocks = this->readsBrain.getOrder();
    this->readsBlocks = ReadBlocks(amountBlocks);
    this->readsBlocks.readFromDefaultInput();
    
    // http://graphonline.ru/en/?graph=hkjsoujcLmznDfSb

    Vertex vertex = Vertex(1);
    this->shortestPathVertexList.insert(vertex);
    
    vertex = Vertex(3);
    this->shortestPathVertexList.insert(vertex);

    vertex = Vertex(8);
    this->shortestPathVertexList.insert(vertex);

    vertex = Vertex(11);
    this->shortestPathVertexList.insert(vertex);

    vertex = Vertex(18);
    this->shortestPathVertexList.insert(vertex);
    
    double totalCost = 0.0;
    int size = this->shortestPathVertexList.size();
    for(int i = 0; i < size; i++) {
    	Vertex vertexBlock = this->shortestPathVertexList.get(i);
    	int blockId = vertexBlock.getId();
    	
    	Block block = this->readsBlocks.getBlock(blockId - 1);
    	bool isHealth = block.isHealth();
    	
    	if (!isHealth) {
    		Graph graph = this->readsBlocks.getGraph(blockId);
    		Kruskal kruskal = Kruskal(graph);
			kruskal.execute();
			
			double cost = kruskal.getMinSpanningTreeWeight();
			totalCost += cost;
    	}
    }
    
    std::cout << totalCost << std::endl;

}

# endif
