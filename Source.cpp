#include <iostream>
using namespace std;

template <typename T>				//using templates for generic data types
struct node {						//structure for storing data using queues
	T data;							//variable for storing value
	node<T>* next;					//pointer for linking one value to another
};

template <typename T>
class queue {						//queue class implementation
	node<T>* rear;					//pointer for performing operation on queue
public:
	queue() {
		rear = NULL;				//making rear point to NULL in the start
	}
	~queue() {
		makeempty();				//making queue empty in destructor
	}
	void push(const T& val) {		//function for pushing values to queue
		if (full()) {				//if queue is full then throwing exception
			throw "Cannot add data, Queue is full!\n";
		}
		node<T>* temp;				//pointer of node type
		temp = new node<T>;			//allocating new memory
		temp->data = val;			//storing value in data type
		if (rear == NULL) {			//if queue is empty
			temp->next = temp;		//then pointing rear
			rear = temp;			//to itself
		}
		else {
			temp->next = rear->next;		//else previous node to
			rear->next = temp;				//next node and rear's next
			rear = temp;					//part to first node
		}
	}
	void pop() {				//function for removing values
		if (empty()) {			//if queue is empty then throwing exception
			throw "Cannot remove data, Queue is empty!\n";
		}
		node<T>* temp;			//pointer of node type
		temp = rear->next;		//pointer to first node
		if (temp == rear) {		//if pointing to rear node
			rear = NULL;		//then making rear NULL
			delete temp;		//and deleting temp
		}
		else {
			rear->next = temp->next;		//if not then moving rear to second node
			delete temp;					//and deleting temp
		}
	}
	T front() {					//function for getting data at queue's front
		if (empty()) {			//if queue is empty then throwing exception
			throw "Cannot get data, Queue is empty!\n";
		}
		return rear->next->data;	//else returning value at front
	}
	bool full() {				//function for checking whether queue is full or not
		node<T>* temp;			//checking by allocating a
		temp = new node<T>;		//a new memory
		if (temp == NULL) {		//if memory is not allocated then
			return true;		//returning true
		}
		else {					//if allocated
			delete temp;		//then deleting memory
			return false;		//and returning false
		}
	}
	bool empty() {				//function for checking if queue is empty or not
		return rear == NULL;	//if rear=NULL then returning true
	}
	void makeempty() {			//function for making queue empty
		while (!empty()) {		//while queue is not empty
			pop();				//deleting elements one by one
		}
	}
};

int main()						//client code
{
	queue<int> q;				//declaring a queue of integer type
	q.push(1); q.push(7); q.push(4); q.push(9);		//pushing four values in queue
	while (!q.empty()) {				//while queue is not empty
		cout << q.front() << "	";		//displaying values at front
		q.pop();						//and removing them one by one
	}
	cout << endl;
	try {								//handling exception by using try block
		cout << q.front() << endl;		//by removing data from
		q.pop();						//an empty queue
	}
	catch (const char* msg) {			//catching exception
		cout << msg;					//and displaying message thrown by exception
	}
	return 0;
}