#include <iostream>
using namespace std;

#define M 7

//Dinh nghia
struct IntValue {
	int value;
	int freq;
};

struct Node
{
	IntValue *data;
	int next;
};

struct HashTable
{
	Node h[M];
	int r;
};

//Ham bam
int hashFunc(int value) {
	return value % M;
}

//Khoi tao rong
void init(HashTable& ht) {
	for (int i = 0; i < M; i++) {
		ht.h[i].data = NULL;
		ht.h[i].next = -1;
	}
	ht.r = M - 1;
}

//Them phan tu vao bang bam
void insert(HashTable& ht, IntValue *data) {
	int k = hashFunc(data->value);
	if (ht.h[k].data == NULL) {
		ht.h[k].data = data;
	}
	else {
		//Xay ra dung do
		if (ht.h[k].data->value == data->value) {
			ht.h[k].data->freq += 1;
			return;
		}
		
		while (ht.h[k].next != -1) {
			k = ht.h[k].next;
			if (ht.h[k].data->value==data->value) {
				ht.h[k].data->freq += 1;
				return;
			}
		}
		ht.h[ht.r].data = data;
		ht.h[k].next = ht.r;
	}

	while (ht.r >= 0 && ht.h[ht.r].data != NULL) {
		ht.r--;
	}
}
//In ra man hinh bang bam hien tai
void printHashTable(HashTable ht) {
	for (int i = 0; i < M; i++) {
		if (ht.h[i].data != NULL) {
			cout << "BUCKET " << i << ": " << ht.h[i].data->value << "-->" << ht.h[i].next << " so lan xuat hien: " << ht.h[i].data->freq << endl;
		}
	}
}
//Ham tim kiem 1 phan tu tren bang bam
int search(HashTable ht, int key) {
	int k = hashFunc(key);

	while (k!=-1 && ht.h[k].data->value != key) {
		k = ht.h[k].next;
	}

	return k;
}

int main() {
	int a[] = { 15, 7, 9, 7, 13, 15, 20, 11, 9, 15, 20 };
	int n = sizeof(a) / sizeof(a[0]);

	HashTable ht;
	init(ht);

	for (int i = 0; i < n; i++) {
		IntValue* data = new IntValue;
		data->value = a[i];
		data->freq = 1;
		insert(ht, data);
	}

	/*insert(ht, 7);
	insert(ht, 14);
	insert(ht, 9);
	insert(ht, 5);*/

	printHashTable(ht);

	/*int res = search(ht, 28);
	if (res != -1) {
		cout << "Ket qua: tai BUCKET thu " << res << endl;
	}
	else
		cout << "KHONG TIM THAY!\n";*/
	//Giai phong vung nho: SV tu cai dat them
	return 0;
}
