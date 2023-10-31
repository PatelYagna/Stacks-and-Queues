#include "conversion.h"
#include "queue.h"

using namespace std;
int x = true;
int main() {
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
			/*case 1:
				break;*/
			case 2:
				int number;
				cout << "Enter Number: ";
				cin >> number;
				insertNumberInBackOfQueue(number);
				displayTheQueue();
				break;
			case 3:
				removeFrontNumberInQueue();
				break;
			case 4:
				viewFrontNumberInQueue();
				break;
			case 5:
				isQueueEmpty();
				break;
			case 6:
				sizeOfQueue();
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
