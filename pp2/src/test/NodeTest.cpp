#include<iostream>
#include"../lib/Node.h"

using namespace std;

bool test();
bool isEquals(Node<int>* node1, Node<int>* node2);

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
    Node<int>* node1 = new Node<int>();
    Node<int>* node2 = new Node<int>();
    Node<int>* node3 = new Node<int>();

    // create circular link 1-2-3-1
    node2->next = node3;
    node2->prev = node1;

    node3->next = node1;
    node3->prev = node2;

    node1->next = node2;
    node1->prev = node3;

    // create tests
    int count = 0;    
    count += isEquals(node1->next, node2);
    count += isEquals(node1->prev, node3);
    count += isEquals(node2->next, node3);
    count += isEquals(node2->prev, node1);
    count += isEquals(node3->next, node1);
    count += isEquals(node3->prev, node2);

    int amountTests = 6;

    // if all are GOOD so all are GOOD
    if (count == amountTests) {
        return true;
    } else {
        return false;
    }
}

bool isEquals(Node<int>* node1, Node<int>* node2) {
    if (node1 == node2) {
        return true;
    } else {
        return false;
    }
}
