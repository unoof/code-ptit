#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

long long power(long long n, long long k, long long total)
{
    while (k > 0)
    {
        if (k & 1)
        {
            total = (total*n)%MOD;
        }
        n = (n*n)%MOD;
        k >>= 1;
    }
    
    return total;
}

void submit()
{
    long long n, k;
    cin >> n >> k;

    long long total = 1;
    
    cout << power(n, k, total);

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