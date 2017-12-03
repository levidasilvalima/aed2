# include <iostream>
# include "../lib/ReadBlocks.h"
# include "../lib/ReadBrain.h"

using namespace std;

bool test();

int main() {

    bool result = test();

    cout << "ReadBlocks: ";
    if (result) {
        cout << "GOOD" << endl;
    } else {
        cout << "NO_GOOD" << endl;
    }   

    return 0;
}

bool test() {
    
    ReadBrain readBrain = ReadBrain();
    readBrain.readFromDefaultInput();

	int amountBlocks = readBrain.getOrder();
    ReadBlocks readBlocks = ReadBlocks(amountBlocks);
    readBlocks.readFromDefaultInput();

    return true;
}
