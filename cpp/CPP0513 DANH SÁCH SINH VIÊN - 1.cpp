#include <bits/stdc++.h>
using namespace std;

struct SinhVien
{
    string msv, name, lop, birth;
    float GPA;
};

string STT(int n)
{
    string temp = to_string(n);

    while (temp.length() < 3)
    {
        temp = '0' + temp;
    }
    return "B20DCCN" + temp;
}

void nhap(SinhVien ds[], int n)
{
    for (int i = 0; i < n; i++)
    {
        ds[i].msv  = STT(i+1);
        cin.ignore();
        getline(cin, ds[i].name);
        cin >> ds[i].lop >> ds[i].birth >> ds[i].GPA;

        stringstream ss(ds[i].birth);
        string date;
        vector<string> save;

        while (getline(ss, date, '/'))
        {
            save.push_back(date);
        }

        string day = save[0];
        string month = save[1];
        string year = save[2];

        day = (day.size() < 2) ? "0" + day : day;
        month = (month.size() < 2) ? "0" + month : month;

        ds[i].birth = day + "/" + month + "/" + year;
    }
}

void in(SinhVien ds[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << ds[i].msv << " " << ds[i].name << " " << ds[i].lop << " " << ds[i].birth << " " << setprecision(2) << fixed << ds[i].GPA;
        cout << endl;
    }
    
}

int main(){
    struct SinhVien ds[50];
    int N;
    cin >> N;
    nhap(ds, N);
    in(ds, N);
    return 0;
}