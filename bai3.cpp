#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int n;
struct NhanVien{
	int	MaNV, Luong;
	string HoLot, Ten;
};
NhanVien nv[50];
void Nhap(NhanVien *nv, int &n){
	do{
		cout << "Nhap vao so luong nhan vien: " << endl;
		cin >> n;
	}while(n<1 || n>50);
	fstream f;
	f.open("E:/input3.txt", ios::out);
	f << n << endl;
	for (int i = 0; i < n; i++){
		fflush(stdin);
		cout << "Nhap ma nhan vien thu " << i+1 << ": ";
		cin >> nv[i].MaNV;
		f << nv[i].MaNV << endl;
		fflush(stdin);
		cout << "Nhap ho lot nhan vien " << i+1 << ": ";
		getline(cin, nv[i].HoLot);
		f << nv[i].HoLot << endl;
		fflush(stdin);
		cout << "Nhap ten nhan vien " << i+1 << ": ";
		getline(cin, nv[i].Ten);
		f << nv[i].Ten << endl;
		fflush(stdin);
		cout << "Nhap luong nhan vien " << i+1 << ": ";
		cin >> nv[i].Luong;
		f << nv[i].Luong << endl;
	}
}
void Xuat(NhanVien &nv){
		cout << "Ma nhan vien: "<< nv.MaNV << endl;
		cout << "Ho lot nhan vien: "<< nv.HoLot << endl;
		cout << "Ten nhan vien: "<< nv.Ten << endl;
		cout << "Luong nhan vien: "<< nv.Luong << endl;
}
void Docfile(){
	fstream f;
	f.open("E:/input3.txt", ios::in);
	f >> n;
	for(int i = 0; i < n; i++ ){
		string tam;
		f >> nv[i].MaNV;
		getline(f, tam);
		getline(f, nv[i].HoLot);
		getline(f, nv[i].Ten);
		f >> nv[i].Luong;
	}
	for(int i = 0; i < n; i++ ){
		cout << "Thong tin nhan vien thu " << i+1 << ": "<<endl;
		Xuat(nv[i]);
	}
}
string Search(){
	cout << "Nhap vao ma Nhan vien: ";
	int ma;
	cin >> ma;
	for(int i = 0; i < n; i++){
		if(ma == nv[i].MaNV)
			Xuat(nv[i]);
		else
			cout << "Ma nhan vien khong ton tai!" << endl;
	}
}
int MaxLuong(int &n, NhanVien NV[]){
	int max = nv[0].Luong;
	for(int i = 0; i < n; i++){
		if(nv[i].Luong > max)
			max = nv[i].Luong;
		}
	return max;
}
string NVMaxLuong(int &n, NhanVien NV[]){
	for(int i = 0; i< n; i++){
		if (NV[i].Luong == MaxLuong(n, NV)){
			Xuat(NV[i]);
			cout << endl;
		}
	}
}
int MinLuong(int &n, NhanVien NV[]){
	int min = nv[0].Luong;
	for(int i = 0; i < n; i++){
		if(nv[i].Luong < min)
			min = nv[i].Luong;
		}
	return min;
}
string NVMinLuong(int &n, NhanVien NV[]){
	for(int i = 0; i< n; i++){
		if(NV[i].Luong == MinLuong(n, NV)){	
			Xuat(NV[i]);
			cout << endl;
		}
	}
}
string SapXep(NhanVien nv[], int &n){
	for(int i = 0; i < n-1; i++){
		for(int j = i+1; j < n; j++){
			if(nv[i].Ten.compare(nv[j].Ten) > 0 ){
				swap(nv[i], nv[j]);
			}
			else if(nv[i].Ten.compare(nv[j].Ten) == 0){
				if(nv[i].HoLot.compare(nv[j].HoLot) > 0){
					swap(nv[i], nv[j]);
				}
			}
		}
	}
	for(int i = 0; i < n; i++){
		Xuat(nv[i]);	
	}
}
void GhiKQ(){
	fstream f;
	f.open("E:/output3.txt", ios::out);
	f << "Tim kiem thong tin nhan vien:" << Search() << endl;
	f << "Nhan vien co luong cao nhat: " << NVMaxLuong(n, nv) << endl;
	f << "Nhan vien co luong thap nhat: " << NVMinLuong(n, nv) << endl;
	f << "Sap xep nhan vien theo ten: "  << SapXep(nv, n) << endl;
	f.close();
}
void MENU(){
	cout << "            --------------MENU--------------" << endl
	<< " *     1-Nhap thong tin nhan vien vao tap tin input3.txt      * " << endl
	<< " *     2-Doc file thong tin nhan vien                         * " << endl
	<< " *     3-Tim kiem thong tin nhan vien                         * " << endl
	<< " *     4-Nhan vien co luong cao nhat va thap nhat             * " << endl
	<< " *     5-Sap xep nhan vien theo ten                           * " << endl
	<< " *     6-Ghi ket qua thuc hien vao tap tin output3            * " << endl
	<< " *     7-Thoat                  				              * " << endl;
	cout << "     -------------Xin moi ban chon!-----------" << endl;
	cin >> n;
	switch (n){
		case 1:
			system("cls");
			cout << "* 1-Nhap thong tin nhan vien! " << endl;
			Nhap(nv, n);
			MENU();
		case 2:
			system("cls");
			cout << "Doc file thong tin nhan vien! " << endl;
			Docfile();
			MENU();
		case 3:
			system("cls");
			cout << "Tim kiem thong tin nhan vien: " << endl;
			Search();
			MENU();
		case 4:
			system("cls");
			cout << "Nhan vien co luong cao nhat: " << endl;
			NVMaxLuong(n, nv);
			cout << "Nhan vien co luong thap nhat: " << endl;
			NVMinLuong(n, nv);
		case 5:
			system("cls");
			cout << "Sap xep nhan vien theo ten: " << endl;
			SapXep(nv, n);
			MENU();
		case 6:
			GhiKQ();
			cout << "---------Da ghi ket qua vao file---------" << endl;
			MENU();
		case 7:
			system("cls");
			cout << "------------Goodbye see you again!---------------";
			exit(1);
		default:
			cout << "Sai roi ban oi! Nhap lai nao!" << endl << "--------Ban nhap lai nao--------" << endl;
			MENU();
			cout << endl;
	}
}
int main(){
	MENU();
}
