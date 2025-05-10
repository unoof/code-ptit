#include <bits/stdc++.h>
using namespace std;

struct human
{
    string name;
    int d, m, y;
};

bool compare(const human &a, const human &b)
{
    if (a.y > b.y)
    {
        return 1;
    }
    else if (a.y == b.y)
    {
        if (a.m > b.m)
        {
            return 1;
        }
        else if (a.m == b.m)
        {
            if (a.d > b.d)
            {
                return 1;
            }
        }
    }
    return 0;
}

void nhap(human &a)
{
    cin >> a.name;    
    string temp;
    cin >> temp;

    stringstream ss(temp);
    string word;
    vector<string> save;

    while (getline(ss, word, '/'))
    {
        save.push_back(word);
    }
    
    a.d = stoi(save[0]);
    a.m = stoi(save[1]);
    a.y = stoi(save[2]);
}

void sap_xep(human s[], int n)
{
    sort(s, s + n, compare);
}

void in_ds(human ds[], int n)
{
    cout << ds[0].name << endl << ds[n-1].name;
}

int main(){
    int n;
    cin >> n;
    struct human *ds = new human[n];
    for(int i = 0; i < n; i++) {
        nhap(ds[i]);
	}
	sap_xep(ds, n);
    in_ds(ds,n);
    return 0;
}