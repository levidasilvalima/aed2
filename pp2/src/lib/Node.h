# ifndef NODE_H
# define NODE_H

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

# endif
