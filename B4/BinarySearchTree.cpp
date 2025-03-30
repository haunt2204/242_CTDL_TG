#include <iostream>
using namespace std;

//Dinh nghia
struct Node
{
	//Vung thong tin
	int data;

	//Vung lien ket
	Node* left, * right;
};

//Khoi tao rong
void treeEmpty(Node*& root) {
	root = NULL;
}

//Them 1 node vao trong cay
Node* createNode(int x) {
	Node* p = new Node;
	p->data = x;
	p->left = NULL;
	p->right = NULL;

	return p;
}

void insertNode(Node*& root, int x) {
	Node* p = createNode(x);
	if (root == NULL) {
		root = p;
		return;
	}

	Node* q = root;
	Node* parent = NULL;

	while(q!=NULL&&q->data!=x){
		parent = q;
		if (x > q->data)
			q = q->right;
		else
			q = q->left;
	}

	if (q != NULL)
		return;

	if (x > parent->data)
		parent->right = p;
	else
		parent->left = p;
}

//Duyet cay theo thu tu LNR
void duyetLNR(Node* root) {
	if (root == NULL)
		return;
	duyetLNR(root->left);
	cout << root->data << " ";
	duyetLNR(root->right);
}

//Thao tac tim kiem tren cay
Node* search(Node* root, int key) {
	Node* p = root;

	while (p != NULL && p->data != key) {
		if (key > p->data)
			p = p->right;
		else
			p = p->left;
	}

	return p;
}
//Thao tac xoa mot node tren cay
void delNode(Node*& root, int key) {
	Node* cur = root;
	Node* parent = NULL;

	while (cur != NULL && cur->data != key) {
		parent = cur;
		if (key > cur->data)
			cur = cur->right;
		else
			cur = cur->left;
	}

	if (cur == NULL)
		return;//Khong tim thay key

	//Node cur la node bac: 0 va 1
	if (cur->left == NULL || cur->right == NULL) {
		Node* temp;
		if (cur->left != NULL)
			temp = cur->left;
		else
			temp = cur->right;

		if (cur == root) {
			root = temp;
		}
		else {
			if (key > parent->data)
				parent->right = temp;
			else
				parent->left = temp;
		}
		delete cur;
		return;
	}

	//Node cur la node bac 2
	////Tim node the mang: node phai nhat o nhanh con ben trai cur
	Node* temp = cur->left;
	parent = NULL;
	while (temp->right != NULL) {
		parent = temp;
		temp = temp->right;
	}

	//Chep gia tri cua node the mang len cho cur
	cur->data = temp->data;

	if (parent != NULL)
		parent->right = temp->left;
	else
		cur->left = temp->left;

	//Xoa node the mang
	delete temp;
	return;
}

//Dinh nghia stack
#define MAX 100

//Dinh nghia
struct Stack {
	Node* a[MAX];
	int top;
};

//Khoi tao rong
void init(Stack& s) {
	s.top = -1;
}

//Them vao stack
void push(Stack& s, Node* x) {
	s.a[++s.top] = x;
}

//Lay phan tu tu stack ra
Node* pop(Stack& s) {
	return s.a[s.top--];
}

//Kiem tra stack rong
bool isEmpty(Stack s) {
	return s.top == -1;
}


//Duyet cay khong de quy
void duyetLNRNoRec(Node* root) {
	Node* p = root;
	Stack s;
	init(s);

	while (p!=NULL||!isEmpty(s)) {
		//Xu ly 
		while (p != NULL) {
			push(s, p);
			p = p->left;
		}

		p = pop(s);
		cout << p->data << "\t";
		p = p->right;
	}
}
int main() {
	Node* root;
	treeEmpty(root);

	insertNode(root, 40);
	insertNode(root, 60);
	insertNode(root, 20);
	insertNode(root, 10);
	insertNode(root, 25);
	insertNode(root, 15);

	duyetLNR(root);
	cout << endl;

	/*Node* p = search(root, 60);
	if (p != NULL)
		cout << "Ket qua tim kiem: " << p->data << endl;
	else
		cout << "Khong tim thay!\n";

	cout << "================XOA NODE=============\n";
	delNode(root, 40);
	duyetLNR(root);*/
	//cout << endl;
	duyetLNRNoRec(root);
	cout << endl;
	return 0;
}