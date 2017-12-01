# include <iostream>
# include "../lib/Block.h"

using namespace std;

bool test();

int main() {

    bool result = test();

    cout << "Block: ";
    if (result) {
        cout << "GOOD" << endl;
    } else {
        cout << "NO_GOOD" << endl;
    }   

    return 0;
}

bool test() {

    Block block = Block();    
    
    Neuron neuron1 = Neuron(1, 2, 4, true);
    block.insertNeuron(neuron1);
    
    Neuron neuron2 = Neuron(2, 3, 5, true);
    block.insertNeuron(neuron2);

    Neuron neuron3 = Neuron(3, 1, 6, false);
    block.insertNeuron(neuron3);
    
    int count = 0;
    
    neuron1 = block.getNeuron(0);
    count += (neuron1.getSource() == 1);
    count += (neuron1.getDestination() == 2);
    count += (neuron1.getWeight() == 4);
    count += (neuron1.isHealth() == true);
    
    neuron2 = block.getNeuron(1);
    count += (neuron2.getSource() == 2);
    count += (neuron2.getDestination() == 3);
    count += (neuron2.getWeight() == 5);
    count += (neuron2.isHealth() == true);
    
    neuron3 = block.getNeuron(2);
    count += (neuron3.getSource() == 3);
    count += (neuron3.getDestination() == 1);
    count += (neuron3.getWeight() == 6);
    count += (neuron3.isHealth() == false);
    
    count += (block.isHealth() == false);    
    
    int amountTests = 13;
    
    if (count == amountTests) {
        return true;
    } else {
        return false;
    }

}
