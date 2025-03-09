#include "AbstractLinkedList.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct SinhVien {
	long mssv;
	string hoTen;
	char ngaySinh[11];
	char queQuan[50];
	double diemTB;
};

ostream& operator<< (ostream& out, const SinhVien sv) {
	out << "===============================\n";
	out << "ID: ";
	out << sv.mssv << endl;
	out << "Ho va ten: ";
	out << sv.hoTen << endl;
	out << "Ngay sinh: ";
	out << sv.ngaySinh << endl;
	out << "Que quan: ";
	out << sv.queQuan << endl;
	out << "Diem trung binh: ";
	out << sv.diemTB << endl;
	out << "===============================\n";

	return out;
}


//Sap xep danh sach sinh vien: mac dinh sap tang dan theo ID,...
template <typename T>
void readFile(LinkedList<T>& l) {
	ifstream inFile("SinhVien.txt");

	if (inFile.is_open()) {

		while (!inFile.eof()) {
			SinhVien sv;
			inFile >> sv.mssv;
			inFile.ignore(1);
			getline(inFile, sv.hoTen, '#');
			inFile.getline(sv.ngaySinh, 11, '#');
			inFile.getline(sv.queQuan, 50, '#');
			inFile >> sv.diemTB;

			insertFirst(l, sv);
		}

		//Dong
		inFile.close();
	}
}

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


int main() {
	//Định nghĩa
	//Khai báo
	LinkedList<SinhVien> l;

	//Khởi tạo rỗng
	init(l);

	//Thao tác trên danh sách
	readFile(l);
	printList(l);

	//Thao tac sap xep
	cout << "==============SAP XEP=========\n";
	sort(l, cmpWithNameAsc);
	printList(l);

	//Giai phong danh sach
	detroyList(l);
	return 0;
}