#include<iostream>
#include<conio.h>
#include<string.h>
#include<fstream>
using namespace std;

void nhap(string &s){
	ofstream outfile;
	outfile.open("input1.txt", ios::out | ios::trunc);	
	cout<<"Nhap chuoi: "; getline(cin, s);
	while (s.size()>255)
	{
		cout<<"Chuoi nhap vao chi duoc co do dai toi da la 255 ky tu.\n";
		cout<<"Nhap lai chuoi: "; cin>>s;
	}
	outfile<<s<<"\n";
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

main(){
	string s;
	ofstream outfile;
	outfile.open("output1.txt", ios::trunc);
	outfile.close();
	nhap(s);
	xuat(s);
	s = boKhoangTrang(s);
	xuat(s);
	s = chuanHoaProper(s);
	xuat(s);
	cout<<"so chu cai trong chuoi la "<<demChuCai(s)<<"\n";
	outfile.open("output1.txt", ios::app);
	outfile<<"so chu cai trong chuoi la "<<demChuCai(s)<<"\n";
	outfile.close();
	getch();
}
