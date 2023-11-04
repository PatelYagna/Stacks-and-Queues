#include "conversion.h"
#include "queue.h"

using namespace std;

int main() {
	int x = true;
	queue<string> list;
	while (x){
		int input;
		cout << endl 
			 << "1. Infix to Postfix" << endl
			 << "2. Insert Element in Queue" << endl
			 << "3. Remove Front Element in Queue" << endl
			 << "4. View Front Element in Queue" << endl
			 << "5. Check if Queue is Empty" << endl
			 << "6. Size of Queue" << endl
			 << "7. Quit" << endl
			 << "Enter Option: ";
		cin >> input;
		
		switch(input){
			case 1:
				break;
			case 2:
				list.enQueue();
				list.display();
				break;
			case 3:
				list.deQueue();
				break;
			case 4:
				cout << list.viewFront() << endl;
				break;
			case 5:
				if (list.isEmpty() == 0){
					cout << "Queue is NOT Empty" << endl;
				}
				else {
					cout << "Queue is Empty" << endl;
				}
				break;
			case 6:
				cout << "Size " << list.queueSize() << endl;
				break;
			case 7:
				x = false;
				break;
			default:
				cout << "INVALID INPUT" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
		}
	}
}
