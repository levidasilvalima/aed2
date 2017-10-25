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
    int boardToGraph(int i, int j);
    Pair<int, int> graphToBoard(int v);    
};

int Map::boardToGraph(int i, int j) {
    return i*8 + j;
}

Pair<int, int> Map::graphToBoard(int v) {
    int i = v/8;
    int j = v%8;
    Pair<int, int> pair = Pair<int, int>(i, j);
    return pair;
}

// END - Map ----------------------------------------------------------



void listTest();
void pairTest();
void mapTest();

int main() {

    mapTest();

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
