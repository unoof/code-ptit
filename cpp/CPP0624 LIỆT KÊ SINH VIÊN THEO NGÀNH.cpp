#include <bits/stdc++.h>
using namespace std;

string process_class(string s)
{
	string out;
	bool last_num = false;
	for (auto &&i : s)
	{
		if (isdigit(i))
		{
			last_num = true;
		}
		else if (last_num && !isdigit(i))
		{
			out += i;
		}
	}

	out.erase(0, 2);
	return out;
}

string process_subject(string s)
{
	string out;
	bool last_space = true;
	for (auto &&i : s)
	{
		if (isspace(i))
		{
			last_space = true;
		}
		if (last_space && !isspace(i))
		{
			out += toupper(i);
			last_space = false;
		}
	}

	out.erase(2, out.size() - 2);
	
	return out;
}

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
	string msv, name, class_name, email, subject;
};

void in(SinhVien ds[], int n)
{
	for (int i = 0; i < n; i++)
	{
		getline(cin, ds[i].msv);
		getline(cin, ds[i].name);
		getline(cin, ds[i].class_name);
		getline(cin, ds[i].email);
		ds[i].subject = process_class(ds[i].msv);
	}
	
}

void out(SinhVien ds[], int n, string s)
{
	cout << "DANH SACH SINH VIEN NGANH " << all_up(s) << ":" << endl;
	for (int i = 0; i < n; i++)
	{
		if (process_subject(s) == "CN" || process_subject(s) == "AT")
		{
			if (ds[i].class_name[0] == 'E')
			{
				continue;
			}
		}
		
		if (ds[i].subject == process_subject(s))
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