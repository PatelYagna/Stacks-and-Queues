#include <iostream>
#include <queue>
#include <limits>

using namespace std;

queue<int> tqueue;

void displayTheQueue() {
	for (int i = 0; i < tqueue.size(); i++){
		cout << tqueue.front() << " ";
		tqueue.push(tqueue.front());
		tqueue.pop();
  }
	cout << endl;
}

void insertNumberInBackOfQueue(int& number){
	tqueue.push(number);
}

void removeFrontNumberInQueue() {
	if (!tqueue.empty()) {
		int item = tqueue.front();
		cout << "Removed: " << item << endl;
		tqueue.pop();
	}
	else {
		cout << "Queue is Empty." << endl;
	}
}

void viewFrontNumberInQueue(){
	if (!tqueue.empty()) {
		int item = tqueue.front();
		cout << "Front Number: " << item << endl;
	}
	else {
		cout << "Queue is Empty." << endl;
	}
}

void isQueueEmpty(){
	if (tqueue.empty()){
		cout << "Queue is Empty" << endl;
	}
	else{
		cout << "Queue is NOT Empty" << endl;
	}
}

void sizeOfQueue(){
	cout << "Size: " << tqueue.size() << endl;
}
