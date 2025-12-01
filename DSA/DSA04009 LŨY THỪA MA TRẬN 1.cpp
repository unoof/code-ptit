#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9+7;

void multiply(vector<vector<long long>> &A, vector<vector<long long>> &B, int n)
{
    vector<vector<long long>> C(n, vector<long long>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                C[i][j] += (A[i][k]*B[k][j]);
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

vector<vector<long long>> setup(vector<vector<long long>> &A, int n, int k)
{
    vector<vector<long long>> ans(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++)
    {
        ans[i][i] = 1;
    }
    
    while (k > 0)
    {
        if (k&1)
        {
            multiply(ans, A, n);
        }
        multiply(A, A, n);
        k >>= 1;
    }
    return ans;
}

void submit()
{
    int n, k;
    cin >> n >> k;
    
    vector<vector<long long>> M(n, vector<long long>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> M[i][j];
        }
    }
    
    vector<vector<long long>> ans = setup(M, n, k);
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
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