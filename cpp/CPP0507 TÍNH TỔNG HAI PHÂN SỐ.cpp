#include <bits/stdc++.h>
using namespace std;

long long GCD(long long x, long long y)
{
    while (y != 0)
    {
        long long r = x%y;
        x = y;
        y = r;
    }
    return x;
}

typedef struct PhanSo
{
    long long x, y;
}temp;

void nhap(temp &a)
{
    cin >> a.x >> a.y;  
}

PhanSo tong(temp &a1, temp &a2)
{
    PhanSo t;
    long long z = GCD(a1.y, a2.y);

    t.y = (a1.y*a2.y)/z;
    a1.x *= t.y/a1.y;
    a2.x *= t.y/a2.y;
    t.x = a1.x+a2.x;
    
    long long save = GCD(t.x, t.y);
    t.x /= save;
    t.y /= save;

    return t;
}

void in(temp &a)
{
    cout << a.x << "/" << a.y;
}


int main() {
	struct PhanSo p,q;
	nhap(p); nhap(q);
	PhanSo t = tong(p,q);
	in(t);
	return 0;
}