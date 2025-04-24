#include <bits/stdc++.h>
using namespace std;

typedef struct SinhVien
{
    string ho_ten;
    string lop;
    string ngay_sinh;
    float GPA;
}temp;

void nhap(temp &a)
{
    getline(cin, a.ho_ten);
    getline(cin, a.lop);
    getline(cin , a.ngay_sinh);

    if (a.ngay_sinh.size() == 8)
    {
        a.ngay_sinh = "0" + a.ngay_sinh.substr(0, 2) + "0" + a.ngay_sinh.substr(2);
    }
    else
    {
        if (a.ngay_sinh[0] =='0')
        {
            a.ngay_sinh = a.ngay_sinh.substr(0, 3) +  "0" + a.ngay_sinh.substr(3);
        }
        else
        {
            a.ngay_sinh = "0" + a.ngay_sinh;
        }
        
    }
    

    cin >> a.GPA;
}

void in(temp &a)
{
    cout << "B20DCCN001 ";
    for (auto &&i : a.ho_ten)
    {
        cout << i;
    }
    cout << " ";
    for (auto &&i : a.lop)
    {
        cout << i;
    }
    cout << " ";
    for (auto &&i : a.ngay_sinh)
    {
        cout << i;
    }
    cout << " ";
    cout << setprecision(2) << fixed << a.GPA;
}

int main(){
    struct SinhVien a;
    nhap(a);
    in(a);
    return 0;
}