#include<iostream>
#include"YOUR_LIBRARY"

using namespace std;

bool test();
// function prototype to Unit test

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

}

// function body to Unit Test
