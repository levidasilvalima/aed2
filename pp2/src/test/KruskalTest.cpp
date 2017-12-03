# include <iostream>
# include "../lib/Kruskal.h"
# include "../lib/ReadBrain.h"
# include "../lib/ReadBlocks.h"

using namespace std;

bool test();

int main() {

    bool result = test();

    cout << "Kruskal: ";
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
    
    Graph graph = readBlocks.getGraph(13);
    
    Kruskal kruskal = Kruskal(graph);
    
	kruskal.execute();
	
	return true;
}
