# include <iostream>
# include "../lib/Graph.h"

using namespace std;

bool test();
// function prototype to Unit test

int main() {

    bool result = test();

    cout << "Graph: ";
    if (result) {
        cout << "GOOD" << endl;
    } else {
        cout << "NO_GOOD" << endl;
    }

    return 0;
}

bool test() {
  Graph graph(5);
  int count;

  //validate insert
  for(int u=0; u < 5; u++){
    for(int v=0; v < 5; v++){
      graph.insertEdge(u, v, 1.0);
    }
  }

  // validate read
  count = 0;
  for(int u=0; u < 5; u++){
    for(int v=0; v < 5; v++){
      count += (1.0 == graph.getWeight(u, v));
    }
  }

  // validate update
  for(int u=0; u < 5; u++){
    for(int v=0; v < 5; v++){
      graph.setWeight(u, v, 2.0);
    }
  }

  for(int u=0; u < 5; u++){
    for(int v=0; v < 5; v++){
      count += (2.0 == graph.getWeight(u, v));
    }
  }

  if(count == 50){
    return true;
  }
  return false;
}

// function body to Unit Test
