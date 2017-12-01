#include<iostream>
#include"../lib/Item.h"

using namespace std;

bool test();
// function prototype to Unit test

int main() {

    bool result = test();

    cout << "Item: ";
    if (result) {
        cout << "GOOD" << endl;
    } else {
        cout << "NO_GOOD" << endl;
    }

    return 0;
}

bool test() {
  Item<double, Item<int, char> > item(5.0, Item<int, char>(7, 'c'));
  int cont;
  // validate getKey
  cont = 0;
  cont += (item.getKey() == 5.0);

  // validate getValue

  cont += (item.getValue().getKey() == 7);
  cont += (item.getValue().getValue() == 'c');

  if(cont == 3){
    return true;
  }
  return false;
}

// function body to Unit Test
