# include <iostream>
# include "../lib/Neuron.h"

using namespace std;

bool test();

int main() {

    bool result = test();

    cout << "Node: ";
    if (result) {
        cout << "GOOD" << endl;
    } else {
        cout << "NO_GOOD" << endl;
    }   

    return 0;
}

bool test() {
    
    Neuron neuron1 = Neuron(1, 2, 3.5, true);   
    Edge edge = Edge(3, 4, 55);
    Neuron neuron2 = Neuron(edge, false); 
    Neuron neuron3 = Neuron(1, 2, 3.5, true);   
    
    int count = 0;
    
    count += (neuron1 < neuron2);
    count += (neuron2 > neuron1);
    count += 1 - (neuron1 > neuron3);
    count += (neuron1.getSource() == 1);
    count += (neuron1.getDestination() == 2);
    count += (neuron1.getWeight() == 3.5);
    count += (neuron1.isHealth() == true);
    count += (neuron2.getSource() == 3);
    count += (neuron2.getDestination() == 4);
    count += (neuron2.getWeight() == 55);
    count += (neuron2.isHealth() == false);
    
    int amountTests = 11;
    
    if (count == amountTests) {
        return true;
    } else {
        return false;
    }    
}
