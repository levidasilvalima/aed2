#include<iostream>
#include<vector>
using namespace std;

typedef int Vertex;

template<typename T>
class List{
private:
	vector<T> v;
public:
	void insert(T);
	void remove(T);
	void print();
	T* search(T);
	void destroy();
};

template<typename T>
void List<T>::insert(T item){
	v.push_back(item);
}

template<typename T>
void List<T>::remove(T item){
	for(int i=0; i < v.size(); i++){
		if(v[i] == item){
			v.erase(v.begin() + i);
		}
	}
}

template<typename T>
void List<T>::print(){
	int tam = v.size();
	if(tam == 0) cout << "NULL" << endl;
	else{
		cout << v[0];
		for(int i=1; i < tam; i++){
			cout << ' ' << v[i];
		}
		cout << endl;
	}
}

template<typename T>
T* List<T>::search(T item){
	int tam = v.size();
	for(int i=0; i < tam; i++){
		if(v[i] == item){
			return (v.begin() + i);
		}
	}
	return NULL;
}

template<typename T>
void List<T>::destroy(){
	v.clear();
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
	int* getN();
	void setN(int);
	int* getM();
	void setM();
	void print();
};

Graph::Graph(){}

Graph::Graph(int n){
	initialize(n);
}

void Graph::initialize(int n){

	// if(this->n != 0) destroy();
	this->n = n;

	adj = new List<Vertex>[n + 1];
}

void Graph::insertEdge(Vertex u, Vertex v){
	adj[u].insert(v); // chave igual ao id do vertice
	adj[v].insert(u);
	this->m++;
}

void Graph::print(){
	for(int i=1; i <= this->n; i++){
		cout << "adj[" << i << "] = ";
		adj[i].print();
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

	cout << "aqui" << endl;
	g.print();
}


int main(int argc, const char * argv[]){
	int n, m;
	cout << "Ordem : ";
	cin >> n;
	Graph g;
	g = Graph(n);
	testaGrafo(g);
}
