#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9+7;

void multiply(vector<vector<long long>> &A, vector<vector<long long>> &B)
{
    vector<vector<long long>> C(2, vector<long long>(2, 0));

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                C[i][j] += (A[i][k]*B[k][j])%MOD;
            }
        }
    }
    
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            A[i][j] = C[i][j];
        }
    }
}

vector<vector<long long>> setup(vector<vector<long long>> &A, int n)
{
    vector<vector<long long>> ans = {{1, 0},
                                     {0, 1}};
    while (n > 0)
    {
        if (n&1)
        {
            multiply(ans, A);
        }
        multiply(A, A);
        n >>= 1;
    }
    return ans;
}

void submit()
{
    int n;
    cin >> n;
    
    vector<vector<long long>> M = {{1, 1},
                                   {1, 0}};
    vector<vector<long long>> T = {{1, 0},
                                   {0, 0}};
    vector<vector<long long>> ans = setup(M, n-1);
    multiply(ans, T);

    
    cout << ans[0][0];

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