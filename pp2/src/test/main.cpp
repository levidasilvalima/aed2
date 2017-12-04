#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

template<typename T>
class Node{
public:
	Node<T>* next;
	Node<T>* prev;
	T item;

	Node();
};

template<typename T>
Node<T>::Node(){
	next = NULL;
	prev = NULL;
}

template<typename T>
class Edge {
private:
    T source;
    T destination;
    double weight;

public:
    Edge(T source, T destination, double weight);
    Edge();
    T getSource();
    T getDestination();
    double getWeight(); 

	bool operator>(Edge<T> otherEdge) {
		double otherWeight = otherEdge.getWeight();
    
        if (weight > otherWeight) {
        	return true;
        }
        return false;		        
    }  

	bool operator<(Edge<T> otherEdge) {
		double otherWeight = otherEdge.getWeight();
    
        if (weight < otherWeight) {
        	return true;
        }
        return false;		        
    }  

    bool operator==(Edge<T> otherEdge) {
		T otherSource = otherEdge.getSource();
		T otherDestination = otherEdge.getDestination();
		double otherWeight = otherEdge.getWeight();
    
        if (source == otherSource) {
            if (destination == otherDestination) {
                if (weight == otherWeight) {
                    return true;
                }
            }
        }
        return false;		        
    }  
};

template<typename T>
Edge<T>::Edge(T vertexSource, T vertexDestination, double edgeWeight) {
    this->source = vertexSource;
    this->destination = vertexDestination;
    this->weight = edgeWeight;
}

template<typename T>
Edge<T>::Edge() {
}

template<typename T>
T Edge<T>::getSource() {
    return this->source;
}

template<typename T>
T Edge<T>::getDestination() {
    return this->destination;
}

template<typename T>
double Edge<T>::getWeight() {
    return this->weight;
}

class Neuron {
private:
    Edge<int>  edge;
    bool health;

public:
    Neuron();
    Neuron(int source, int destination, double weight, bool neuronIsHealth);
    Neuron(Edge<int>  newEdge, bool neuronIsHealth);
    int getSource();
    int getDestination();
    double getWeight();
    bool isHealth();
    
    bool operator<(Neuron otherNeuron) {
        double weight = edge.getWeight();
        double otherNeuronWeight = otherNeuron.getWeight();
        
        return weight < otherNeuronWeight;
    }
    
    bool operator>(Neuron otherNeuron) {
        double weight = edge.getWeight();
        double otherNeuronWeight = otherNeuron.getWeight();
        
        return weight > otherNeuronWeight;
    }
    bool operator==(Neuron otherNeuron) {
        bool otherHealth = otherNeuron.isHealth();
        Edge<int>  otherEdge = otherNeuron.edge;
        
        if (health == otherHealth) {
            if (edge == otherEdge) {
                return true;
            }
        }

        return false;
    }


};

Neuron::Neuron() {
	
    this->health = false;    
}

Neuron::Neuron(int source, int destination, double weight, bool neuronIsHealth) {
    this->edge = Edge<int> (source, destination, weight);
    this->health = neuronIsHealth;
}

Neuron::Neuron(Edge<int>  newEdge, bool neuronIsHealth) {
    this->edge = newEdge;
    this->health = neuronIsHealth;
}

int Neuron::getSource() {
    int source = this->edge.getSource();
    return source;
}

int Neuron::getDestination() {
    int destination = this->edge.getDestination();
    return destination;
}

double Neuron::getWeight() {
    double weight = edge.getWeight();
    return weight;
}

bool Neuron::isHealth() {
    return this->health;
}

class BrainEdge {
private:
	int id;
	double weight;
	
public:
	BrainEdge();
	BrainEdge(int newId, double newWeight);
	
	int getId();
	double getWeight();
	
	bool operator<(BrainEdge otherBrainEdge) {
		double otherWeight = otherBrainEdge.getWeight();
		return this->weight < otherWeight;
	}
	
	bool operator>(BrainEdge otherBrainEdge) {
		double otherWeight = otherBrainEdge.getWeight();
		return this->weight > otherWeight;
	}
	
	bool operator==(BrainEdge otherBrainEdge) {
		double otherWeight = otherBrainEdge.getWeight();
		return this->weight == otherWeight;
	}
};

BrainEdge::BrainEdge() {

}

BrainEdge::BrainEdge(int newId, double newWeight) {
	this->id = newId;
	this->weight = newWeight;
}

int BrainEdge::getId() {
	return this->id;
}

double BrainEdge::getWeight() {
	return this->weight;
}


template<typename T>
class DoubleLinkedList{
private:
	Node<T>* head;
	Node<T>* tail;
	int listSize;
	void initialize(int newSize, T element);

public:
	DoubleLinkedList();
	DoubleLinkedList(int newSize, T element);
	int size();
	void insert(T element);
	bool validatePosistion(int position);
	T get(int position);
	void update(int position, T newValue);
	void remove(int position);
	void print();
    bool contain(T value);
};

template<typename T>
DoubleLinkedList<T>::DoubleLinkedList(){
	this->listSize = 0;
	this->head = new Node<T>();
	this->tail = new Node<T>();
	this->head->next = this->tail;
	this->tail->prev = this->head;
}

template<typename T>
void DoubleLinkedList<T>::initialize(int newSize, T element){
	this->listSize = 0;
	this->head = new Node<T>();
	this->tail = new Node<T>();
	this->head->next = this->tail;
	this->tail->prev = this->head;
	for(int i = 0; i < newSize; i++){
		insert(element);
	}
}

template<typename T>
void DoubleLinkedList<T>::insert(T element){
	Node<T>* aux = new Node<T>();

	this->tail->prev->next = aux;
	aux->prev = this->tail->prev;
	aux->next = this->tail;
	this->tail->prev = aux;
	aux->item = element;
	this->listSize++;
}

template<typename T>
DoubleLinkedList<T>::DoubleLinkedList(int newSize, T element){
	initialize(newSize, element);
}

template<typename T>
int DoubleLinkedList<T>::size(){
	return this->listSize;
}

template<typename T>
bool DoubleLinkedList<T>::validatePosistion(int position){
	if(0 <= position && position < this->listSize){
		return true;
	}
	return false;
}

template<typename T>
T DoubleLinkedList<T>::get(int position){
	Node<T>* it = this->head->next;
	for(int i = 0; i < position; i++){
		it = it->next;
	}
	return it->item;
}

template<typename T>
void DoubleLinkedList<T>::update(int position, T newValue){
	Node<T>* it = this->head->next;

	for(int i = 0; i < position; i++){
		it = it->next;
	}
	it->item = newValue;
}

template<typename T>
void DoubleLinkedList<T>::remove(int position){
	Node<T>* it = this->head->next;
	for(int i = 0; i < position; i++){
		it = it->next;
	}
	it->prev->next = it->next;
	it->next->prev = it->prev;
	this->listSize--;
	delete it;
}

template<typename T>
void DoubleLinkedList<T>::print(){
	Node<T>* it = this->head->next;
	if(listSize > 0) std::cout << it->item;
	for(int i = 1; i < this->listSize; i++){
		it = it->next;
		std::cout << ' ' << it->item;
	}
	std::cout << std::endl;
}

template<typename T>
bool DoubleLinkedList<T>::contain(T value) {
    Node<T>* it = this->head->next;
	for(int i = 0; i < this->listSize; i++){
        if (it->item == value) {
    		it = it->next;
            return true;
        }
	}

    return false;
}

template<typename T1, typename T2>
class Dictionary{
private:
  T1 key;
  T2 value;
  
public:
	Dictionary();
	Dictionary(T1 newKey, T2 newValue);
	T1 getKey();
	T2 getValue();
 
};

template<typename T1, typename T2>
Dictionary<T1, T2>::Dictionary(){

}

template<typename T1, typename T2>
Dictionary<T1, T2>::Dictionary(T1 newKey, T2 newValue){
  this->key = newKey;
  this->value = newValue;
}

template<typename T1, typename T2>
T1 Dictionary<T1, T2>::getKey(){
  return this->key;
}

template<typename T1, typename T2>
T2 Dictionary<T1, T2>::getValue(){
  return this->value;
}

class Graph{
private:
	int order;
	int size;
	Dictionary<int, double> **adj;
    void initialize(int newOrder);
    bool validateVertices(int source, int destination);

public:
	Graph();
	Graph(int order);
	int getOrder();
	int getSize();
	void insertEdge(int source, int destination, double weight);
    double getWeight(int source, int destination);
    void setWeight(int source, int destination, double weight);
	void print();
	DoubleLinkedList<BrainEdge> getNeighbors(int id);
};

Graph::Graph(){
	this->size = 0;
    this->order = 0;
	this->adj = NULL;
}

Graph::Graph(int newOrder){
    this->size = 0;
    this->order = 0;
	this->adj = NULL;

	initialize(newOrder);
}

int Graph::getOrder(){
	return this->order;
}

int Graph::getSize(){
	return this->size;
}

void Graph::initialize(int newOrder){
	this->order = newOrder;
    this->adj = new Dictionary<int, double>*[newOrder];
	
	for(int i=0; i < newOrder; i++) {
        this->adj[i] = new Dictionary<int, double>[newOrder];
    }
    for(int i = 0; i < newOrder; i++){
    	for(int j = 0; j < newOrder; j++){
    		adj[i][j] = Dictionary<int, double>(-1, -1);
    	}
    }
}

bool Graph::validateVertices(int source, int destination){
  if(0 <= source && source < this->order){
    if(0 <= destination && destination < this->order){
      return true;
    }
    return false;
  }
  return false;
}

void Graph::insertEdge(int source, int destination, double weight){
    if (this->validateVertices(source, destination) ) {    
        Dictionary<int, double> dictionary = Dictionary<int, double>(this->size, weight);
        this->adj[source][destination] = dictionary;
        this->adj[destination][source] = dictionary;
	    this->size++;
    }
}

double Graph::getWeight(int source, int destination){
  if(this->validateVertices(source, destination)){
    Dictionary<int, double> dictionary = this->adj[source][destination];
    double weight = dictionary.getValue();

    return weight;
  }

  return 0;
}

void Graph::setWeight(int source, int destination, double weight){
  if(validateVertices(source, destination)){
    Dictionary<int, double> dictionary = this->adj[source][destination];
    int key = dictionary.getKey();
    this->adj[source][destination] = Dictionary<int, double>(key, weight);
  }
}

void Graph::print(){
	cout << "         ";
	for(int u=1; u <= this->order; u++){
		cout << setw(3) << u << " ";
	}
	cout << endl;
	
	for(int u=0; u < this->order; u++){
		std::cout << "adj[" << (u + 1) << "] = ";
		for(int v=0; v < this->order; v++){
            std::cout << setw(3) << this->adj[u][v].getValue() << ' ';
        }
        std::cout << std::endl;
	}
}

DoubleLinkedList<BrainEdge> Graph::getNeighbors(int id) {
	DoubleLinkedList<BrainEdge> neighbors = DoubleLinkedList<BrainEdge>();
	for(int i = 0; i < this->order; i++) {
		double weight = this->getWeight(id, i);
		if (weight > 0) {	
			BrainEdge brainEdge = BrainEdge(i, weight);	
			neighbors.insert(brainEdge);
		}
	}
	
	return neighbors;
}

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

class Block {
private:
    int size;
    int order;
    DoubleLinkedList<Neuron> neuronList;
    bool health;

public:
    Block();
    Block(int newSize, int newOrder);
    int getSize();
    int getOrder();
    DoubleLinkedList<Neuron> getNeuronList();
    Neuron getNeuron(int index);
    void insertNeuron(Neuron neuron);
    bool isHealth();
};

Block::Block() {
    this->size = 0;
    this->order = 0;
    this->neuronList = DoubleLinkedList<Neuron>();
    this->health = true;
}

Block::Block(int newSize, int newOrder) {
    this->size = newSize;
    this->order = newOrder;
    this->neuronList = DoubleLinkedList<Neuron>();
    this->health = true;
}

int Block::getSize() {
    return this->size;
}

int Block::getOrder() {
    return this->order;
}

Neuron Block::getNeuron(int index) {
    Neuron neuron = this->neuronList.get(index);
    return neuron;
}

DoubleLinkedList<Neuron> Block::getNeuronList(){
	return this->neuronList;
}

void Block::insertNeuron(Neuron neuron) {
    this->neuronList.insert(neuron);
    if (!neuron.isHealth()){
        this->health = false;
    }        
}

bool Block::isHealth() {
    return this->health;
}

template<typename T>
class Heap{
public:
	T* A;
	int extent;
	Heap();
	Heap(T [],int);
	void printHeap();
	int parent(int);
	int left(int);
	int right(int);
	void minHeapfy(int);
	void buildMinHeapfy();
	void heapSort();
};

template<typename T>
Heap<T>::Heap(){
	extent = 0;
	
	A = new T[1];
}

template<typename T>
Heap<T>::Heap(T V[], int tam){
	extent = 0;

	A = new T[1];
	T* aux = NULL;	
		
	for(int i = 0; i < tam; i++){
		extent = extent + 1;
		
		aux = static_cast<T*>( realloc (A, (extent + 1) * sizeof(T)) );
		A = aux;
		A[extent] = V[i];
	}

	buildMinHeapfy();
}

template<typename T>
void Heap<T>::printHeap(){
	if(extent > 0){	
		for(int i = 1; i <= extent; i++){
			cout << A[i] << ' ';
		}
		cout << endl;		
	}
	else{
		cout << "Heap empty!" << endl;
	}
}

template<typename T>
int Heap<T>::parent(int i){
	return (i / 2);
}

template<typename T>
int Heap<T>::left(int i){
	return (2 * i);
}

template<typename T>
int Heap<T>::right(int i){
	return (2 * i + 1);
}

template<typename T>
void Heap<T>::minHeapfy(int i){
	int l = left(i);
	int r = right(i);
	int menor;
	
	if((l <= extent) && (A[l] < A[i])){
		menor = l;
	} else{
		menor = i;
	}
	
	if((r <= extent) && (A[r] < A[menor])){
		menor = r;
	}
	
	if(menor != i){
		T aux = A[i];
		A[i] = A[menor];
		A[menor] = aux;
		
		minHeapfy(menor);
	}
}

template<typename T>
void Heap<T>::buildMinHeapfy(){
	for(int i = (extent / 2); i >= 1; i--){
		minHeapfy(i);
	}
}

template<typename T>
void Heap<T>::heapSort(){
	buildMinHeapfy();
	
	int sizeAuxiliar = extent;
	
	for(int i = extent; i >= 2; i--){
		T aux = A[1];
		A[1] = A[i];
		A[i] = aux;
		
		extent = extent - 1;
		minHeapfy(1);
	}
	
	extent = sizeAuxiliar;
}

template<typename T>
class PriorityQueue{
private:
	Heap<T> hp;
	int INF = 1000000123;
public:
	PriorityQueue();
	PriorityQueue(T[], int);
	T front();
	void pop();
	void increaseKey(int,T);
	void push(T);
	int empty();
	void printPQ();
};

template<typename T>
PriorityQueue<T>::PriorityQueue(){

}

template<typename T>
PriorityQueue<T>::PriorityQueue(T V[], int tam){
	Heap<T> src(V, tam);
	hp = src;
}

template<typename T>
T PriorityQueue<T>::front(){
	return hp.A[1];	
}

template<typename T>
void PriorityQueue<T>::pop(){
	if(hp.extent == 0){
		return;
	}
	
	hp.A[1] = hp.A[hp.extent];
	hp.extent = hp.extent - 1;

	T* aux = NULL;
	aux = static_cast<T*>( realloc (hp.A, (hp.extent + 1) * sizeof(T)) );
	hp.A = aux;

	hp.minHeapfy(1);
}

template<typename T>
void PriorityQueue<T>::increaseKey(int i, T key){
	if(key < hp.A[i]){
		return;
	}
	
	hp.A[i] = key;
	
	while((i > 1) && (hp.A[hp.parent(i)] > hp.A[i])){
		T aux = hp.A[i];
		hp.A[i] = hp.A[hp.parent(i)];
		hp.A[hp.parent(i)] = aux;
		
		i = hp.parent(i);
	}
}

template<typename T>
void PriorityQueue<T>::push(T key){
	
	hp.extent = hp.extent + 1;
	
	T* aux = NULL;
	aux = static_cast<T*>( realloc (hp.A, (hp.extent + 1) * sizeof(T)) );
	hp.A = aux;
	hp.A[hp.extent] = key;
	
	increaseKey(hp.extent, key);
}

template<typename T>
int PriorityQueue<T>::empty(){
	return (hp.extent == 0);
}

template<typename T>
void PriorityQueue<T>::printPQ(){
	hp.printHeap();
}

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

class Vertex {
private:
	int id;
	DoubleLinkedList<Edge<Vertex*> > edgeList;

public:
    Vertex();
    Vertex(int newBlockId);
    DoubleLinkedList<Vertex> getNeighbors(Graph graph);
    void insertNeighbor(Vertex vertex, double weight);
    int getId();
    Edge<Vertex*> getEdge(int neighborId);

};

Vertex::Vertex() {
	this->id = -1;
	this->edgeList = DoubleLinkedList<Edge<Vertex*> >();
}

Vertex::Vertex(int newBlockId) {
	this->id = newBlockId;
	this->edgeList = DoubleLinkedList<Edge<Vertex*> >();	
}

DoubleLinkedList<Vertex> Vertex::getNeighbors(Graph graph) {
	DoubleLinkedList<Vertex> neighbors = DoubleLinkedList<Vertex>();
	this->edgeList = DoubleLinkedList<Edge<Vertex*> >();
	
	int order = graph.getOrder();
	for(int i = 0; i < order; i++) {
		double weight = graph.getWeight(this->id, i);
		if (weight > 0) {
			Vertex vertexNeighbor1 = Vertex(i);
			neighbors.insert(vertexNeighbor1);
			
			Vertex* vertexNeighbor = new Vertex(i);
			Edge<Vertex*> edge = Edge<Vertex*>(this, vertexNeighbor, weight);
			
			this->edgeList.insert(edge);
		}
	}

	return neighbors;
}

void Vertex::insertNeighbor(Vertex vertex, double weight) {	
	Vertex* vertexSource = new Vertex(this->id); 
	Vertex* vertexDestination = new Vertex(vertex.getId());	
	Edge<Vertex*> edge = Edge<Vertex*> (vertexSource, vertexDestination, weight);
	this->edgeList.insert(edge);
}

int Vertex::getId() {
	return this->id;
}

Edge<Vertex*> Vertex::getEdge(int neighborId) {
	Edge<Vertex*> edge = this->edgeList.get(neighborId);
	return edge;
}


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
	for(int i = 0; i < graphOrder; i++){
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

template<typename T>
class QuickSort {
public:
	QuickSort();	
	int partition(DoubleLinkedList<T>& A, int low, int high);
	void sort(DoubleLinkedList<T>& A, int low, int high);

};

template<typename T>
QuickSort<T>::QuickSort() {

}

template<typename T>
int QuickSort<T> ::partition(DoubleLinkedList<T>& A, int low, int high){
  T pivot = A.get(low);
  T temp = A.get(high + 1);
  A.update(high + 1, pivot);

  int i = low, j = high + 1;

  while(i <= j){
    do{
        i++;
    }while(A.get(i) < pivot);
    do{
        j--;
    }
    while(A.get(j) > pivot);
    if(i < j){
      T aux = A.get(i);
      A.update(i, A.get(j));
      A.update(j, aux);
    }
  }
  T aux = A.get(low);
  A.update(low, A.get(j));
  A.update(j, aux);

  A.update(high + 1, temp);

  return j;
}

template<typename T>
void QuickSort<T>::sort(DoubleLinkedList<T>& A, int low, int high){
  if(low < high){
    int q = partition(A, low, high);
    sort(A, low, q - 1);
    sort(A, q + 1, high);
  }
}

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

class ReadBrain {
private:
	int input;
	int output;
    int size;
    int order;
    Graph graph;
    void insertEdge(int source, int destination, double weight);
    void createGraph(int newOrder);

public:
    ReadBrain();
    int getSize();
    int getOrder();
    double getWeight(int source, int destination);
    void readFromDefaultInput();
    int getInput();
   	int getOutput();
   	Graph getGraph();
};

void ReadBrain::insertEdge(int source, int destination, double weight) {    
    this->graph.insertEdge(source, destination, weight);
}

void ReadBrain::createGraph(int newOrder) {
    this->graph = Graph(order);
}

ReadBrain::ReadBrain() {
    this->size = 0;
    this->order = 0;
    this->graph = Graph();
}

int ReadBrain::getSize() {
    return this->size;
}

int ReadBrain::getOrder() {
    return this->order;
}

double ReadBrain::getWeight(int source, int destination) {
    double weight = this->graph.getWeight(source, destination);
    return weight;
}


void ReadBrain::readFromDefaultInput() {
    std::cin >> this->order >> this->size;
    
    this->createGraph(this->order);

    int source, destination;
    double weight;
    for (int i = 0; i < this->size; i++) {
        std::cin >> source >> destination >> weight;
        this->insertEdge(source - 1, destination - 1, weight);
    }
	std::cin >> this->input >> this->output;
	this->input--;
	this->output--;
}   

int ReadBrain::getInput() {
	return this->input;
}

int ReadBrain::getOutput() {
	return this->output;
}

Graph ReadBrain::getGraph() {
	return this->graph;
}

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

	for (int i = 0; i < this->amountBlocks; i++) {		
		int blockOrder, blockSize;
		std::cin >> blockOrder >> blockSize;

		int amountDiseaseNeurons;
		std::cin >> amountDiseaseNeurons;
		
		int indexNeuron;
	    DoubleLinkedList<int> diseaseNeurons = DoubleLinkedList<int>();	
		for(int j = 0; j < amountDiseaseNeurons; j++) {
			std::cin >> indexNeuron;		
			diseaseNeurons.insert(indexNeuron - 1);			
		}	
		
		Block block = Block(blockSize, blockOrder);
		int source, destination;
		double weight;
		for (int j = 0; j < blockSize; j++) {
			std::cin >> source >> destination >> weight;
		
			bool result = diseaseNeurons.contain(source - 1);
			Neuron neuron = Neuron(source - 1, destination - 1, weight, !result);
			
			block.insertNeuron(neuron);
			
			result = diseaseNeurons.contain(destination - 1);
			neuron = Neuron(destination - 1, source - 1, weight, !result);
			
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
//	graph.print();
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
    	
//    		cout << "vertexId: " << (vertexId) << endl;
    	if (!isHealth) {
    		Graph graphBlock = this->readsBlocks.getGraph(vertexId);  
//    		graphBlock.print(); 
    		
    		Kruskal kruskal = Kruskal(graphBlock);
			kruskal.execute();
			
			double cost = kruskal.getMinSpanningTreeWeight();
//			cout << "cost: " << cost << endl;
			totalCost += cost;
    	}
    }
    
    std::cout << totalCost << std::endl;
//	cout << endl;
}

int main(int argc, char **argv) {

	Task task = Task();
    task.execute();

	return 0;
}
