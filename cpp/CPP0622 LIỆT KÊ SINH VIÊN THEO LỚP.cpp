#include <bits/stdc++.h>
using namespace std;

string all_up(string s)
{
	for (auto &&i : s)
	{
		i = toupper(i);
	}
	return s;
}

struct SinhVien
{
	string msv, name, class_name, email;
};

void in(SinhVien ds[], int n)
{
	for (int i = 0; i < n; i++)
	{
		getline(cin, ds[i].msv);
		getline(cin, ds[i].name);
		getline(cin, ds[i].class_name);
		getline(cin, ds[i].email);
	}
	
}

void out(SinhVien ds[], int n, string s)
{
	cout << "DANH SACH SINH VIEN LOP " << all_up(s) << ":" << endl;
	for (int i = 0; i < n; i++)
	{
		if (ds[i].class_name == s)
		{
			cout << ds[i].msv << " " << ds[i].name << " " << ds[i].class_name << " " << ds[i].email << endl;
		}
	}
}

int main()
{
	SinhVien ds[1001];

	int n;
	cin >> n;
	cin.ignore();

	in(ds, n);

	int count;
	cin >> count;
	cin.ignore();

	for (int i = 0; i < count; i++)
	{
		string temp;
		getline(cin, temp);
		out(ds, n, temp);
	}
	


	
	
	
	return 0;
}