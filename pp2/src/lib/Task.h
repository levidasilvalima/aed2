# include "ReadBrain.h"
# include "ReadBlocks.h"
# include "DoubleLinkedList.h"
# include "Vertex.h"
# include "Adapter.h"

# ifndef TASK
# define TASK

class Task() {
private:
    ReadBrain readsBrain;
    ReadBlocks readsBlocks;
    DoubleLinkedList<Vertex> shortestPathVertexList;

public:
    Task();
    void execute();
};

Task::Task() {
    this->readsBrain = ReadBrains();
    this->readsBlocks = ReadBlocks();
    this->shortestPathVertexList = DoubleLinkedList<Vertex>();
}

void Task::execute() {
    this->readsBrains.readFromDefaultInput();
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

}

# endif
