# include "../lib/PriorityQueue.h"

bool test();

int main(){

	bool result = test();
	
    cout << "PriorityQueue: ";
    if (result) {
        cout << "GOOD" << endl;
    } else {
        cout << "NO_GOOD" << endl;
    } 
	return 0;
}

bool test(){
	//int a[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
	PriorityQueue<int> pq;//(a, 10);

	pq.printPQ();
	pq.push(4);
	pq.printPQ();
	pq.push(1);
	pq.printPQ();
	pq.push(3);
	pq.printPQ();
	pq.push(32);
	pq.printPQ();
	pq.push(16);
	pq.printPQ();
	pq.push(9);
	pq.printPQ();
	pq.push(10);
	pq.printPQ();
	pq.push(14);
	pq.printPQ();
	
	while(!pq.empty()){
		cout << pq.front() << ' ';
		pq.pop();
	}
	cout << endl;

	return 1;
}
