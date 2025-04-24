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

void rutgon(temp &a)
{
    long long z = GCD(a.x, a.y);
    a.x /= z;
    a.y /= z;
}

void in(temp &a)
{
    cout << a.x << "/" << a.y;
}

int main() {
	struct PhanSo p;
	nhap(p);
	rutgon(p);
	in(p);
	return 0;
}