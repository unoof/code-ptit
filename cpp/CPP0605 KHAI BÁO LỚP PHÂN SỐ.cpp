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

class PhanSo
{
public:
    long long x, y;
    PhanSo(long long a, long long b) : x(a), y(b) {}

    friend std::ostream& operator<<(std::ostream& os, const PhanSo& p);
    friend std::istream& operator>>(std::istream& is, PhanSo& p);

    void rutgon()
    {
        long long temp = GCD(x, y);
        x /= temp;
        y /= temp;
    }
};

istream& operator>>(istream& is, PhanSo& obj)
{
    is >> obj.x >> obj.y;
    return is;
}

ostream& operator<<(ostream& os, const PhanSo& obj)
{
    os << obj.x << "/" << obj.y;
    return os;
}

int main() {
	PhanSo p(1,1);
	cin >> p;
	p.rutgon();
	cout << p;
	return 0;
}