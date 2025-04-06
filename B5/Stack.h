#include <iostream>
using namespace std;

#define MAX 100

//Dinh nghia
struct Stack {
	char* a[MAX];
	int top;
};

//Khoi tao rong
void init(Stack& s) {
	s.top = -1;
}

//Them vao stack
void push(Stack& s, char* x) {
	s.a[++s.top] = x;
}

//Lay phan tu tu stack ra
char* pop(Stack& s) {
	if (s.top == -1)
		return NULL;
	return s.a[s.top--];
}

//Xuat ngan xep ra man hinh
void print(Stack s) {
	for (int i = 0; i <= s.top; i++) {
		cout << s.a[i] << " ";
	}
	cout << endl;
}

//Kiem tra stack rong
bool isEmpty(Stack s) {
	return s.top == -1;
}

//Lay phan tu dau Stack
char* peek(Stack s) {
	if (s.top == -1)
		return NULL;
	return s.a[s.top];
}