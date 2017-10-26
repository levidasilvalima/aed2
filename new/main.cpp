#include<iostream>
#include<vector>

using namespace std;

// START - List ------------------------------------------------------
template<typename T>
class List {

private:
    vector<T> elements;

public:
    List(int size);
    List();
    int size();
    void insert(T element);
    bool validatePosistion(int position);
    T get(int position);
    void update(int position, T newValue);
    void remove(int position);
    void print();
};

template<typename T>
List<T>::List(int size) {
    this->elements.assign(size, -1);
}

template<typename T>
List<T>::List():List(0) {}

template<typename T>
int List<T>::size() {
    return this->elements.size();
}

template<typename T>
void List<T>::insert(T element) {
    this->elements.push_back(element);
}

template<typename T>
bool List<T>::validatePosistion(int position) {
  int elementSize = this->elements.size();
  if (position >= 0 && position < elementSize) {
    return true;
  }
  
  return false;
}

template<typename T>
T List<T>::get(int position) {

    if (validatePosistion(position)) {
        return this->elements[position];
    }

    return -1;
}


template<typename T>
void List<T>::update(int position, T newValue) {

    if (validatePosistion(position)) {
        this->elements[position] = newValue;
    }
}

template<typename T>
void List<T>::remove(int position) {

    if (validatePosistion(position)) {
        vector<int>::iterator it = this->elements.begin();
        this->elements.erase(it + position);
    }
}

template<typename T>
void List<T>::print() {
    int elementsSize = this->elements.size();
    for(int i = 0; i < elementsSize; i++) {
        cout << this->elements[i] << " ";
    }
    cout << endl;
}

// END - List --------------------------------------------------------

// START - Pair ------------------------------------------------------

template<typename T1, typename T2>
class Pair {

public:
    T1 first;
    T2 second;
    Pair(T1 first, T2 second);
};

template<typename T1, typename T2>
Pair<T1, T2>::Pair(T1 i, T2 j) {
    this->first = i;
    this->second = j;
}

// END - Pair ---------------------------------------------------------

// START - Map -------------------------------------------------------

class Map {

public:
    int boardToGraph(int row, int column);
    Pair<int, int> graphToBoard(int vertex);
};

int Map::boardToGraph(int row, int column) {
    return row*8 + column;
}

Pair<int, int> Map::graphToBoard(int vertex) {
    int row = vertex/8;
    int column = vertex%8;
    Pair<int, int> pair = Pair<int, int>(row, column);
    return pair;
}

// END - Map ----------------------------------------------------------


// START - Queue ----------------------------------------------------------

template<typename T>
class Queue{
private:
	vector<T> q;
public:
	Queue();
	void push(T);
	T front();
	void pop();
	bool empty();
};

template<typename T>
Queue<T>::Queue(){
	this->q.clear();
}

template<typename T>
void Queue<T>::push(T item){
	this->q.push_back(item);
}

template<typename T>
T Queue<T>::front(){
	return this->q[0];
}

template<typename T>
void Queue<T>::pop(){
	this->q.erase(this->q.begin());
}

template<typename T>
bool Queue<T>::empty(){
	return this->q.size() == 0;
}

// END - Queue ----------------------------------------------------------


// START - Graph ----------------------------------------------------------

class Graph{
private:
	int order;
	int size;
	List<int> *adj;
	void destroy();

public:
	Graph();
	Graph(int order);
	void initialize(int newOrder);
	void insertEdge(int source, int destination);
	List<int> getAdj();
	int getSize();	
	int getOrder();	
	void print();
};

Graph::Graph(){
	this->size = 0;
    this->order = 0;
	this->adj = NULL;
}

Graph::Graph(int newOrder){
	initialize(newOrder);
}

void Graph::initialize(int newOrder){
	this->order = newOrder;

	adj = new List<int>[newOrder + 1];
}

void Graph::insertEdge(int source, int destination){
	adj[source].insert(destination); // key and vertice are same
	adj[destination].insert(source);
	this->size++;
}

void Graph::print(){
	for(int i=1; i <= this->order; i++){
		cout << "adj[" << i << "] = ";
		adj[i].print();
	}
}

// END - Graph ----------------------------------------------------------


void listTest();
void pairTest();
void mapTest();
void queueTest();
void graphTest();

int main() {

<<<<<<< HEAD
    graphTest();

=======
    mapTest();
	graphTest();
	queueTest();
>>>>>>> c1f08b7df0d4e87323f33b2eb8be187d89e67369
    return 0;
}

// Test fucntions

void listTest() {
    List<int> list = List<int>();
    int listSize = 5;
    int array[] = {1, 2, 3, 4, 5};

    for(int i = 0; i < listSize; i++) {
        int element = array[i];
        list.insert(element);
    }

    list.print();
    list.update(2, 9);
    list.print();
    list.remove(4);
    list.print();
}

void pairTest() {
    Pair<int, int> pair = Pair<int,int>(1, 2);
    cout << pair.first << " " << pair.second << endl;
}

void mapTest() {
    Map map = Map();
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            cout << i << " " << j << " ";

            int vertex = map.boardToGraph(i,j);

            cout << vertex << " ";

            Pair<int, int> pair = map.graphToBoard(vertex);

            cout << pair.first << " " << pair.second << endl;
        }
    }
}

void queueTest(){
	Queue<int> q;
	for(int i=0; i < 10; i++) q.push(i);
	while(!q.empty()){
		int u = q.front(); q.pop();
		cout << u << ' ';
	}
	cout << endl;
}

void graphTest(){
	Graph g(5);
	g.insertEdge(1, 2);
	g.insertEdge(2, 3);
	g.insertEdge(3, 4);
	g.insertEdge(4, 5);
	g.insertEdge(5, 1);
	g.insertEdge(5, 2);
	g.insertEdge(2, 4);

	g.print();
}
