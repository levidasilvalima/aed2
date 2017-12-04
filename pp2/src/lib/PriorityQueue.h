#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include"Heap.h"
#include<iostream>
#include<vector>

using namespace std;

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
	// Testar o que acontece com o construtor vazio
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
	hp.A.pop_back();
	
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
	hp.A.push_back(key);
	
	hp.extent = hp.A.size() - 1;
	//cout << "Ultimo: " << hp.A[hp.extent] << endl;
	//cout << "Extent: " << hp.extent << endl;
	increaseKey(hp.extent, key);
	//cout << "Ultimo depois: " << hp.A[hp.extent] << endl;
}

template<typename T>
int PriorityQueue<T>::empty(){
	return (hp.extent == 0);
}

template<typename T>
void PriorityQueue<T>::printPQ(){
	hp.printHeap();
}
#endif
