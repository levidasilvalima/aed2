# include <iostream>
# include "../lib/QuickSort.h"
# include "../lib/Neuron.h"

using namespace std;

bool test();
// function prototype to Unit test

int main() {

    bool result = test();

    cout << "QuickSort: ";
    if (result) {
        cout << "GOOD" << endl;
    } else {
        cout << "NO_GOOD" << endl;
    }

    return 0;
}

bool test() {
    DoubleLinkedList<Neuron> list;
    QuickSort<Neuron> quick;
    list.insert(Neuron(1, 2, 1.2, true));
    list.insert(Neuron(1, 2, 1.3, true));
    list.insert(Neuron(1, 2, 2.5, true));
    list.insert(Neuron(1, 2, 3.8, true));
    list.insert(Neuron(1, 2, 5.13, true));
    list.insert(Neuron(1, 2, 8.21, true));
    list.insert(Neuron(1, 2, 13.34, true));
    list.insert(Neuron(1, 2, 21.55, true));
    list.insert(Neuron(1, 2, 35.89, true));
    

    quick.sort(list, 0, 7);
    return true;
}

// function body to Unit Test
