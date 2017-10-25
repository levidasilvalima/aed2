#include<iostream>
#include<vector>

using namespace std;

// START - List ------------------------------------------------------
class List {
private:
    vector<int> elements;
public:   
    List(int size);
    List();
    int size();
    void insert(int element);
    int get(int position);
    void update(int position, int newValue);
    void remove(int position); 
    void print();
};

List::List(int size) {
    this->elements.assign(size, -1);
}

List::List():List(0) {}

int List::size() {
    return this->elements.size();
}

void List::insert(int element) {
    this->elements.push_back(element);
}

int List::get(int position) {
    int elementsSize = this->elements.size();

    if ( position >= 0 && position < elementsSize) {
        return this->elements[position];
    }
    
    return -1;
}

void List::update(int position, int newValue) {
    int elementsSize = this->elements.size();

    if ( position >= 0 && position < elementsSize) {
        this->elements[position] = newValue;
    }
}

void List::remove(int position) {
    int elementsSize = this->elements.size();

    if ( position >= 0 && position < elementsSize) {
        vector<int>::iterator it = this->elements.begin();
        this->elements.erase(it + position);
    }
}

void List::print() {
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
    List list = List();
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
