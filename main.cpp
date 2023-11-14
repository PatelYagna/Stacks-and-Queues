#include "stack.h" 
#include "queue.h"   

using namespace std; 

int main() {
	int input = 0; 
	queue<string> list;  // Declare a queue named 'list' of strings
	string infixInput; 

	// Main loop to display menu and handle user input until '7' is entered
	while (input != 7) {
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

		// Switch statement to perform actions based on user input
		switch (input) {
			case 1:
				// Convert infix expression to postfix
				cout << "Enter Infix: ";
				cin.ignore(10000, '\n');  // Ignore any remaining characters in the input buffer
				getline(cin, infixInput);  // Read the entire line as infix input
				inPostFix(infixInput);  // Call a function (not defined in the provided code)
				break;

			case 2:
				// Insert element in the queue
				list.enQueue();
				list.display();
				break;

			case 3:
				// Remove front element from the queue
				list.deQueue();
				list.display();
				break;

			case 4:
				// View front element in the queue
				cout << list.viewFront() << endl;
				break;

			case 5:
				// Check if the queue is empty and display the result
				if (list.isEmpty() == 0) {
					cout << "Queue is NOT Empty" << endl;
				} else {
					cout << "Queue is Empty" << endl;
				}
				break;

			case 6:
				// Display the size of the queue
				cout << "Size: " << list.queueSize() << endl;
				break;

			case 7:
				// Quit the program
				break;

			default:
				// Handle invalid input, clear input buffer and ignore extra characters
				cout << "INVALID INPUT" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
		}
	}
}
