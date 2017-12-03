# include "../lib/Heap.h"

bool test();

int main(){

	bool result = test();
	
    cout << "Heap: ";
    if (result) {
        cout << "GOOD" << endl;
    } else {
        cout << "NO_GOOD" << endl;
    } 
	return 0;
}

bool test(){
	double a[] = {6.5, 4.1, 10.3, 2.141, 14.541, 16.1234, 23.5134, 3.1234, 7.6211, 5.14513, 2.142};

	Heap<double> hp(a, 11);
	
	hp.heapSort();
	
	// TODO finish test
	
	return 1;
}
