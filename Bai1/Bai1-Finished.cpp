#include<iostream>
#include<conio.h>
#include<string.h>
#include<fstream>
#include<windows.h>
using namespace std;

bool checkEmpty(){
	ifstream infile;
	infile.open("input1.txt");
	string s;
	getline(infile, s);
	if (s[0]=='\0') return true;
	return false;
}

void nhapVaoFile(){
	ofstream outfile;
	outfile.open("input1.txt", ios::out | ios::app);
	string s;
	cout<<"Nhap chuoi: "; fflush(stdin); getline(cin, s);
	while (s.size()>255)
	{
		cout<<"Chuoi nhap vao chi duoc co do dai toi da la 255 ky tu.\n";
		cout<<"Nhap lai chuoi: "; cin>>s;
	}
	while (s[s.size()-1]=='\n')
		s.erase(s.begin() + (s.size()-1));
	if (checkEmpty()) outfile<<s;
	else outfile<<"\n"<<s;
	outfile.close();
}

void xuat(string s){
	ofstream outfile;
	outfile.open("output1.txt", ios::app);
	cout<<s<<"\n";
	outfile<<s<<"\n";
	outfile.close();
}

void boKhoangTrangGiua(string &s){
	for(int i=0; i<s.size()-1; i++)
		if (s[i]==32 and s[i+1]==32)
		{
			s.erase(s.begin() + i);
			i-=1;
		}
}

void boKhoangTrangDau(string &s){
	if (s[0]==32) s.erase(s.begin());
}

void boKhoangTrangCuoi(string &s){
	if (s[s.size()-1]==32) s.erase(s.begin() + (s.size()-1));
}

string boKhoangTrang(string s){
	boKhoangTrangGiua(s);
	boKhoangTrangDau(s);
	boKhoangTrangCuoi(s);
	return s;
}

string chuanHoaProper(string s){
	if (s[0]>=97 and s[0]<=122) s[0]-=32;
	for(int i=0; i<s.size()-1; i++)
	{
		if (s[i]==32 and s[i+1]>=97 and s[i+1]<=122) s[i+1]=s[i+1]-32;
	}
	return s;
}

int demChuCai(string s){
	int cnt=0;
	for(int i=0; i<s.size(); i++)
	{
		if ((s[i]>=65 and s[i]<=90) or (s[i]>=97 and s[i]<=122)) cnt+=1;
	}
	return cnt;
}

void xoaDuLieuFileInput(){
	ofstream outfile;
	outfile.open("input1.txt", ios::trunc);
	outfile.close();
}

void xoaDuLieuFileOutput(){
	ofstream outfile;
	outfile.open("output1.txt", ios::trunc);
	outfile.close();
}

main(){
	while (true)
	{
		system("cls");
		int ctrl;
		cout<<"0. Ket thuc chuong trinh\n";
		cout<<"1. Nhap them du lieu vao file input1.txt\n";
		cout<<"2. Xu ly du lieu trong file input1.txt va xuat ra file output1.txt\n";
		cout<<"3. Xoa du lieu trong file input1.txt\n";
		cout<<"4. Xoa du lieu trong file output1.txt\n";
		cout<<"Hay nhap dieu muon lam: "; cin>>ctrl;
		while (ctrl<0 or ctrl>4)
		{
			cout<<"Chi duoc nhap vao so tu 0 den 4\n";
			cout<<"Hay nhap lai: "; cin>>ctrl;
		}
		system("cls");
		if (ctrl==0)
		{
			cout<<"Chuong trinh da thoat.";
			break;
		}
		else if (ctrl==1) nhapVaoFile();
		else if (ctrl==2)
		{
			ifstream infile;
			infile.open("input1.txt");
			while (!infile.eof())
			{
				string s;
				getline(infile, s);
				s = boKhoangTrang(s);
				xuat(s);
				s = chuanHoaProper(s);
				xuat(s);
				cout<<"so chu cai trong chuoi la "<<demChuCai(s)<<"\n";
				ofstream outfile;
				outfile.open("output1.txt", ios::app);
				outfile<<"so chu cai trong chuoi la "<<demChuCai(s)<<"\n";
				outfile.close();
			}
		}
		else if (ctrl==3)
		{
			xoaDuLieuFileInput();
			cout<<"Du lieu trong file input1.txt da duoc xoa";
		}
		else if (ctrl==4)
		{
			xoaDuLieuFileOutput();
			cout<<"Du lieu trong file output1.txt da duoc xoa";
		}
		getch();
	}
}
