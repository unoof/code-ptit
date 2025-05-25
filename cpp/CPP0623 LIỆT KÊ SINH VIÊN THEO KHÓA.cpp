#include <bits/stdc++.h>
using namespace std;

int get_nam(string n)
{
	int temp;
	temp = (n[1] - '0')*10 + n[2] - '0';
	if (temp < 26)
	{
		return temp + 2000;
	}
	
	return temp + 1900;
}

struct SinhVien
{
	string msv, name, lop, email;
	int nam;
};

void nhap(SinhVien ds[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cin >> ds[i].msv;
		cin.ignore();
		getline(cin, ds[i].name);
		getline(cin, ds[i].lop);
		getline(cin, ds[i].email);
		ds[i].nam = get_nam(ds[i].lop);
	}
}

void in(SinhVien ds[], int n, int num, vector<int> A)
{
	for (int i = 0; i < num; i++)
	{
		cout << "DANH SACH SINH VIEN KHOA " << A[i] << ":" << endl;
		for (int j = 0; j < n; j++)
		{
			if (ds[j].nam == A[i])
			{
				cout << ds[j].msv << " " << ds[j].name << " " << ds[j].lop << " " << ds[j].email << endl;
			}
			
		}
		
	}
}

int main(){
	struct SinhVien ds[1001];
	int N;
	cin >> N;
	nhap(ds, N);
	
	int num;
	cin >> num;
	vector<int> A(num);
	for (int i = 0; i < num; i++)
	{
		cin >> A[i];
	}
	
	in(ds, N, num, A);
	return 0;
}