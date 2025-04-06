#include <iostream>
using namespace std;

//Dinh nghia
struct Node
{
	char* info;
	Node* next;
};

struct Queue
{
	Node* head;
	Node* tail;
};

//Khoi tao rong
void init(Queue& q) {
	q.head = q.tail = NULL;
}


//Thao tac chen
Node* createNode(char* x) {
	Node* p = new Node;
	p->info = x;
	p->next = NULL;
	return p;
}

void enQueue(Queue& q, char* x) {
	Node* p = createNode(x);
	if (q.head == NULL) {
		q.head = q.tail = p;
		return;
	}

	q.tail->next = p;
	q.tail = p;
}

//Thao tac lay tu hang doi
char* deQueue(Queue& q) {
	char* res = NULL;

	if (q.head == NULL)
		return NULL;

	Node* p = q.head;
	q.head = q.head->next;

	if (q.head == NULL)
		q.tail = NULL;

	res = p->info;
	delete p;

	return res;
}


bool isEmpty(Queue q) {
	return q.head == NULL;
}
