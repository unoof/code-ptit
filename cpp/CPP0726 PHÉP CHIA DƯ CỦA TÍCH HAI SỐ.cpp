#include <bits/stdc++.h>
using namespace std;

long long multi_mod(long long a, long long b, long long mod)        //using binary decomposition for safty 
{
    long long total = 0;
    a %= mod;

    while (b > 0)
    {
        if (b%2 == 1)
        {
            total = (total+a)%mod;
        }
        
        a = a*2%mod;
        b /= 2;
    }
    return total;
}

void submit()
{
    long long a, b, c;
    cin >> a >> b >> c;

    cout << multi_mod(a, b, c);
    
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