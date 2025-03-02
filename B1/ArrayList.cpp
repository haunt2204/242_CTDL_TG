//Danh sach sinh vien
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define MAX 100

struct SinhVien {
	long mssv;
	string hoTen;
	char ngaySinh[11];
	char queQuan[50];
	double diemTB;
};

struct List
{
	SinhVien a[MAX];
	int n;
};

//Khoi tao rong
void init(List& l) {
	l.n = 0;
}

//Nhap danh sach
void nhap1Sv(SinhVien& sv) {
	cout << "Nhap MSSV: ";
	cin >> sv.mssv;
	cout << "Nhap ho ten: ";
	cin.ignore(1);
	getline(cin, sv.hoTen, '\n');
	cout << "Nhap ngay sinh: ";
	cin >> sv.ngaySinh;
	cout << "Nhap que quan: ";
	cin.ignore(1);
	cin.getline(sv.queQuan, 50);
	cout << "Nhap diem TB: ";
	cin >> sv.diemTB;
}

void xuat1Sv(const SinhVien& sv) {
	cout << "===============================\n";
	cout << "ID: ";
	cout << sv.mssv << endl;
	cout << "Ho va ten: ";
	cout << sv.hoTen << endl;
	cout << "Ngay sinh: ";
	cout << sv.ngaySinh << endl;
	cout << "Que quan: ";
	cout << sv.queQuan << endl;
	cout << "Diem trung binh: ";
	cout << sv.diemTB << endl;
	cout << "===============================\n";
}

void inputArr(List& l) {
	//Nhap so phan tu
	do {
		cout << "Nhap so luong phan tu: ";
		cin >> l.n;
		if (l.n <= 0 || l.n > MAX)
			cout << "Nhap ngoai pham vi! Nhap lai!\n";
	} while (l.n <= 0 || l.n > MAX);
	//Nhap thong tin tung phan tu
	for (int i = 0; i < l.n; i++) {
		cout << "Nhap sinh vien thu " << i << ": ";
		nhap1Sv(l.a[i]);
	}
}

//Duyet danh sach
void outputArr(List& l) {
	if (l.n > 0) {
		for (int i = 0; i < l.n; i++) {
			xuat1Sv(l.a[i]);
		}
	}
	else {
		cout << "Danh sach rong!\n";
	}
}

//Thao tac them 1 sinh vien vao vi tri thu vt
int insert(List& l, const SinhVien& sv, const int vt=0) {
	if (l.n >= MAX || vt<0 || vt>l.n)
		return -1;
	//Danh sach con trong 
	//Chuyen doi du lieu
	for (int i = l.n; i > vt; i--) {
		l.a[i] = l.a[i - 1];
	}
	//Them phan tu moi vao mang
	l.a[vt] = sv;
	l.n++;
	return 1;
}

void inputListFromFile(List& l) {
	ifstream inFile("SinhVien.txt");
	if (inFile.is_open()) {
		//Thao tac

		while (!inFile.eof()) {
			SinhVien sv;
			inFile >> sv.mssv;
			inFile.ignore(1);
			getline(inFile, sv.hoTen, '#');
			inFile.getline(sv.ngaySinh, 11, '#');
			inFile.getline(sv.queQuan, 50, '#');
			inFile >> sv.diemTB;

			insert(l, sv, l.n);
		}

		//Dong tap tin
		inFile.close();
	}
}

//Sap xep danh sach: ID, Ho ten, Que quan, Diem TB
int cmpWithIdAsc(SinhVien sv1, SinhVien sv2) {
	return sv1.mssv - sv2.mssv;
}

int cmpWithIdDesc(SinhVien sv1, SinhVien sv2) {
	return -(sv1.mssv - sv2.mssv);
}

int cmpWithNameAsc(SinhVien sv1, SinhVien sv2) {
	return sv1.hoTen.compare(sv2.hoTen);
}

int cmpWithAddAsc(SinhVien sv1, SinhVien sv2) {
	return strcmp(sv1.queQuan, sv2.queQuan);
}

void sortList(List& l, int comparator(SinhVien, SinhVien)) {
	//Interchange Sort
	for (int i = 0; i < l.n - 1; i++) {
		for (int j = i + 1; j < l.n; j++) {
			if (comparator(l.a[j], l.a[i])<0)
				swap(l.a[j], l.a[i]);
		}
	}
}

//Han che lap code va de mo rong trong tuong lai

int main() {
	//Khai bao: array, n
	List dssv;
	init(dssv);

	//Thao tac nhap danh sach
	//inputArr(dssv);
	inputListFromFile(dssv);
	outputArr(dssv);

	/*SinhVien sv;
	sv.mssv = 999;

	insert(dssv, sv);
	outputArr(dssv);*/
	cout << "=======DS SAU KHI SAP XEP==========\n";
	sortList(dssv, cmpWithAddAsc);
	outputArr(dssv);

	return 0;
}