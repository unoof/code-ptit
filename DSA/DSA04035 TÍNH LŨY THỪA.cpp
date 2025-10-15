#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void multiply(long long &n, long long &k)
{
    n = (n*k)%MOD;
}

long long power(long long n, long long k)
{
    long long ans = 1;
    while (k)
    {
        if (k&1)
        {
            multiply(ans, n);
        }
        multiply(n, n);
        k >>= 1;
    }
    return ans;
}

void submit()
{
    long long n, k;
    while (true)
    {
        cin >> n >> k;
        if (n == 0 && k == 0)
        {
            break;
        }
        
        cout << power(n, k)%MOD;

        cout << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);                                    // Speed up input/output
    cin.tie(nullptr);
    cout.tie(nullptr);

    submit();

    return 0;
}