#include <iostream>
#include <limits>
#include <string>

using namespace std;

// Node structure for the linked list used in the queue
template <typename item_Type>
struct Node { 
	item_Type data;  // Data of the node
	Node* next;      // Pointer to the next node
};

// Queue class template
template <typename item_Type>
class queue {
private:
	Node<item_Type>* head;  // Pointer to the front of the queue
	Node<item_Type>* tail;  // Pointer to the rear of the queue
	int num_Items;         // Number of items in the queue

public:
	// Constructor to initialize the queue
	queue() {
		head = nullptr;
		tail = nullptr;
		num_Items = 0;
	};

	// Destructor to deallocate memory used by the queue
	~queue() {
		while (head != nullptr){
			Node<item_Type>* tempNode = head;
			head = head->next;
			delete tempNode;
		}
	};

	// Enqueue an item into the queue
	item_Type enQueue(){
		item_Type item = ask();
		Node<item_Type>* tempNode = new Node<item_Type>;
		tempNode->data = item;
		tempNode->next = nullptr;
		if (isEmpty()){ 
			head = tempNode; 
		}
		else { 
			tail->next = tempNode; 
		}
		tail = tempNode;
		num_Items++;
		return tail->data;
	};

	// Dequeue an item from the queue
	item_Type deQueue(){
		if (isEmpty()) {
			cout << "Empty List!" << endl;
			return "Nothing Removed";
		}
		else {
			Node<item_Type>* tempNode = head;
			item_Type removedData = head->data;
			head = head->next;
			delete tempNode;
			if (head == nullptr){
				tail = nullptr;
			}
			num_Items--;
			cout << "Removed: " << removedData << endl;
			return removedData;
		}
	};

	// View the front item in the queue
	item_Type viewFront(){
		if (isEmpty()){
			return "Empty List!";
		}
		else {
			cout << "Front Item: " ;
			return head->data;
		}
	};

	// Check if the queue is empty
	bool isEmpty(){
		return num_Items == 0;
	};

	// Get the size of the queue
	int queueSize(){
		return num_Items;
	};

	// Display the items in the queue
	void display(){
		if (isEmpty()) {
			cout << "Empty List!" << endl;
		}
		else {
			Node<item_Type>* tempNode = head;
			while (tempNode != nullptr) {
				cout << tempNode->data << " ";
				tempNode = tempNode->next;
			}
			cout << endl;
		}
	};

	// Ask the user to enter a number and return it
	item_Type ask(){
		item_Type input;
		cout << "Enter Number: ";
		cin >> input;
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		return input;
	};
};
