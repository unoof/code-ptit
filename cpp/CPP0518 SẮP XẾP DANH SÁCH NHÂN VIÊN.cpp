#include <bits/stdc++.h>
using namespace std;

string process_date(string n)
{
    stringstream ss(n);
    string temp;
    vector<string> date;
    

    while (getline(ss, temp, '/'))
    {
        date.push_back(temp);
    }
    
    string day = date[0];
    string month = date[1];
    string year = date[2];

    day = (day.size() == 1) ? "0" + day : day;
    month = (month.size() == 1) ? "0" + month : month;

    return day + "/" + month + "/" + year;
}

string STT(int i)
{
    string temp = to_string(i);
    while (temp.size() < 5)
    {
        temp = "0" + temp;
    }
    return temp;
}

struct NhanVien
{
    string mnv, name, gender, birth, address, tax, sign_date;
    int day, month, year;
};

bool compare(const NhanVien &a, const NhanVien &b)
{
    if (a.year == b.year)
    {
        if (a.month == b.month)
        {
            return a.day < b.day;
        }
        else
        {
            return a.month < b.month;
        }
    }
    else
    {
        return a.year < b.year;
    }
}

void nhap(NhanVien &a)
{
    cin.ignore();
    string temp_birth;
    string temp_sign_date;

    getline(cin, a.name);
    getline(cin, a.gender);
    getline(cin, temp_birth);
    getline(cin, a.address);
    cin >> a.tax >> temp_sign_date;

    a.birth = process_date(temp_birth);
    a.sign_date = process_date(temp_sign_date);

    a.month = stoi(a.birth.substr(0,2));
    a.day = stoi(a.birth.substr(3,2));
    a.year = stoi(a.birth.substr(6,4));
}

void sapxep(NhanVien s[],int n)
{
    for(int i = 0; i < n; i++)
    {
        s[i].mnv = STT(i+1);
    }
    sort(s, s + n, compare);
}

void inds(NhanVien ds[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << ds[i].mnv << " " << ds[i].name <<  " " << ds[i].gender << " " << ds[i].birth << " " << ds[i].address << " " << ds[i].tax << " " << ds[i].sign_date;
        cout << endl;
    }
    
}

int main(){
    struct NhanVien ds[50];
    int N,i;
    cin >> N;
    for(i = 0; i < N; i++) nhap(ds[i]);
    sapxep(ds, N);
    inds(ds, N);
    return 0;
}