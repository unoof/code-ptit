#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

void multiply(vector<vector<long long>> &A, vector<vector<long long>> &B)
{
    vector<vector<long long>> C(2, vector<long long>(2));

    C[0][0] = ((A[0][0]*B[0][0])%MOD + (A[0][1]*B[1][0])%MOD)%MOD;
    C[0][1] = ((A[0][0]*B[0][1])%MOD + (A[0][1]*B[1][1])%MOD)%MOD;

    C[1][0] = ((A[1][0]*B[0][0])%MOD + (A[1][1]*B[1][0])%MOD)%MOD;
    C[1][1] = ((A[1][0]*B[0][1])%MOD + (A[1][1]*B[1][1])%MOD)%MOD;

    A[0][0] = C[0][0];
    A[0][1] = C[0][1];
    A[1][0] = C[1][0];
    A[1][1] = C[1][1];
}

vector<vector<long long>> power(vector<vector<long long>> A, int times)
{
    vector<vector<long long>> ans ={{1, 0}, {0, 1}};
    while (times)
    {
        if (times & 1)
        {
            multiply(ans, A);
        }
        multiply(A, A);
        times >>= 1;
    }
    
    return ans;
}

void submit()
{
    int n;
    cin >> n;

    vector<vector<long long>> F =   {{1, 0},
                                    {0, 0}};
    vector<vector<long long>> M =   {{1, 1}, 
                                    {1, 0}};

    vector<vector<long long>> ans = power(M, n-1);

    multiply(ans, F);

    cout << ans[0][0]%MOD;

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