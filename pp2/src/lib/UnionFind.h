# include "Graph.h"
# include "Adapter.h"
# include "Edge.h"

# ifndef UNIONFIND_H
# define UNIONFIND_H

class UnionFind {
private:
    DoubleLinkedList<int> parent;
	DoubleLinkedList<int> rank;

public:
    UnionFind();
	UnionFind(int graphOrder);
	int find(int vertex);
	void join(int u, int v);

};

UnionFind::UnionFind() {

}

UnionFind::UnionFind(int graphOrder){
	this->parent = DoubleLinkedList<int>();
	this->rank = DoubleLinkedList<int>();
	for(int i = 0; i <= graphOrder; i++){
		this->parent.insert(i);
		this->rank.insert(1);
	}
}

int UnionFind::find(int son){
	int father = this->parent.get(son);
	if(father != son){
		int grandFather = this->find(father);
		this->parent.update(son, grandFather);

		return grandFather;
	}
	
	return son;
}

void UnionFind::join(int u, int v) {
	int fatherU = this->find(u);
	int fatherV	= this->find(v);
	
	int rankFatherU = this->rank.get(fatherU);
	int rankFatherV = this->rank.get(fatherV);
	
	if (rankFatherU < rankFatherV) {
		int aux = rankFatherU;
		rankFatherU = rankFatherV;
		rankFatherV = aux;	
	}
	
	int rankTotal = rankFatherU + rankFatherV;
	this->rank.update(fatherU, rankTotal);
	this->parent.update(fatherV, fatherU);	

}

# endif



