#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

vector<long long> fibonacci()
{
    vector<long long> fibo(1001);
    fibo[0] = 0;
    fibo[1] = 1;

    for (int i = 2; i <= 1000; i++)
    {
        fibo[i] = (fibo[i-1] + fibo[i-2]) % MOD;
    }
    
    return fibo;
}

void submit(vector<long long> fibo)
{
    int n;
    cin >> n;
    
    
    cout << fibo[n];
    
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

    vector<long long> fibo = fibonacci();
    
    while (so_bo_test--)
    {
        submit(fibo);
    }

    return 0;
}