#ifndef HEAP_H
#define HEAP_H

#include<iostream>
#include<vector>

using namespace std;

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
		
		aux = (T*) realloc (A, (extent + 1) * sizeof(T));
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

#endif
