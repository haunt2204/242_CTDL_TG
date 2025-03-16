#include <iostream>
#include <fstream>
using namespace std;

struct Node
{
	//Vung thong tin
	int data;

	//Vung lien ket
	Node* next;
	Node* prev;
};

struct DoublyLinkedList 
{
	Node* head;
	Node* tail;
};

//Khoi tao
void init(DoublyLinkedList& l) {
	l.head = l.tail = NULL;
}

//Kiem tra rong
bool isEmpty(DoublyLinkedList l) {
	return l.head == NULL;
}

//Thao tac them phan tu vao dau
Node* createNode(const int x) {
	Node* p = new Node;
	p->data = x;
	p->next = p->prev = NULL;
	return p;
}

void insertFirst(DoublyLinkedList &l, int x) {
	Node* p = createNode(x);
	if (l.head == NULL) {
		l.head = l.tail = p;
	}
	else {
		p->next = l.head;
		l.head->prev = p;
		l.head = p;
	}
}

void insertOrderedList(DoublyLinkedList& l, int x) {
	//Danh sach rong
	if (isEmpty(l)) {
		l.head = l.tail = createNode(x);
		return;
	}
	
	Node* p = createNode(x);
	//Them dau danh sach
	if (x < l.head->data) {
		p->next = l.head;
		l.head->prev = p;
		l.head = p;
		return;
	}

	Node* cur = l.head;
	while (cur->next != NULL && cur->next->data < x) {
		cur = cur->next;
	}
	//Them vao cuoi danh sach
	if (cur == l.tail) {
		l.tail->next = p;
		p->prev = l.tail;
		l.tail = p;
		return;
	}

	//Them vao giua danh sach
	p->next = cur->next;
	cur->next->prev = p;

	cur->next = p;
	p->prev = cur;
}

//Thao tac tim kiem: max, min, key (xuat hien dau tien)
bool isMax(int a, int b) {
	return a > b;
}

bool isMin(int a, int b) {
	return a < b;
}

Node* findExtremum(DoublyLinkedList l, bool func(int, int)) {
	if (isEmpty(l))
		return NULL;
	Node* p = l.head->next;
	Node* res = l.head;

	while (p != NULL) {

		if (func(p->data, res->data))
			res = p;

		p = p->next;
	}

	return res;
}

Node* findNode(DoublyLinkedList l, int key) {
	if (isEmpty(l))
		return NULL;
	Node* p = l.head;

	while (p != NULL) {
		if (p->data == key)
			return p;

		p = p->next;
	}

	return NULL;
}

//Them sau phan tu mang gia tri key
void insertAfter(DoublyLinkedList& l, int key, int x) {
	Node *q = findNode(l, key);
	if (q == NULL) {
		cout << "Khong tim thay: " << key << " trong danh sach!\n";
		return;
	}

	Node* p = createNode(x);
	if (q == l.tail) {
		q->next = p;
		p->prev = q;
		l.tail = p;
		return;
	}

	p->next = q->next;
	q->next->prev = p;

	q->next = p;
	p->prev = q;
}

//Duyet danh sach
void printListFromHead(DoublyLinkedList l) {
	if (l.head == NULL) {
		cout << "Danh sach rong!\n";
		return;
	}
	Node* p = l.head;
	while (p != NULL) {
		cout << p->data << "\t";
		p = p->next;
	}
	cout << endl;
}

//Thao tac xoa phan tu
void delFirst(DoublyLinkedList& l) {
	if (l.head == NULL) {
		cout << "Danh sach rong!\n";
		return;
	}
	Node* p = l.head;
	l.head = p->next;
	if (l.head == NULL) {
		l.tail = NULL;
	}else
		l.head->prev = NULL;

	p->next = p->prev = NULL;
	delete p;
}
//Thao tac giai phong
void detroyList(DoublyLinkedList& l) {
	while (!isEmpty(l)) {
		delFirst(l);
	}
	cout << "Da giai phong danh sach!\n";
}

int main() {
	//Dinh nghia
	DoublyLinkedList l;

	//Khoi tao 
	init(l);


	//Thao tac tren danh sach
	insertFirst(l, 9);
	insertFirst(l, 13);
	insertFirst(l, 5);
	insertFirst(l, 7);
	insertFirst(l, 1);

	insertAfter(l, 9, 1111);

	printListFromHead(l);

	Node *res = findNode(l, 6);
	if (res != NULL) {
		cout << res->data << endl;
	}
	else
		cout << "Khong tim thay!\n";
	/*insertOrderedList(l, 5);
	insertOrderedList(l, 2);
	insertOrderedList(l, 8);
	insertOrderedList(l, 4);*/

	

	//Thao tac giai phong
	detroyList(l);

	return 0;
}