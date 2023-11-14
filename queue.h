#include <iostream>
#include <limits>
#include <string>

using namespace std;

template <typename item_Type>
struct Node { 
	item_Type data; 
	Node* next; 
};

template <typename item_Type>
class queue {
	private:
		Node<item_Type>* head;
		Node<item_Type>* tail;
		int num_Items;

	public:
		queue() {
			head = nullptr;
			tail = nullptr;
			num_Items = 0;
		};


		~queue() {
			while (head != nullptr){
				Node<item_Type>* tempNode = head;
				head = head->next;
				delete tempNode;
			}
		};

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

		item_Type viewFront(){
			if (isEmpty()){
				return "Empty List!";
			}
			else {
				cout << "Front Item: " ;
				return head->data;
			}
		};

		bool isEmpty(){
			return num_Items == 0;
		};

		int queueSize(){
			return num_Items;
		};

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

		item_Type ask(){
			item_Type input;
			cout << "Enter Number: ";
			cin >> input;
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			return input;
		};
};