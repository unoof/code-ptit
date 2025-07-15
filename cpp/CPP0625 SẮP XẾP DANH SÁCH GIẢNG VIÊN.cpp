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

string last_name(string s)
{
	stringstream ss(s);
	string temp;
	vector<string> A;
	while (ss >> temp)
	{
		A.push_back(temp);
	}
	
	return A[A.size() - 1];
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
	string mgv, name, subject, last_name;
	int stt;
};

bool compare(GiangVien& a, GiangVien& b)
{
	if (a.last_name == b.last_name)
	{
		return a.stt < b.stt;
	}
	return a.last_name < b.last_name;
}

void sort_list(GiangVien ds[], int n)
{
	sort(ds, ds + n, compare);
}

void in(GiangVien ds[], int n)
{
	for (int i = 0; i < n; i++)
	{
		ds[i].mgv = ma(i+1);
		ds[i].stt = i;
		getline(cin, ds[i].name);
	
		string temp;
		getline(cin, temp);
	
		ds[i].subject = process_subject(temp);
		ds[i].last_name = last_name(ds[i].name);
	}
	
}

void out(GiangVien ds[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << ds[i].mgv << " " << ds[i].name << " " << ds[i].subject << endl;
	}
}

int main()
{
	GiangVien ds[1001];

	int n;
	cin >> n;
	cin.ignore();

	in(ds, n);
	sort_list(ds, n);

	int count;
	cin >> count;
	cin.ignore();


	out(ds, n);
	
	
	
	return 0;
}