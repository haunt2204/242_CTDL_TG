#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define M 17

//Ham bam
int hashFunc(string str) {
	int sum = 0;
	for (int i = 0; i < str.length(); i++) {
		sum += tolower(str[i])*(i+1);
	}
	return sum % M;
}

//Dinh nghia bang bam
struct Word {
	string word;
	string type;
	string mean;
};

struct Node {
	Word value;
	Node* next;
};

//Khoi tao rong
void init(Node* heads[]) {
	for (int i = 0; i < M; i++) {
		heads[i] = NULL;
	}
}

//Them phan tu vao bang bam
Node* createNode(Word x) {
	Node* p = new Node;
	p->value = x;
	p->next = NULL;

	return p;
}

void insert(Node* heads[], Word value) {
	int k = hashFunc(value.word);

	Node* newNode = createNode(value);

	if (heads[k] == NULL) {
		heads[k] = newNode;
		return;
	}

	//Xu ly dung do
	Node* p = heads[k];
	while (p->next != NULL) {
		//Tu vung da co trong tu dien roi => khong them
		p = p->next;
	}

	p->next = newNode;

	/*Node* p = heads[k], *q = NULL;

	while (p != NULL && p->value < value) {
		q = p;
		p = p->next;
	}

	if (q == NULL) {
		newNode->next = heads[k];
		heads[k] = newNode;
		return;
	}

	newNode->next = p;
	q->next = newNode;*/
}

void printHashTable(Node* heads[]) {
	for (int i = 0; i < M; i++) {
		if (heads[i] != NULL) {
			cout << "BUCKET " << i << ": ";
			Node* p = heads[i];
			while (p != NULL) {
				cout << p->value.word << " " << p->value.type << " " << p->value.mean << "--->";
				p = p->next;
			}
			cout << endl;
		}
	}
}

void readData(Node*heads[]) {
	ifstream inFile("dictionary.txt");
	if (inFile.is_open()) {
		
		while (!inFile.eof()) {
			Word w;

			getline(inFile, w.word, '#');
			getline(inFile, w.type, '#');
			getline(inFile, w.mean);

			insert(heads, w);
		}

		inFile.close();
	}
}

Node* search(Node* heads[], string word) {
	int k = hashFunc(word);

	Node *p = heads[k];
	while (p != NULL && p->value.word != word) {
		p = p->next;
	}

	return p;
}

int main() {
	Node* heads[M];
	init(heads);

	readData(heads);

	/*insert(heads, 7);
	insert(heads, 22);
	insert(heads, 15);
	insert(heads, 8);
	insert(heads, 11);
	insert(heads, 12);
	insert(heads, 13);*/

	printHashTable(heads);

	string key;

	cout << "Nhap tu can tim: ";
	cin >> key;

	Node *res = search(heads, key);

	if (res!=NULL) {
		cout << res->value.type << "-" << res->value.mean << endl;
	}

	return 0;
}