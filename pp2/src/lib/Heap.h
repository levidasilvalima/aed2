#ifndef HEAP_H
#define HEAP_H

#include<iostream>
#include<vector>

using namespace std;

template<typename T>
class Heap{
public:
	vector<T> A;
	int extent;
	Heap();
	Heap(T [],int);
	void printHeap();
	int parent(int);
	int left(int);
	int right(int);
	void maxHeapfy(int);
	void buildMaxHeapfy();
	void heapSort();
};

template<typename T>
Heap<T>::Heap(){
	extent = 0;
	A.push_back(-1);
}

template<typename T>
Heap<T>::Heap(T V[], int tam){
	A.clear();
	A.push_back(-1);
	for(int i = 0; i < tam; i++){
		A.push_back(V[i]);
	}
	extent = A.size() - 1;

	buildMaxHeapfy();
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
void Heap<T>::maxHeapfy(int i){
	int l = left(i);
	int r = right(i);
	int maior;
	
	if((l <= extent) && (A[l] > A[i])){
		maior = l;
	} else{
		maior = i;
	}
	
	if((r <= extent) && (A[r] > A[maior])){
		maior = r;
	}
	
	if(maior != i){
		T aux = A[i];
		A[i] = A[maior];
		A[maior] = aux;
		
		maxHeapfy(maior);
	}
}

template<typename T>
void Heap<T>::buildMaxHeapfy(){
	for(int i = (extent / 2); i >= 1; i--){
		maxHeapfy(i);
	}
}

template<typename T>
void Heap<T>::heapSort(){
	buildMaxHeapfy();
	
	for(int i = extent; i >= 2; i--){
		T aux = A[1];
		A[1] = A[i];
		A[i] = aux;
		
		extent = extent - 1;
		maxHeapfy(1);
	}
	
	extent = A.size() - 1;
}

#endif
