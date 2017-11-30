#include<iostream>
#include"../lib/DoubleLinkedList.h"

using namespace std;

bool test();

int main() {

    bool result = test();

    cout << "DoubleLinkedList: ";
    if (result) {
        cout << "GOOD" << endl;
    } else {
        cout << "NO_GOOD" << endl;
    }   

    return 0;
}

bool test() {
    DoubleLinkedList<int> list = DoubleLinkedList<int>();
    int listSize = 5;
    int array1[] = {1, 2, 3, 4, 5};
    int array2[] = {1, 2, 9, 4, 5};
    int array3[] = {1, 2, 9, 4};

    for(int i = 0; i < listSize; i++) {
        int element = array1[i];
        list.insert(element);
    }

    // validate insertion
    int count = 0;
    int count1 = 0;
    for(int i = 0; i < listSize; i++) {
        count1 += (list.get(i) == array1[i]);
    }
    count += (count1 == listSize);

    // validate update
    list.update(2, 9);
    count1 = 0;
    for(int i = 0; i < listSize; i++) {
        count1 += (list.get(i) == array2[i]);
    }
    count += (count1 == listSize);

    // validate remove
    list.remove(4);
    count1 = 0;
    for(int i = 0; i < listSize - 1; i++) {
        count1 += (list.get(i) == array3[i]);
    }
    count += (count1 == listSize - 1);

    int amountTest = 3;

    if (count == amountTest) {
        return true;
    } else {
        return false;
    }
}
