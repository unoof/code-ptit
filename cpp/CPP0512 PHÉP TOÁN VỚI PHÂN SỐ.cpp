#include <bits/stdc++.h>
using namespace std;

long long GCD(long long x, long long y)
{
    while (y != 0)
    {
        long long r = x%y;
        x=y;
        y=r;
    }
    return x;
}

struct PhanSo
{
    long long tu, mau;
};

void process(PhanSo& A, PhanSo& B)
{
    PhanSo temp;

    long long save = GCD(A.mau, B.mau);

    temp.tu = A.tu*(B.mau/save) + B.tu*(A.mau/save);
    temp.mau = A.mau*B.mau/save;

    temp.tu *= temp.tu;
    temp.mau *= temp.mau;

    save = GCD(temp.tu, temp.mau);

    cout << temp.tu/save << "/" << temp.mau/save << " ";

    temp.tu *= A.tu*B.tu;
    temp.mau *= A.mau*B.mau;

    save = GCD(temp.tu, temp.mau);

    cout << temp.tu/save << "/" << temp.mau/save << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		PhanSo A;
		PhanSo B;
		cin >> A.tu >> A.mau >> B.tu >> B.mau;
		process(A, B);
	}
}