# include <iostream>
# include "../lib/GraphBlockInput.h"
# include "../lib/GraphBrainInput.h"

using namespace std;

bool test();

int main() {

    bool result = test();

    cout << "GraphBlockInput: ";
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

    GraphBlockInput graphBlockInput = GraphBlockInput();
    graphBlockInput.readFromDefaultInput();

    return true;
}
