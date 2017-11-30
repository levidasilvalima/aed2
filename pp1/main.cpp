#include<iostream>
#include<vector>
#define INFINTE 11235813

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
class List{
private:
	Node<T>* head;
	Node<T>* tail;
	int listSize;

public:
	List();
	List(int newSize, T element);
	void initialize(int newSize, T element);
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
void List<T>::initialize(int newSize, T element){
	for(int i=0; i < newSize; i++){
		insert(element);
	}
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
List<T>::List(int newSize, T element){
	initialize(newSize, element);
}

template<typename T>
int List<T>::size(){
	return this->listSize;
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

class Sort {
private:
	const int ARRAY_SIZE = 64;
public:
	Sort();
	void counting(List<int>& list);
};
Sort::Sort() {}

void Sort::counting(List<int>& list) {
	List<int> array;
	array = List<int>();
	array = List<int>(64, 0);
	int listSize = list.size();
	for(int i = 0; i < listSize; i++) {
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
	void sort();
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
	adj[source].insert(destination);
	this->size++;
}

void Graph::sort(){
	Sort s;
	for(int i=0; i < this->order; i++){
		s.counting(this->adj[i]);
	}
}

void Graph::print(){
	for(int i=0; i < this->order; i++){
		cout << "adj[" << i << "] = ";
		adj[i].print();
	}
}

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

class Search{
private:
	const int WHITE = 0;
	const int GREY = 1;
	const int BLACK = 2;
	const int INF = 1000000123;
public:
	Search();
	List<int> breadthFirstSearch(Graph&,int);
};

Search::Search(){}

List<int> Search::breadthFirstSearch(Graph &g, int src){
	Queue<int> q;
	List<int> color;
	List<int> dist;
	dist.initialize(64, INF);
	color.initialize(64, WHITE);

	color.update(src, GREY);
	dist.update(src, 0);
	q.push(src);

	while(!q.empty()){
		int u = q.front(); q.pop();

		List<int>* adj = g.getAdj();
		int tam = adj[u].size();
		for(int i = 0; i < tam; i++){
			int v = adj[u].get(i);
			if(color.get(v) == WHITE){
				color.update(v, GREY);
				dist.update(v, dist.get(u) + 1);
				q.push(v);
			}
		}
		color.update(u, BLACK);
	}
	for(int i=0; i < dist.size(); i++){
		int element = dist.get(i);
		dist.update(i, element - 1);
	}
	return dist;

}

int main() {
	int n;
	cin >> n;
	for(int j=0; j < n; j++){
		Graph chess;
		Search search;
		List<int> dist, result;
		int min = INFINTE, source, knights[4];
		string king, knight;
		Map map;
		for(int i=0; i < 4; i++){
			cin >> knight;
			knights[i] = map.boardToGraph(knight[1] - 1 - '0', knight[0] - 'a');
		}
		cin >> king;

		source = map.boardToGraph(king[1] - 1 - '0', king[0] - 'a');

		build(chess);

		dist = search.breadthFirstSearch(chess, source);

		for(int i=0; i < 4; i++){
			int comp = dist.get(knights[i]);
			if(comp < min){
				min = comp;
			}
		}
		for(int i=0; i < 4; i++){
			int element = dist.get(knights[i]);
			if(element == min){

				result.insert(element);
			}
		}
		result.print();

	}

    return 0;
}
