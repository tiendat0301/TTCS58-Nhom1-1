#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int n;
string s;
void NhapChuoi(){
	fstream f;  //khai bao bien f
	f.open("E:/input1.txt", ios::out); //mo file input.txt 
	cout<<"Nhap vao chuoi: ";
	fflush(stdin); //xoa bo dem ban phim
	getline(cin, s); // nhap du lieu vao chuoi s
	f << s; //truyen chuoi s vao file
	f.close(); //dong file
}
string XoaTrang(){
	// Xoa khoang trang dau
	while (s[0] == ' '){
		s.erase(s.begin() + 0);
	}
	// Xoa khoang trang giua
	while (s[s.length() - 1] == ' '){
		s.erase(s.begin() + s.length() - 1);
	}
	// Xoa khoang trang cuoi
	for (int i = 0; i < s.length(); i++){
		if (s[i] == ' ' && s[i + 1] == ' '){
			s.erase(s.begin() + i);
			i--;
		}
	}
	return s;
}
string Proper(){
	if (s[0] != ' '){
		if (s[0] >= 97 && s[0] <= 122){
			s[0] -= 32;
		}	
	}
	for (int i = 0; i < s.length() - 1; i++){
		if (s[i] == ' ' && s[i + 1] != ' '){
			if (s[i + 1] >= 97 && s[i + 1] <= 122){
				s[i + 1] -= 32; 
			}
		}
	}
	return s;
}
int ThongKe(){	
	int dem = 0; 
	for (int i = 0; i<s.length(); i++){
		if(s[i] != ' ')
		dem++;
	}
	return dem;
}
void GhiKQ(){
	fstream f;
	f.open("E:/output1.txt", ios::app);
	f << "Chuoi sau khi xoa khoang trang:" << XoaTrang() << endl;
	f << "Chuoi sau khi chuan hoa: " << Proper() << endl;
	f << "So luong ki tu: " << ThongKe() << endl;
	f.close();
}
void MENU(){
	cout << "             -------------MENU-------------" << endl 
	<< " *    1-Nhap chuoi vao tap tin input1.txt          *" << endl
	<< " *    2-Xoa cac khoang trang thua                  *" << endl
	<< " *    3-Chuan hoa chuoi dang proper                *" << endl
	<< " *    4-Thong ke so luong cac ky tu trong chuoi    *" << endl
	<< " *    5-Ghi ket qua thuc hien vao tap tin          *" << endl
	<< " *    6-Thoat                                      *" << endl
	<< "      -------------Xin moi ban chon-----------"<< endl;
	cin >> n;
	switch (n)
	{
		case 1:
			system("cls");
			NhapChuoi();
			MENU();
			break;
		case 2:
			system("cls");
			cout <<"Chuoi sau khi xoa khoang trang: " << XoaTrang() << endl;
			MENU();
			break;
		case 3:
			system("cls");
			cout << "Chuoi sau khi chuan hoa: " << Proper() << endl;
			MENU();
			break;
		case 4:
			system("cls");
			cout << "So luong ki tu: " << ThongKe() << endl;
			MENU();
			break;
		case 5:
			system("cls");
			GhiKQ();
			cout << "---Da ghi ket qua vao file---" << endl;
			MENU();
			break;
		case 6:
			system("cls");
			cout << "------------Goodbye see you again!---------------";
			exit(1);
		default:
			system("cls");
			cout << "Sai roi ban oi! Nhap lai nao!" << endl << "--------Ban nhap lai nao--------" << endl;
			MENU();
			cout << endl;
	}
}
int main(){
	MENU();
}
