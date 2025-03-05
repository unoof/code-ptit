#include <bits/stdc++.h>
using namespace std;

long long GCD(long long a, long long b)
{
    if (a == 0 && b == 0) return 0;

    if (a == 0) return b;
    if (b == 0) return a;
    
    while (b != 0)
    {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void submit()
{
    int a;
    cin >> a;

    long long result {1};

    for (int i = 2; i <= a; i++)
    {
        result = (result*i)/GCD(result, i);
    }
    
    cout << result;
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