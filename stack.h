#include <string>
#include <iostream>
using namespace std;

class Stack {
	private:
	// Node structure for the stack
	struct Node {
		char data;
		Node* next;
		Node(char value) : data(value), next(nullptr) {}
	};
	Node* top;  // Pointer to the top of the stack

	public:
	// Constructor to initialize the stack
	Stack() : top(nullptr) {}

	// Push a new element onto the stack
	void push(char value) {
		Node* newNode = new Node(value);
		newNode->next = top;
		top = newNode;
	}

	// Pop the top element from the stack
	void pop() {
		if (!isEmpty()) {
			Node* temp = top;
			top = top->next;
			delete temp;
		}
	}

	// Peek at the top element of the stack
	char peek() const {
		return (top != nullptr) ? top->data : '\0';
	}

	// Check if the stack is empty
	bool isEmpty() const {
		return top == nullptr;
	}

	// Destructor to deallocate memory used by the stack
	~Stack() {
		while (!isEmpty()) {
			pop();
		}
	}
};

// Function to check the precedence of operators
int operatorCheck(char row) {
	if (row == '^')
		return 3;
	else if (row == '/' || row == '*')
		return 2;
	else if (row == '+' || row == '-')
		return 1;
	else
		return -1;
};

// Function to check the balanced parentheses in the infix expression
bool orgCheck(string infixInput, Stack& brackets) {
	bool isBalanced = true;
	char open[] = { '(', '[', '{' };
	char close[] = { ')', ']', '}' };

	for (auto i : infixInput) {
		for (char j : open) {
			if (i == j) {
				brackets.push(i);
			}
		}

		for (int j = 0; j < 3; j++) {
			if (i == close[j]) {
				if (!brackets.isEmpty() && brackets.peek() == open[j]) {
					brackets.pop();
				} else {
					isBalanced = false;
				}
			}
		}
	}

	if (brackets.isEmpty()) {
		isBalanced = true;
		return true;
	} else {
		isBalanced = false;
		cout << "INVALID!" << endl;
		return false;
	}
};

// Function to convert infix expression to postfix
void inPostFix(string infixInput) {
	Stack stack1;
	string output = "";
	char row;

	// Loop through each character in the infix expression
	for (int i = 0; i < infixInput.length(); i++) {
		row = infixInput[i];

		// If the character is an operand, add it to the output
		if ((row >= 'a' && row <= 'z') || (row >= 'A' && row <= 'Z') || (row >= '0' && row <= '9')) {
			output += row;
		} else {
			// If the character is an operator, handle precedence and associativity
			while (!stack1.isEmpty() && operatorCheck(infixInput[i]) <= operatorCheck(stack1.peek())) {
				output += stack1.peek();
				stack1.pop();
			}
			if ((row != '(') && (row != ')') && (row != '{') && (row != '}') && (row != '[') && (row != ']'))
				stack1.push(row);
		}
	}

	// Pop any remaining operators from the stack
	while (!stack1.isEmpty()) {
		output += stack1.peek();
		stack1.pop();
	}

	// Check for balanced parentheses and display the postfix expression
	if (orgCheck(infixInput, stack1)) {
		cout << output << endl;
	}
};
