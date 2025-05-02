#include <bits/stdc++.h>
using namespace std;

long mod = 1e9 +7;

long long mod_pow(long long a, long long b)                                 //dùng fermat's little theorem vì cách khác WA :)
{
    long long result = 1;
    a %= mod;

    while (b > 0)
    {
        if (b % 2 == 1)
        {
            result = (result * a) % mod;
        }
        a = (a * a) % mod;
        b /= 2;
    }

    return result;
}

void submit()
{
    int n, r;
    cin >> n >> r;

    long long total = 1;
    long long temp = 1;
    int count = 1;


    for (long long i = r+1; i <= n; i++)
    {
        total = (total*i)%mod;

        total = (total*mod_pow(count, mod-2))%mod;
        count++;
    }
    
    cout << total/temp;
    
    cout << endl;
}



int main()
{
    ios::sync_with_stdio(false);                                    // Speed up input/output
    cin.tie(nullptr);
    cout.tie(nullptr);

    int so_bo_test;
    cin >> so_bo_test;
    cin.ignore();


    while (so_bo_test--)
    {
        submit();
    }

    return 0;
}