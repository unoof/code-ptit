#include <bits/stdc++.h>
using namespace std;

struct ThiSinh
{
    string Ho_ten;
    string ngay_sinh;
    double mon_1;
    double mon_2;
    double mon_3;

};

void nhap(ThiSinh &a)
{
    getline(cin, a.Ho_ten);
    getline(cin, a.ngay_sinh);
    cin >> a.mon_1 >> a.mon_2 >> a.mon_3;
}

void in(ThiSinh &a)
{
    for (auto &&i : a.Ho_ten)
    {
        cout << i;
    }
    cout << " ";

    for (auto &&i : a.ngay_sinh)
    {
        cout << i;
    }
    cout << " ";

    cout << setprecision(1) << fixed << a.mon_1+a.mon_2+a.mon_3;
}

int main(){
    struct ThiSinh A;
    nhap(A);
    in(A);
    return 0;
}