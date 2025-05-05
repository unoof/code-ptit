#include <bits/stdc++.h>
using namespace std;

vector<int> M = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
vector<int> N = {-1, -1, -1, 0, 0, 0, 1, 1, 1};

void check(vector<vector<int>> &A, int n, int m, int max_n, int max_m)
{
    for (int i = 0; i < 9; i++)
    {
        if (n - N[i] >= 0 && m - M[i] >= 0 && n - N[i] < max_n && m - M[i] < max_m)
        {
            if (A[n-N[i]][m-M[i]] == 1)
            {
                A[n-N[i]][m-M[i]] = 0;
                check(A, n-N[i], m-M[i], max_n, max_m);
            }
        }
    }
}

void submit()
{
    int n, m, count = 0;
    cin >> n >> m;

    vector<vector<int>> A(n, vector<int> (m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> A[i][j];
        }
        
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (A[i][j] == 1)
            {
                A[i][j] = 0;
                check(A, i, j, n, m);
                count++;
            }
            
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