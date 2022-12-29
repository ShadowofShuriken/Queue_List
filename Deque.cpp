#include "Deque.h"

///------------------------------------------------------
/// Default constructor
/// 
Deque::Deque() {
	this->head = NULL;
	this->tail = NULL;
	noOfItems = 0;
} //end-Deque

///------------------------------------------------------
/// Destructor
/// 
Deque::~Deque() {
	while (this->head) {
		DequeNode* node = this->head;
		this->head = this->head->next;	//deleting nodes until nothing is left
		delete node;
	}
} //end-~Deque


void Deque::AddFront(int item) {
	DequeNode* node = new DequeNode(item);
	if (this->head==NULL)		//checking empty
	{
		this->head = node;
		this->tail = node;
	}
	else
	{
		node->next = this->head;	//node adding head of list
		this->head->prev = node;	
		this->head = node;			//node becomes head
	}
	this->noOfItems++;
} //end-AddFront


void Deque::AddRear(int item) {
	DequeNode* node = new DequeNode(item);
	if (this->tail == NULL)		//checking empty
	{
		this->head = NULL;
		this->tail = node;
	}
	else {
		node->prev = this->tail;	//node adding end of list
		this->tail->next = node;
		this->tail = node;			//node becomes tail
	}
	this->noOfItems++;
} //end-AddRear


int Deque::RemoveFront() {
	if (this->head == NULL)
	{
		throw std::exception(" Empty Dequeue");
	}

	int item= this->head->item;
	DequeNode* node = this->head;
	this->head = this->head->next; // next item becomes head

	if (this->head==NULL)
	{
		this->tail = NULL;  //checking empty
	}
	else
	{
		this->head->prev = NULL; // next of previous item =NULL
	}
	delete node;
	this->noOfItems--;
	
	return item;
} //end-RemoveFront


int Deque::RemoveRear() {
	if (this->head == NULL)
	{
		throw std::exception(" Empty Dequeue");
	}

	int item = this->tail->item;
	DequeNode* node = this->tail;
	this->tail = this->tail->prev;  // previous item becomes tail
	
	if (this->tail==NULL)
	{
		this->head = NULL;  //checking empty
	}
	else
	{
		this->tail->next = NULL;   // prev of next item =NULL
	}
	delete node;
	this->noOfItems--;

	return item;
} //end-RemoveRear


int Deque::Front() {
	if (this->head == NULL)
	{
		throw std::exception(" Empty Dequeue");
	}
	return this->head->item;
} //end-Front


int Deque::Rear() {
	if (this->head == NULL)
	{
		throw std::exception(" Empty Dequeue");
	}
	return this->tail->item;
} //end-Rear
