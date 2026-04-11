#include <bits/stdc++.h>
using namespace std;

void degree(vector<vector<int>> &A, int n)
{
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] == 1)
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
        int count = 0;
        vector<int> ans;
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] == 1)
            {
                count++;
                ans.push_back(j+1);
            }
        }
        cout << count << " ";
        for (auto &&k : ans)
        {
            cout << k << " ";
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
    
    vector<vector<int>> A(n, vector<int>(n));
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
            if (A[i][j] == 1)
            {
                count++;
            }
        }
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