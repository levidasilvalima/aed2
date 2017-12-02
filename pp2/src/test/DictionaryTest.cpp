# include <iostream>
# include "../lib/Dictionary.h"

using namespace std;

bool test();
// function prototype to Unit test

int main() {

    bool result = test();

    cout << "Dictionary: ";
    if (result) {
        cout << "GOOD" << endl;
    } else {
        cout << "NO_GOOD" << endl;
    }

    return 0;
}

bool test() {
  Dictionary<double, Dictionary<int, char> > dictionary(5.0, Dictionary<int, char>(7, 'c'));
  int cont;
  // validate getKey
  cont = 0;
  cont += (dictionary.getKey() == 5.0);

  // validate getValue

  cont += (dictionary.getValue().getKey() == 7);
  cont += (dictionary.getValue().getValue() == 'c');

  if(cont == 3){
    return true;
  }
  return false;
}

// function body to Unit Test
