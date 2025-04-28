#include <bits/stdc++.h>
using namespace std;

bool is_prime(long long n)
{
    if (n == 1 || n == 0)
    {
        return false;
    }
    
    for (int i = 2; i*i <= n; i++)
    {
        if (n%i == 0)
        {
            return false;
        }
        
    }
    return true;
}

void submit()
{
    long long n, m;
    cin >> n >> m;
    int count = 0;

    for (long long i = n; i*i <= m; i++)
    {
        if (is_prime(i))
        {
            count++;
        }
        
    }
    
    cout << count;
    
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