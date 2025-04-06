#include <iostream>
using namespace std;

//Dinh nghia
struct Node
{
	int info;

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
Node* createNode(int x) {
	Node* p = new Node;
	p->info = x;
	p->next = NULL;
	return p;
}

void enQueue(Queue& q, int x) {
	Node* p = createNode(x);
	if (q.head == NULL) {
		q.head = q.tail = p;
		return;
	}


	q.tail->next = p;
	q.tail = p;
}

//Thao tac lay tu hang doi
int deQueue(Queue& q) {
	int res = -1;

	if (q.tail == NULL)
		return -1;

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

int main() {
	Queue q;
	init(q);

	enQueue(q, 9);
	enQueue(q, 10);
	enQueue(q, 12);
	enQueue(q, 16);

	while (!isEmpty(q)) {
		cout << deQueue(q) << " ";
	}

	return 0;
}