#define _CRT_SECURE_NO_WARNINGS
#include "Queue.h"
#include "Stack.h"
#include <iostream>
#include <string>
using namespace std;

int getPriority(string op) {
	if (op == "*" || op == "/")
		return 2;
	if (op == "+" || op == "-")
		return 1;
	return 0;
}

void infixToPostfix(char str[]) {
	Queue postfix;
	init(postfix);

	Stack s;
	init(s);

	char *p = strtok(str, " ");

	while (p != NULL) {
		if (isdigit(*p)) {
			enQueue(postfix, p);
		}
		else if (*p == '(') {
			push(s, p);
		}
		else if (*p == ')') {
			char* op = pop(s);
			while (*op != '(') {
				enQueue(postfix, op);
				op = pop(s);
			}
		}
		else {
			while (!isEmpty(s)&&getPriority(p)<=getPriority(peek(s))) {
				char* op = pop(s);
				enQueue(postfix, op);
			}

			push(s, p);
		}

		p = strtok(NULL, " ");
	}

	while (!isEmpty(s)) {
		enQueue(postfix, pop(s));
	}

	while (!isEmpty(postfix)) {
		cout << deQueue(postfix) << " ";
	}

	cout << endl;
}


int main() {
	char str[] = "2 + 1 + ( 4 - 2 ) / 2 + 3 - 3 * 2"; //2 1 + 4 2 - 2 / + 3 + 3 2 * -
	
	infixToPostfix(str);

	return 0;
}