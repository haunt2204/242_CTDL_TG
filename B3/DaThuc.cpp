#include "AbstractLinkedList.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Term
{
	int coef;//He so
	int exp;//Bac
};

ostream& operator<< (ostream& out, const Term t) {
	out << t.coef << "x^" << t.exp;

	return out;
}

double f(LinkedList<Term> l, int x) {
	if (isEmpty(l)) {
		return 0.0;
	}
	double res = 0.0;

	Node<Term>* p = l.head;

	while (p != NULL) {
		res += p->data.coef * pow(x, p->data.exp);
		p = p->next;
	}

	return res;
}

//Thao tac duyet danh sach
void printList(const LinkedList<Term> l) {
	if (!isEmpty(l)) {
		Node<Term>* p = l.head;
		cout << "f(x) = ";
		while (p != NULL) {
			cout << p->data;
			if (p->next != NULL)
				cout << " + ";
			p = p->next;
		}
		cout << endl;
	}
	else
		cout << "Danh sach rong!\n";
}

int main() {
	LinkedList<Term> l;

	init(l);

	Term t1;
	t1.coef = 4;
	t1.exp = 3;

	Term t2;
	t2.coef = 2;
	t2.exp = 2;

	insertFirst(l, t1);
	insertLast(l, t2);

	printList(l);

	cout << "f(x) = " << f(l, 1) << endl;

	detroyList(l);
	return 0;
}