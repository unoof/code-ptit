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
    
    vector<vector<int>> A(n, vector<int>(n, 0));
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int start, end;
        cin >> start >> end;
        A[start-1][end-1] = A[end-1][start-1] = 1;
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