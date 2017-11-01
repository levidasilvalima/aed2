#include<iostream>
#include<vector>

using namespace std;

// START - Node ------------------------------------------------------
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

// END - Node ------------------------------------------------------

// START - List ------------------------------------------------------
template<typename T>
class List{
private:
	Node<T>* head;
	Node<T>* tail;
	int listSize;

public:
	List();
	List(int newSize, T element);
	int size();
	void insert(T element);
	bool validatePosistion(int position);
	T get(int position);
	void update(int position, T newValue);
	void remove(int position);
	void print();
};

template<typename T>
List<T>::List(){
	this->listSize = 0;
	this->head = new Node<T>();
	this->tail = new Node<T>();
	this->head->next = this->tail;
	this->tail->prev = this->head;
}

template<typename T>
List<T>::List(int newSize, T element){
	for(int i=0; i < newSize; i++){
		insert(element);
	}
}

template<typename T>
int List<T>::size(){
	return this->listSize;
}

template<typename T>
void List<T>::insert(T element){
	Node<T>* aux = new Node<T>();

	this->tail->prev->next = aux;
	aux->prev = this->tail->prev;
	aux->next = this->tail;
	this->tail->prev = aux;
	aux->item = element;
	this->listSize++;
}

template<typename T>
bool List<T>::validatePosistion(int position){
	if(0 <= position && position < this->listSize){
		return true;
	}
	return false;
}

template<typename T>
T List<T>::get(int position){
	Node<T>* it = this->head->next;
	for(int i=0; i < position; i++){
		it = it->next;
	}
	return it->item;
}

template<typename T>
void List<T>::update(int position, T newValue){
	Node<T>* it = this->head->next;
	for(int i=0; i < position; i++){
		it = it->next;
	}
	it->item = newValue;
}

template<typename T>
void List<T>::remove(int position){
	Node<T>* it = this->head->next;
	for(int i=0; i < position; i++){
		it = it->next;
	}
	it->prev->next = it->next;
	it->next->prev = it->prev;
	this->listSize--;
	delete it;
}

template<typename T>
void List<T>::print(){
	Node<T>* it = this->head->next;
	if(listSize > 0) cout << it->item;
	for(int i=1; i < this->listSize; i++){
		it = it->next;
		cout << ' ' << it->item;
	}
	cout << endl;
}

// END - List ------------------------------------------------------

// START - List ------------------------------------------------------
// template<typename T>
// class List {
//
// private:
//     vector<T> elements;
//
// public:
//     List(int size);
//     List();
//     int size();
//     void insert(T element);
//     bool validatePosistion(int position);
//     T get(int position);
//     void update(int position, T newValue);
//     void remove(int position);
//     void print();
// };
//
// template<typename T>
// List<T>::List(int size) {
//     this->elements.assign(size, 0);
// }
//
// template<typename T>
// List<T>::List():List(0) {}
//
// template<typename T>
// int List<T>::size() {
//     return this->elements.size();
// }
//
// template<typename T>
// void List<T>::insert(T element) {
//     this->elements.push_back(element);
// }
//
// template<typename T>
// bool List<T>::validatePosistion(int position) {
//   int elementSize = this->elements.size();
//   if (position >= 0 && position < elementSize) {
//     return true;
//   }
//
//   return false;
// }
//
// template<typename T>
// T List<T>::get(int position) {
//
//     if (validatePosistion(position)) {
//         return this->elements[position];
//     }
//
//     return -1;
// }
//
//
// template<typename T>
// void List<T>::update(int position, T newValue) {
//
//     if (validatePosistion(position)) {
//         this->elements[position] = newValue;
//     }
// }
//
// template<typename T>
// void List<T>::remove(int position) {
//
//     if (validatePosistion(position)) {
//         vector<int>::iterator it = this->elements.begin();
//         this->elements.erase(it + position);
//     }
// }
//
// template<typename T>
// void List<T>::print() {
//     int elementsSize = this->elements.size();
//     for(int i = 0; i < elementsSize; i++) {
//         cout << this->elements[i] << " ";
//     }
//     cout << endl;
// }

// END - List --------------------------------------------------------

// START - Pair ------------------------------------------------------

template<typename T1, typename T2>
class Pair {

public:
    T1 first;
    T2 second;
	Pair();
    Pair(T1 first, T2 second);
};

template<typename T1, typename T2>
Pair<T1, T2>::Pair(){}

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
	List<int>* getAdj();
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

List<int>* Graph::getAdj(){
	return this->adj;
}

int Graph::getSize(){
	return this->size;
}

int Graph::getOrder(){
	return this->order;
}

void Graph::insertEdge(int source, int destination){
	adj[source].insert(destination); // key and vertice are same
	// adj[destination].insert(source);
	this->size++;
}


void Graph::print(){
	for(int i=0; i < this->order; i++){
		cout << "adj[" << i << "] = ";
		adj[i].print();
	}
}

// END - Graph ----------------------------------------------------------

// START - Sort --------------------------------------------------------

class Sort {
private:
 	const int ARRAY_SIZE = 64;
public:
	Sort();
	void counting(List<int>& list);
};
Sort::Sort() {}

 /*
 * Because elemnts are distinct on list and it are
 * initialized  ith zero, just update  array to one
 * will make counting sort work for this problem
 */
void Sort::counting(List<int>& list) {
    List<int> array(ARRAY_SIZE, 0);
	int arraySize = array.size();

    for(int i = 0; i < arraySize; i++) {
		    int element = list.get(i);
		    array.update(element, 1);
     }

	int index = 0;
	for(int i = 0; i < ARRAY_SIZE; i++) {
		if(array.get(i) != 0 ) {
			list.update(index, i);
			index++;
		}
	}
}

// END - Sort ----------------------------------------------------------

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
void build(Graph &g){
	int dir[] = {1, 1, -1, -1, 2, 2, -2, -2};
	int esq[] = {2, -2, 2, -2, 1, -1, 1, -1};

	Map map;
	int v, di, dj;
	Pair<int, int> rowColumn;

	g = Graph(64);

	for(int u=0; u < 64; u++){
		rowColumn = map.graphToBoard(u);

		for(int j=0; j < 8; j++){
			di = rowColumn.first + dir[j];
			dj = rowColumn.second + esq[j];

			if(0 <= di && di < 8 && 0 <= dj && dj < 8){
				v = map.boardToGraph(di, dj);
				g.insertEdge(u, v);
			}
		}
	}
}

void listaTest();
void listTest();
void pairTest();
void mapTest();
void graphTest();
void countSortTest();
void queueTest();

int main() {

    graphTest();

    return 0;
}

// Test fucntions

void listaTest() {
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

	build(g);

	cout << endl;

	g.print();
}

void countSortTest(){
	List<int> list;
	Sort sort = Sort();
	list.insert(5);
	list.insert(21);
	list.insert(13);
	list.insert(1);
	list.insert(8);
	list.insert(3);
	list.insert(2);

    list.print();

	sort.counting(list);

    list.print();
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
