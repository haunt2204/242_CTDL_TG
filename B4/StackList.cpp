#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#define MAX 100

//Dinh nghia
struct Stack {
	int a[MAX];
	int top;
};

//Khoi tao rong
void init(Stack& s) {
	s.top = -1;
}

//Them vao stack
void push(Stack &s, int x) {
	s.a[++s.top] = x;
}

//Lay phan tu tu stack ra
int pop(Stack &s) {
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

void calExp(char str[]) {
	Stack s;
	init(s);

	char *p = strtok(str," ");

	while (p!=NULL) {
		if (isdigit(*p)) {
			push(s, atoi(p));
		}
		else {
			int b = pop(s);
			int a = pop(s);

			switch (*p)
			{
			case '+':
				push(s, a + b);
				break;
			case '*':
				push(s, a * b);
				break;
			case '-':
				push(s, a - b);
				break;
			case '/':
				if (b != 0) {
					push(s, a / b);
				}
				else {
					cout << "Loi chia cho so 0!\n";
					return;
				}
				break;
			default:
				cout << "Phep tinh khong hop le!\n";
				return;
			}
		}
		p = strtok(NULL," ");
	}

	cout << "Ket qua phep tinh: " << pop(s) <<endl;
}

void convertDecToBin(int n) {
	Stack s;
	init(s);

	while (n != 0) {
		push(s, n % 2);
		n /= 2;
	}

	while (!isEmpty(s)) {
		cout << pop(s);
	}
	cout << endl;
}

int main() {
	/*char str[] = "2 4 6 + * 5 / 1 -";
	
	calExp(str);*/

	convertDecToBin(4);

	return 1;
}