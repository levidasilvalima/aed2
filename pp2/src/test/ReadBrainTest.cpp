# include <iostream>
# include "../lib/ReadBrain.h"

using namespace std;

bool test();

int main() {

    bool result = test();

    cout << "ReadBrain: ";
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

    // TODO finish test

    return true;
}
