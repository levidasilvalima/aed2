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
	Neuron neurons[9];
	int count, amount;
	
    neurons[0] = Neuron(1, 2, 1.2, true);
    neurons[1] = Neuron(1, 2, 1.3, true);
    neurons[2] = Neuron(1, 2, 2.5, true);
    neurons[3] = Neuron(1, 2, 3.8, true);
    neurons[4] = Neuron(1, 2, 5.13, true);
    neurons[5] = Neuron(1, 2, 8.21, true);
    neurons[6] = Neuron(1, 2, 13.34, true);
    neurons[7] = Neuron(1, 2, 21.55, true);
    neurons[8] = Neuron(1, 2, 35.89, true);


    list.insert(Neuron(1, 2, 1.3, true));
    list.insert(Neuron(1, 2, 5.13, true));
    list.insert(Neuron(1, 2, 1.2, true));
    list.insert(Neuron(1, 2, 21.55, true));
    list.insert(Neuron(1, 2, 2.5, true));
    list.insert(Neuron(1, 2, 35.89, true));
    list.insert(Neuron(1, 2, 8.21, true));
    list.insert(Neuron(1, 2, 13.34, true));
    list.insert(Neuron(1, 2, 3.8, true));
    

    quick.sort(list, 0, 8);
    
    count = 0;
    
    for(int i=0; i < 9; i++){
		count += (neurons[i] == list.get(i));
    }
    
    amount = 9;
        
    if(count == amount){
    	return true;
    }
    return false;
    
    return true;
}

// function body to Unit Test
