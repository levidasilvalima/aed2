#include<iostream>
#include"../lib/DoubleLinkedList.h"

using namespace std;

bool test();
bool check(DoubleLinkedList<int>* list, int array[]);

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
	DoubleLinkedList<int> listM(6, 5);

    int listSize = 5;
    int array1[] = {1, 2, 3, 4, 5};
    int array2[] = {1, 2, 9, 4, 5};
    int array3[] = {1, 2, 9, 4};
	int array4[] = {5, 5, 5, 5, 5, 5};

    for(int i = 0; i < listSize; i++) {
        int element = array1[i];
        list.insert(element);
    }

    int count = 0;

    // validate insertion
    count += check(&list, array1);

    // validate update
    list.update(2, 9);
    count += check(&list, array2);

    // validate remove
    list.remove(4);
    count += check(&list, array3);

	// validate Constructor

	count += check(&listM, array4);

    int amountTest = 4;

    if (count == amountTest) {
        return true;
    } else {
        return false;
    }
}

bool check(DoubleLinkedList<int>* list, int array[]) {
    int listSize = list->size();
    int count = 0;

    for(int i = 0; i < listSize; i++) {
        count += (list->get(i) == array[i]);
    }

    if (count == listSize) {
        return true;
    } else {
        return false;
    }
}
