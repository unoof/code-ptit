#include <bits/stdc++.h>
using namespace std;

long long GCD(long long a, long long b)
{
    while (b != 0)
    {
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}

void submit()
{
    long long a, b;
    cin >> a >> b;

    long long c = GCD(a, b);

    long long LCM = (a*b)/c;

    cout << LCM << "  " << c;

    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);                                    // Speed up input/output
    cin.tie(nullptr);
    cout.tie(nullptr);

    int so_bo_test;
    cin >> so_bo_test;

    while (so_bo_test--)
    {
        submit();
    }

    return 0;
}