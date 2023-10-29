#include "conversion.h"
#include "queue.h"
#include <iostream>

using namespace std;

int main() {
	int input;
	while (input != 7){
		
		cout << "1. Infix to Postfix"
			 << "2. Insert Element in Queue"
			 << "3. Remove Front Element in Queue"
			 << "4. View Front Element in Queue"
			 << "5. Check if Queue is Empty"
			 << "6. Size of Queue"
			 << "7. Quit"
			 << "Enter Option: ";
		cin >> input;
		
		switch(input){
			/*case 1:
				break;*/
			case 2:
				int number;
				cout << "Enter Number: ";
				cin >> number;
				insert(number);
				display();
				break;
			
			/*case 3:
				break;
			case 3:
				break;
			case 3:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;*/
			default:
				cout << "INVALID INPUT" << endl;
				break;
		}
	}
}
