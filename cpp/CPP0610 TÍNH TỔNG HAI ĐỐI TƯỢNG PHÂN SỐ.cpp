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

    PhanSo operator+(const PhanSo& other) const {
        long long z = GCD(y, other.y);
        
        long long temp1 = x*(other.y/z) + other.x*(y/z);
        long long temp2 = y*other.y/z;

        long long save = GCD(temp1, temp2);

        temp1 /= save;
        temp2 /= save;

        return PhanSo(temp1, temp2);
    }

    friend std::ostream& operator<<(std::ostream& os, const PhanSo& p);
    friend std::istream& operator>>(std::istream& is, PhanSo& p);
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
	PhanSo p(1,1), q(1,1);
	cin >> p >> q;
	cout << p + q;
	return 0;
}
