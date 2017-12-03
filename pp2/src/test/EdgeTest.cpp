# include <iostream>
# include "../lib/Edge.h"

using namespace std;

bool test();

int main() {

    bool result = test();

    cout << "Edge: ";
    if (result) {
        cout << "GOOD" << endl;
    } else {
        cout << "NO_GOOD" << endl;
    }   

    return 0;
}

bool test() {
    
    Edge<int>  edge = Edge<int>(123, 456, 2.5);
    
    int count = 0;
    
    count += (edge.getSource() == 123);
    count += (edge.getDestination() == 456);
    count += (edge.getWeight() == 2.5);
    
    int amountTests = 3;
    
    if (count == amountTests) {
        return true;
    } else {
        return false;
    }
}
