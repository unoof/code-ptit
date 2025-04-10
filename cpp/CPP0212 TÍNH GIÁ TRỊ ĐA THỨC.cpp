#include <bits/stdc++.h>
using namespace std;
const long long modulo = 1e9+7;

void submit()
{
    int n, x;
    cin >> n >> x;
    
    int A[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    
    long long total = 0;

    for (int i = 0; i < n; i++)
    {
        long long sum = 1;
        for (int j = 1; j <= n-i-1; j++)
        {
            sum *= x;
            sum %= modulo;
        }
        
        total += A[i]*sum;
        total %= modulo;
    }
    
    cout << total;

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