#include <bits/stdc++.h>
using namespace std;

long long MOD = 1000000000000007;

long long mul_2_num(long long a, long long b)
{
    long long temp = 0;
    while (b > 0)
    {
        if (b&1)
        {
            temp = (temp+a)%MOD;
        }
        a = (a+a)%MOD;
        b >>= 1;
    }
    return temp;
}

vector<vector<long long>> multiply(vector<vector<long long>> &A, vector<vector<long long>> &B)
{
    vector<vector<long long>> C(4, vector<long long>(4, 0));

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                C[i][j] = (C[i][j]%MOD + mul_2_num(A[i][k], B[k][j])%MOD)%MOD;
            }
        }
    }

    return C;
}

vector<vector<long long>> setup(vector<vector<long long>> &A, int n)
{
    vector<vector<long long>> ans = {{1, 0 ,0, 0},
                                     {0, 1, 0, 0},
                                     {0, 0, 1, 0},
                                     {0, 0, 0, 1}};

    while (n > 0)
    {
        if (n&1)
        {
            ans = multiply(ans, A);
        }
        A = multiply(A, A);
        n >>= 1;
    }
    return ans;
}

void submit()
{
    int n;
    cin >> n;
    
    if (n == 0)
    {
        cout << 0 << endl;
        return;
    }
    else if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    else if (n == 2)
    {
        cout << 3 << endl;
        return;
    }
    else if (n == 3)
    {
        cout << 6 << endl;
        return;
    }
    
    
    vector<vector<long long>> M = {{1, 1, 1, 0},
                                   {1, 0, 0, 0},
                                   {0, 1, 0, 0},
                                   {1, 1, 1, 1}};
    vector<vector<long long>> T = {{3, 0, 0, 0},
                                   {2, 0, 0, 0},
                                   {1, 0, 0, 0},
                                   {6, 0, 0, 0}};

    vector<vector<long long>> ans = setup(M, n-3);
    ans = multiply(ans, T);
    
    cout << ans[3][0];

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