# include <iostream>
# include "../lib/Task.h"

using namespace std;

bool test();

int main() {

    bool result = test();

    cout << "Task: ";
    if (result) {
        cout << "GOOD" << endl;
    } else {
        cout << "NO_GOOD" << endl;
    }   

    return 0;
}

bool test() {

    Task task = Task();
    task.execute();

	return true;
}
