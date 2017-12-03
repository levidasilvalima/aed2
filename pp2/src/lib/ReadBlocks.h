# include "Block.h"
# include "Graph.h"
# include "Adapter.h"
# ifndef READ_BLOCKS_H
# define READ_BLOCKS_H

class ReadBlocks {
private:
    DoubleLinkedList<Block> blockList;
    int amountBlocks;

public:
	ReadBlocks();
	ReadBlocks(int newAmountBlocks);
	void readFromDefaultInput();	
	Graph getGraph(int indexBlock);	
	Block getBlock(int indexBlock);
};

ReadBlocks::ReadBlocks() {
	
}

ReadBlocks::ReadBlocks(int newAmountBlocks) {
	this->amountBlocks = newAmountBlocks;	
}

void ReadBlocks::readFromDefaultInput() {

	for (int i = 1; i <= this->amountBlocks; i++) {		
		int blockOrder, blockSize;
		std::cin >> blockOrder >> blockSize;

		int amountDiseaseNeurons;
		std::cin >> amountDiseaseNeurons;
		
		int indexNeuron;
	    DoubleLinkedList<int> diseaseNeurons = DoubleLinkedList<int>();		
		for(int j = 1; j <= amountDiseaseNeurons; j++) {
			std::cin >> indexNeuron;		
			diseaseNeurons.insert(indexNeuron);			
		}
		
		Block block = Block(blockSize, blockOrder);
		int source, destination;
		double weight;
		for (int j = 1; j <= blockSize; j++) {
			std::cin >> source >> destination >> weight;
		
			bool result = diseaseNeurons.contain(source);
			Neuron neuron = Neuron(source, destination, weight, result);
			
			block.insertNeuron(neuron);
			
			result = diseaseNeurons.contain(destination);
			neuron = Neuron(destination, source, weight, result);
			
			block.insertNeuron(neuron);	

		}
		
		blockList.insert(block);
	}	

}

Graph ReadBlocks::getGraph(int indexBlock) {
	Block block = this->blockList.get(indexBlock);
	Adapter adapter;
	int order = block.getOrder();
	Graph graph = Graph(order);
	adapter.getGraph(block.getNeuronList(), graph);
	
	return graph;
}

Block ReadBlocks::getBlock(int indexBlock) {
	Block block = this->blockList.get(indexBlock);
	return block;
}

# endif

