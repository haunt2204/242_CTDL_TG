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
	out << t.coef << "x^" << t.exp << "\t";

	return out;
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


	detroyList(l);
	return 0;
}