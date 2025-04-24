#include <bits/stdc++.h>
using namespace std;

typedef struct NhanVien
{
    string name;
    string gender;
    string birth;
    string address;
    long long number;
    string sign_date;
}temp;

void nhap(temp &a)
{
    getline(cin, a.name);
    getline(cin, a.gender);
    getline(cin , a.birth);
    getline(cin, a.address);
    cin >> a.number >> a.sign_date;

    if (a.birth.size() == 8)
    {
        a.birth = "0" + a.birth.substr(0, 2) + "0" + a.birth.substr(2);
    }
    else if (a.birth.size() == 9)
    {
        if (a.birth[0] =='0')
        {
            a.birth = a.birth.substr(0, 3) +  "0" + a.birth.substr(3);
        }
        else
        {
            a.birth = "0" + a.birth;
        }
        
    }
    
    if (a.sign_date.size() == 8)
    {
        a.sign_date = "0" + a.sign_date.substr(0, 2) + "0" + a.sign_date.substr(2);
    }
    else if (a.sign_date.size() == 9)
    {
        if (a.sign_date[0] =='0')
        {
            a.sign_date = a.sign_date.substr(0, 3) +  "0" + a.sign_date.substr(3);
        }
        else
        {
            a.sign_date = "0" + a.sign_date;
        }
        
    }

}

void in(temp &a)
{
    cout << "00001 ";
    for (auto &&i : a.name)
    {
        cout << i;
    }
    cout << " ";
    for (auto &&i : a.gender)
    {
        cout << i;
    }
    cout << " ";
    for (auto &&i : a.birth)
    {
        cout << i;
    }
    cout << " ";
    for (auto &&i : a.address)
    {
        cout << i;
    }
    cout << " " << a.number << " ";
    for (auto &&i : a.sign_date)
    {
        cout << i;
    }
}

int main(){
    struct NhanVien a;
    nhap(a);
    in(a);
    return 0;
}