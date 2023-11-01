#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<int> tstack;

bool isAllowedChar(char c); // Function prototype

void isBalanced() {
	string infix;
	cout << "Enter Infix Expression: ";
	getline(cin, infix);
	for (int i = 0; i < infix.length(); i++) {
		if (isAllowedChar(infix[i]) == false) {
			cout << "Invalid character: " << infix[i] << endl;
			return;
		}
		tstack.push(infix[i]);
	}

	if (!tstack.empty()) {
		int item = tstack.top();
		cout << item << " ";
		tstack.pop();
	} else {
		cout << "Stack is Empty!" << endl;
	}
}

bool isAllowedChar(char c) {
	const char* allowedChars = "{[(]})\\//+-*%";
	int length = 12; // Manually set the length of allowedChars
	for (int i = 0; i < length; i++) {
		if (c == allowedChars[i]) {
			return true;
		}
	}
	return false;
}
