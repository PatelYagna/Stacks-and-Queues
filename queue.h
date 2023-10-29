#include <queue>

using namespace std;

queue<int> tqueue;

void insert(int number){
	tqueue.push(number);
}

void display() {
  while (!tqueue.empty()) {
	// Print the front element of the queue.
	cout << tqueue.front() << " ";
  }
}
