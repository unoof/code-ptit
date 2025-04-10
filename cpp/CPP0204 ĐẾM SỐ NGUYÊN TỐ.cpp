#include <bits/stdc++.h>
using namespace std;

vector<bool> prime_num()
{
    vector<bool> prime(100000, true);
    prime[0] = prime[1] = false;

    for (int i = 2; i*i <= 100000; i++)
    {
        for (int j = i*2; j <= 100000; j+=i)
        {
            prime[j] = false;
        }
        
    }
    return prime;
}

void submit()
{
    int l, r;
    cin >> l >> r;

    int count = 0;
    vector<bool> prime = prime_num();

    for (int i = l; i <= r; i++)
    {
        if (prime[i])
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

    while (so_bo_test--)
    {
        submit();
    }

    return 0;
}