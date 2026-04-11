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
            if (A[i][j] != 10000 && A[i][j] != 0)
            {
                A[j][i] = 0;
                cout << i+1 << " " << j+1 << " " << A[i][j] << endl;
            }
        }
    }
}

void submit()
{
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    int n, s;
    cin >> s >> n;
    
    vector<vector<int>> A(n, vector<int>(n, 0));
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
            if (A[i][j] != 10000 && A[i][j] != 0) count++;
        }
        
    }
    

    if (s == 1)
    {
        degree(A, n);
    }
    else
    {
        cout << n << " " << count/2 << endl;
        adj(A, n);
    }
}

int main()
{
    submit();
    return 0;
}