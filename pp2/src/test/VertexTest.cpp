# include <iostream>
# include "../lib/Vertex.h"

using namespace std;

bool test();

int main() {

    bool result = test();

    cout << "Vertex: ";
    if (result) {
        cout << "GOOD" << endl;
    } else {
        cout << "NO_GOOD" << endl;
    }   

    return 0;
}

bool test() {

	Vertex vertex = Vertex(1);
	Vertex vertex2 = Vertex(2);

	vertex.insertNeighbor(vertex2, 6.0);

	return true;
}
