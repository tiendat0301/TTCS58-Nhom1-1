#include <iostream>
#include <conio.h>
#include <iomanip>
#include <vector>
#include <fstream>

using namespace std;

int dem=0, n;
vector< int > cachTangQua;
vector< vector< int > > xuat;

void docFileInput(int &n, int &p, vector< int > &a){
	ifstream infile;
	infile.open("input4.txt");
	infile>>n; infile.ignore(256, ' ');
	infile>>p; infile.ignore(256, '\n');
	a.resize(n);
	for(int i=0; i<n-1; i++)
	{
		int temp;
		infile>>temp;
		a[i]=temp;
		infile.ignore(256, ' ');
	}
	infile>>a[n-1];
}

void quaylui(vector< int > a, int control, int p)
{
    if (control==n and p==0)
    {
    	//truong hop dung
        dem++;
        xuat.push_back(cachTangQua);
    }

    if (control<n and p>=0) //chi chay tu 0 toi n-1
	{
		//vet can tat ca cac truong hop
        cachTangQua[control] = 1;
        quaylui (a, control+1, p-a[control]);
        cachTangQua[control] = 0;
        quaylui (a, control+1, p);
    }
}

void output(){
	ofstream outfile;
	outfile.open("output4.txt", ios::out | ios::trunc);
	if (dem==0)
	{
		cout<<"Khong chon duoc.";
		outfile<<"Khong chon duoc.";
	}
    else 
	{
	    cout<<"So cach chon qua: "<<dem<<"\n";
	    outfile<<"So cach chon qua: "<<dem<<"\n";
	    for (int i=0; i<dem; i++)
		{
	        for (int j=0;j<n;j++)
	        {
	            cout<<setw(3)<<xuat[i][j];
	            outfile<<setw(3)<<xuat[i][j];
	        }
	        cout<<"\n";
	        outfile<<endl;
	    }
    }
    outfile.close();
}

int main()
{
    int P;
    vector< int > giaTriCacMonQua;
    docFileInput(n, P, giaTriCacMonQua);
    cachTangQua.resize(n);
    quaylui(giaTriCacMonQua, 0, P);
    output();
}
