#include <iostream>
#include <fstream>
using namespace std;


//Selection Sort
void selectionSort(long a[], int n) {
	int pos;
	for (int i = 0; i < n - 1; i++) {
		pos = i;
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[pos])
				pos = j;
		swap(a[pos], a[i]);
	}
}

//Insertion Sort
void insertionSort(long a[], int n) {
	int x, j;
	for (int i = 1; i < n; i++) {
		x = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > x) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}

//Interchange Sort (SV cai dat)

//Bubble Sort (SV cai dat)

void quickSort(long a[], int left, int right) {
	int pivot = a[(left + right) / 2];

	int l = left, r = right;

	while (l <= r) {
		while (a[l] < pivot)
			l++;
		while (a[r] > pivot)
			r--;

		if (l <= r) {
			swap(a[l], a[r]);
			l++; 
			r--;
		}
	}

	if (left < r) {
		quickSort(a, left, r);
	}
		
	if (l < right) {
		quickSort(a, l, right);
	}
}


//Heap Sort O(nlogn)
void heapify(long a[], int n, int i) {
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	int maxPos = i;

	if (l<n && a[l]>a[maxPos])
		maxPos = l;
	if (r<n && a[r]>a[maxPos])
		maxPos = r;

	if (maxPos == i)
		return;

	swap(a[i], a[maxPos]);
	heapify(a, n, maxPos);
}

void heapSort(long a[], int n) {
	int i = n / 2 - 1;

	while (i >= 0) {
		heapify(a, n, i);
		i--;
	}

	for (int right = n - 1; right > 0; right--) {
		swap(a[0], a[right]);
		heapify(a, right, 0);
	}
}


void printList(long a[], int n) {
	ofstream outFile("DaySo_Ordered.txt");
	if (outFile.is_open()) {
		for (int i = 0; i < n; i++) {
			outFile << a[i] << "\n";
		}
	}
	cout << "Da xuat ket qua xuong file!\n";
}

int main() {
	/*long a[] = { 40,60,10,50,90,20,10,70 };
	long n = sizeof(a) / sizeof(a[0]);*/

	long n = 1000000;
	long* a = new long[n];

	ifstream inFile("DaySo_Ordered.txt");

	if (inFile.is_open()) {

		for (int i = 0; i < n; i++) {
			inFile >> a[i];
		}

		inFile.close();
	}

	heapSort(a,n);
	//insertionSort(a, n);

	printList(a, n);

	delete[]a;
	return 0;
}