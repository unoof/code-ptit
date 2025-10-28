#include <bits/stdc++.h>
using namespace std;

vector<bool> prepare()
{
    vector<bool> prime(1e6+1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i*i < 1e6+1; i++)
    {
        for (int j = i*i; j < 1e6+1; j+=i)
        {
            prime[j] = false;
        }
    }
    return prime;
}

void submit(vector<bool> &prime)
{
    int n;
    cin >> n;
    
    bool check = false;
    for (int i = 0; i < n; i++)
    {
        if (prime[n-i] && prime[i])
        {
            check = true;
            cout << i << " " << n-i;
            break;
        }
    }

    if (!check) cout << -1;
    

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
    
    vector<bool> prime = prepare();
    while (so_bo_test--)
    {

        submit(prime);
    }

    return 0;
}