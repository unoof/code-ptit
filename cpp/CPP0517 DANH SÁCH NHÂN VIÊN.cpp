#include <bits/stdc++.h>
using namespace std;

typedef struct NhanVien
{
    string id, name, gender, birth, address, tax, sign_date;
}temp;

void nhap(temp &a)
{
    cin.ignore();
    getline(cin, a.name);
    getline(cin, a.gender);
    getline(cin , a.birth);
    getline(cin, a.address);
    cin >> a.tax >> a.sign_date;

}

string stt(int n)
{
    string r = to_string(n);
    while (r.size() < 5)
    {
        r = "0" + r;
    }
    return r;
}

void inds(temp ds[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << stt(i+1) << " ";
        cout << ds[i].name << " " << ds[i].gender << " " << ds[i].birth << " " << ds[i].address << " " << ds[i].tax << " " << ds[i].sign_date << endl;
    }
}


int main(){
    struct NhanVien ds[50];
    int N,i;
    cin >> N;
    for(i = 0; i < N; i++) nhap(ds[i]);
    inds(ds,N);
    return 0;
}