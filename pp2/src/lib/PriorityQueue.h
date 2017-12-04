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
	aux = (T*) realloc (hp.A, (hp.extent + 1) * sizeof(T));
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
	aux = (T*) realloc (hp.A, (hp.extent + 1) * sizeof(T));
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
#endif	
