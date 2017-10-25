#include<iostream>
#include<vector>
#define BRANCO 0
#define CINZA 1
#define PRETO -1
#define NULO -1

using namespace std;

typedef int Vertex;

template<typename T>
class List{
private:
	vector<T> v;
public:
	List();
	List(int);
	List(int, int);
	int getTam();
	T getItem(int);
	void setItem(int, T);
	void insert(T);
	void remove(T);
	void print();
	T* search(T);
	void destroy();
};



template<typename T>
List<T>::List(){}

template<typename T>
List<T>::List(int tam){
	this->v = vector<T>(tam);
}

template<typename T>
List<T>::List(int tam, int initial){
	this->v = vector<T>(tam, initial);
}

template<typename T>
int List<T>::getTam(){
	return this->v.size();
}

template<typename T>
T List<T>::getItem(int index){
	return this->v[index];
}

template<typename T>
void List<T>::setItem(int index, T item){
	this->v[index] = item;
}

template<typename T>
void List<T>::insert(T item){
	this->v.push_back(item);
}

template<typename T>
void List<T>::remove(T item){
	for(int i=0; i < v.size(); i++){
		if(this->v[i] == item){
			this->v.erase(v.begin() + i);
		}
	}
}

template<typename T>
void List<T>::print(){
	int tam = this->v.size();
	if(tam == 0) cout << "NULL" << endl;
	else{
		cout << this->v[0];
		for(int i=1; i < tam; i++){
			cout << ' ' << this->v[i];
		}
		cout << endl;
	}
}

template<typename T>
T* List<T>::search(T item){
	int tam = this->v.size();
	for(int i=0; i < tam; i++){
		if(this->v[i] == item){
			return (this->v.begin() + i);
		}
	}
	return NULL;
}

template<typename T>
void List<T>::destroy(){
	this->v.clear();
}

class Graph{
private:
	int n; // Ordem
	int m; // Tamanho
	List<Vertex> *adj;
	void destroy();

public:
	Graph();
	Graph(int);
	void initialize(int);
	void insertEdge(Vertex, Vertex);
	void removeEdge(Vertex, Vertex);
	List<Vertex>* getAdj();
	void setAdj(List<Vertex>*);
	int getN();
	void setN(int);
	int getM();
	void setM();
	void print();
};

Graph::Graph(){}

Graph::Graph(int ordem){
	initialize(ordem);
}

void Graph::initialize(int ordem){

	// if(this->n != 0) destroy();
	this->n = ordem;

	this->adj = new List<Vertex>[ordem + 1];
}

int Graph::getN(){
	return this->n;
}

int Graph::getM(){
	return this->m;
}

List<Vertex>* Graph::getAdj(){
	return this->adj;
}

void Graph::insertEdge(Vertex u, Vertex v){
	this->adj[u].insert(v); // chave igual ao id do vertice
	this->adj[v].insert(u);
	this->m++;
}

void Graph::print(){
	for(int i=1; i <= this->n; i++){
		cout << "adj[" << i << "] = ";
		this->adj[i].print();
	}
}

// void Graph::destroy(){
// 	for(int i=0; i <= this->n; i++){
// 		adj[i].destroy();
// 	}
// 	delete adj;
// 	this->n = this->m = 0;
// }

void testaGrafo(Graph &g){

	g.insertEdge(1, 2);
	g.insertEdge(2, 3);
	g.insertEdge(3, 4);
	g.insertEdge(4, 5);
	g.insertEdge(5, 1);
	g.insertEdge(5, 2);
	g.insertEdge(2, 4);
	g.print();
}

// Depth-Fist Search

// lista que guarda o estado do vertice
List<int> cor;
// lista que indica quem eh o pai do vetice
List<int> pai;


void DFSVisita(Graph &g, int u){
	cor.setItem(u, CINZA);
	List<Vertex>* adj = g.getAdj();
	for(int i=0; i < adj[u].getTam(); i++){
		int v = adj[u].getItem(i);
		if(cor.getItem(v) == BRANCO){
			cout << ' ' << v;
			pai.setItem(v, u);
			DFSVisita(g, v);
		}
	}
	cor.setItem(u, PRETO);
}

void DFS(Graph &g){
	// inicializa a lista de vertices com a cor BRANCO
	cor = List<Vertex>(g.getN() + 1, BRANCO);
	// inicialoza a lista de vertices com pai NULO
	pai = List<Vertex>(g.getN() + 1, NULO);

	for(int u=1; u <= g.getN(); u++){
		if(cor.getItem(u) == BRANCO){
			cout << u;
			DFSVisita(g, u);
		}

	}
	cout << endl;

}



int main(int argc, const char * argv[]){
	Graph g;
	g = Graph(5);
	testaGrafo(g);
	DFS(g);
}
