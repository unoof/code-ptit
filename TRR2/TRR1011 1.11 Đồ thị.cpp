#include <bits/stdc++.h>
using namespace std;

void degree(vector<vector<int>> &A, int n)
{
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] != 10000 && A[i][j] != 0)
            {
                count++;
            }
        }
        cout << count << " ";
    }
}

void adj(vector<vector<int>> &A, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            i == j ? (cout << 0 << " ") : (cout << A[i][j] << " ");
        }
        cout << endl;
    }
}

void submit()
{
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    int n, s;
    cin >> s >> n;
    
    vector<vector<int>> A(n, vector<int>(n, 10000));
    int count = 0;
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        A[u-1][v-1] = A[v-1][u-1] = w;
    }
    

    if (s == 1)
    {
        degree(A, n);
    }
    else
    {
        cout << n << endl;
        adj(A, n);
    }
}

int main()
{
    submit();
    return 0;
}