# include <iostream>
# include "../lib/GraphBrainInput.h"

using namespace std;

bool test();

int main() {

    bool result = test();

    cout << "GraphBrainInput: ";
    if (result) {
        cout << "GOOD" << endl;
    } else {
        cout << "NO_GOOD" << endl;
    }   

    return 0;
}

bool test() {

    GraphBrainInput graphBrainInput = GraphBrainInput();
    graphBrainInput.readFromDefaultInput();

    return false;
}
