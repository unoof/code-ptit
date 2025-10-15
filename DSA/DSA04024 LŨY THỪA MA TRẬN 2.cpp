#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

void multiply(vector<vector<long long>> &A, vector<vector<long long>> &B, int n)
{
    vector<vector<long long>> C(n, vector<long long> (n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                C[i][j] += (A[i][k]*B[k][j])%MOD;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            A[i][j] = C[i][j]%MOD;
        }
    }
}

vector<vector<long long>> power(vector<vector<long long>> A, int n, int times)
{
    vector<vector<long long>> ans(n, vector<long long> (n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                ans[i][j] = 1;
            }
            else
            {
                ans[i][j] = 0;
            }
        }
    }
    
    while (times)
    {
        if (times & 1)
        {
            multiply(ans, A, n);
        }
        multiply(A, A, n);
        times >>= 1;
    }
    
    return ans;
}

void submit()
{
    int n, k;
    cin >> n >> k;

    vector<vector<long long>> A(n, vector<long long> (n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    }

    A = power(A, n, k);
    long long total = 0;

    for (int i = 0; i < n; i++)
    {
        total += A[i][n-1]%MOD;
    }
    
    cout << total%MOD;

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