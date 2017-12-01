# include "Node.h"

# ifndef DOUBLE_LINKED_LIST
# define DOUBLE_LINKED_LIST

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
	for(int i=0; i < newSize; i++){
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
	for(int i=0; i < position; i++){
		it = it->next;
	}
	return it->item;
}

template<typename T>
void DoubleLinkedList<T>::update(int position, T newValue){
	Node<T>* it = this->head->next;

	for(int i=0; i < position; i++){
		it = it->next;
	}
	it->item = newValue;
}

template<typename T>
void DoubleLinkedList<T>::remove(int position){
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
void DoubleLinkedList<T>::print(){
	Node<T>* it = this->head->next;
	if(listSize > 0) std::cout << it->item;
	for(int i=1; i < this->listSize; i++){
		it = it->next;
		std::cout << ' ' << it->item;
	}
	std::cout << std::endl;
}

# endif
