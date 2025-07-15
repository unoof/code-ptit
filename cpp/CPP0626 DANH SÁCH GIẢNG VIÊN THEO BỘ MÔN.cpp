#include <bits/stdc++.h>
using namespace std;

string process_subject(string s)
{
	string out;
	bool last_space = true;
	for (auto &&i : s)
	{
		if (last_space && !isspace(i))
		{
			out += toupper(i);
			last_space = false;
		}

		if (isspace(i))
		{
			last_space = true;
		}
	}
	return out;
}

string ma(int n)
{
	string out = "GV";
	string temp = to_string(n);
	if (temp.length() < 2)
	{
		out += "0";
	}
	out += temp;
	return out;
}

struct GiangVien
{
	string mgv, name, subject;
};

void in(struct GiangVien ds[], int n)
{
	for (int i = 0; i < n; i++)
	{
		ds[i].mgv = ma(i+1);
		getline(cin, ds[i].name);
	
		string temp;
		getline(cin, temp);
	
		ds[i].subject = process_subject(temp);
	}
	
}

void out(struct GiangVien ds[], string temp, int n)
{
	cout << "DANH SACH GIANG VIEN BO MON " << temp << ":" << endl;
	for (int i = 0; i < n; i++)
	{
		if (ds[i].subject == temp)
		{
			cout << ds[i].mgv << " " << ds[i].name << " " << ds[i].subject << endl;
		}
	}
}

int main()
{
	GiangVien ds[1001];

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
		out(ds, process_subject(temp), n);
	}
	
	
	
	return 0;
}