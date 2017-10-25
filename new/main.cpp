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
T List<T>::get(int position) {
    int elementsSize = this->elements.size();

    if ( position >= 0 && position < elementsSize) {
        return this->elements[position];
    }
    
    return -1;
}

template<typename T>
void List<T>::update(int position, T newValue) {
    int elementsSize = this->elements.size();

    if ( position >= 0 && position < elementsSize) {
        this->elements[position] = newValue;
    }
}

template<typename T>
void List<T>::remove(int position) {
    int elementsSize = this->elements.size();

    if ( position >= 0 && position < elementsSize) {
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

void listTest();

int main() {

    listTest();

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
