#include <iostream>
#include <fstream>
#include <string>
using namespace std;

template <typename T>
struct Node
{
	//Vung thong tin
	T data;
	//Vung lien ket
	Node<T>* next;
};

template <typename T>
struct LinkedList
{
	Node<T>* head;
	Node<T>* tail;
};

//Khoi tao rong
template <typename T>
void init(LinkedList<T>& l) {
	l.head = l.tail = NULL;
}

//Thao tac them dau, them cuoi
template <typename T>
Node<T>* createNode(T x) {
	Node<T>* p = new Node<T>;
	p->data = x;
	p->next = NULL;
	return p;
}

template <typename T>
void insertFirst(LinkedList<T>& l, T newElm) {
	Node<T>* p = createNode(newElm);
	if (l.head == NULL) {
		l.head = p;
		l.tail = p;
	}
	else {
		p->next = l.head;
		l.head = p;
	}
}

template <typename T>
void insertLast(LinkedList<T>& l, T newElm) {
	Node<T>* p = createNode(newElm);
	if (l.head == NULL) {
		l.head = p;
		l.tail = p;
	}
	else {
		l.tail->next = p;
		l.tail = p;
	}
}

//Kiem tra danh sach rong
template <typename T>
bool isEmpty(const LinkedList<T> l) {
	return l.head == NULL;
}

//Thao tac duyet danh sach
template <typename T>
void printList(const LinkedList<T> l) {
	if (!isEmpty(l)) {
		Node<T>* p = l.head;
		while (p != NULL) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
	else
		cout << "Danh sach rong!\n";
}


//Xoa phan tu dau, cuoi danh sach
template <typename T>
void delFirst(LinkedList<T>& l) {
	if (!isEmpty(l)) {
		Node<T>* p = l.head;

		if (l.head == l.tail)
			l.tail = NULL;

		l.head = p->next;

		delete p;
	}
	else
		cout << "Danh sach rong!\n";
}

template <typename T>
void delLast(LinkedList<T>& l) {
	if (!isEmpty(l)) {
		Node<T>* pLast = l.tail;
		Node<T>* pPrev = l.head;

		if (l.head == l.tail) {
			l.head = l.tail = NULL;
			delete pLast;
			return;
		}

		while (pPrev->next != l.tail) {
			pPrev = pPrev->next;
		}

		pPrev->next = NULL;
		l.tail = pPrev;

		delete pLast;
	}
	else {
		cout << "Danh sach rong!\n";
	}
}


template <typename T>
void sort(LinkedList<T>& l, int comparator(T, T)) {
	for (Node<T>* i = l.head; i->next != NULL; i = i->next) {
		for (Node<T>* j = i->next; j != NULL; j = j->next) {
			if (comparator(j->data, i->data) < 0)
				swap(j->data, i->data);
		}
	}
}

//Huy danh sach
template <typename T>
void detroyList(LinkedList<T>& l) {
	while (!isEmpty(l)) {
		delFirst(l);
	}
}
