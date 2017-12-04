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
	PriorityQueue<double> pq;//(a, 10);


	pq.push(4.1);
	pq.printPQ();
	pq.push(1.1);
	pq.printPQ();
	pq.push(3.2);
	pq.printPQ();
	pq.push(32.3);
	pq.printPQ();
	pq.push(16.5);
	pq.printPQ();
	pq.push(9.8);
	pq.printPQ();
	pq.push(10.13);
	pq.printPQ();
	pq.push(14.21);
	pq.printPQ();
	
	int count = 0;
	count += (pq.front() == 1.1);
	pq.pop();
	pq.printPQ();
	count += (pq.front() == 3.2);
	pq.pop();
	pq.printPQ();
	count += (pq.front() == 4.1);
	pq.pop();
	pq.printPQ();
	count += (pq.front() == 9.8);
	pq.pop();
	pq.printPQ();
	count += (pq.front() == 10.13);
	pq.pop();
	pq.printPQ();
	count += (pq.front() == 14.21);
	pq.pop();
	pq.printPQ();
	count += (pq.front() == 16.5);
	pq.pop();
	pq.printPQ();
	count += (pq.front() == 32.3);
	pq.pop();
	pq.printPQ();
	
	int amountTests = 8;
	if (count == amountTests) {
		return true;
	}

	return false;
}
