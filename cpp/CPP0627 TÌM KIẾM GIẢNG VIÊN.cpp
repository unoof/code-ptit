#include <bits/stdc++.h>
using namespace std;

string lower(string s)
{
	for (auto &&i : s)
	{
		i = tolower(i);
	}
	return s;
}

string stt(int n)
{
	string temp = "GV";
	if (to_string(n+1).size() >= 2)
	{
		return temp + to_string(n+1);
	}
	return temp + '0' + to_string(n+1);
}

string process_subject(string s)
{
	string temp;
	bool last_space = true;
	for (auto &&i : s)
	{
		if (isspace(i))
		{
			last_space = true;
		}
		if (last_space && !isspace(i))
		{
			temp += toupper(i);
			last_space = false;
		}
	}
	return temp;
}

bool compare(string s, string t)
{
	for (int i = 0; i <= s.size() - t.size(); i++)
	{
		string temp = s.substr(i, t.size());
		if (temp == t)
		{
			return true;
		}
	}
	return false;
}

struct GiangVien
{
	string mgv, name, subject, name_lower;
};

void in(GiangVien ds[], int n)
{
	for (int i = 0; i < n; i++)
	{
		ds[i].mgv = stt(i);
		getline(cin, ds[i].name);
		string temp;
		getline(cin, temp);
		ds[i].subject = process_subject(temp);
		ds[i].name_lower = lower(ds[i].name);
	}
	
}

void out(GiangVien ds[], int n, string s)
{
	cout << "DANH SACH GIANG VIEN THEO TU KHOA " << s << ":" << endl;
	for (int i = 0; i < n; i++)
	{
		if (compare(ds[i].name_lower, lower(s)))
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
		out(ds, n, temp);
	}
	


	
	
	
	return 0;
}