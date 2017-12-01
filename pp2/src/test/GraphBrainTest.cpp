#include<iostream>
#include"../lib/GraphBrain.h"

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

    GraphBrain graphBrain = GraphBrain();
    graphBrain.readFromDefaultInput();

    return true;
}
