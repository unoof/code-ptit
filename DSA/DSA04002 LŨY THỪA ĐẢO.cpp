#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

long long power(long long n, long long k)
{
    if (k == 0) return 1;
    long long temp = (power(n, k/2));
    if (k%2 == 0) return (temp*temp)%MOD;
    return (n*((temp*temp)%MOD))%MOD;
}

long long rev(long long n)
{
    long long res = 0;
    while (n > 0)
    {
        res = res*10 + n%10;
        n /= 10;
    }
    return res;
}

void submit()
{
    long long n, k;
    cin >> n;
    k = rev(n);

    
    cout << power(n, k);

    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);                                    // Speed up input/output
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test;
    cin >> test;
    while (test--)
    {
        submit();
    }
    

    return 0;
}