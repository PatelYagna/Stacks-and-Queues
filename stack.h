#include <string>
#include <iostream>
#include <stack>
using namespace std;

int operatorCheck(char row)
{
	if (row == '^')
		return 3;
	else if (row == '/' || row == '*')
		return 2;
	else if (row == '+' || row == '-')
		return 1;
	else
		return -1;
};

bool orgCheck(string infixInput) {
	stack<char> brackets;
	bool isBalanced = true;
	char open[] = { '(' , '[' , '{' };
	char close[] = { ')' , ']' , '}' };

	for (auto i : infixInput) {
		for (char j : open) {
			if (i == j) {
				brackets.push(i);
			}
		}

		for (int j = 0; j < 3; j++) {
			if(i == close[j]) {
				if (brackets.top() == open[j]) {
					brackets.pop();
				}
				else {
					isBalanced = false;
				}
			}
		}

	}

	if (brackets.empty()) {
		isBalanced = true;
		return true;
	}
	else {
		isBalanced = false;
		cout << "INVALID!" << endl;
		return false;
	}
};

void inPostFix(string infixInput) {
	stack<char> stack1;
	string output = "";
	char row;
	//int balanced = 0;
	//char currRow;
	//cout << infixInput;

	for (int i = 0; i < infixInput.length(); i++) {
		row = infixInput[i];


		if ((row >= 'a' && row <= 'z') || (row >= 'A' && row <= 'Z') || (row >= '0' && row <= '9')) {
			output += row;
			//cout << output << endl;
		}
		else {
			//orgCheck(infixInput);
			while (!stack1.empty() && operatorCheck(infixInput[i]) <= operatorCheck(stack1.top())) {
				output += stack1.top();
				stack1.pop();
			}
			if ((row != '(') && (row != ')') && (row != '{') && (row != '}') && (row != '[') && (row != ']'))
				stack1.push(row);
		}
	}

	while (!stack1.empty()) {
		output += stack1.top();
		stack1.pop();
	}

	if (orgCheck(infixInput) == true) {
		cout << output << endl;
	}
};