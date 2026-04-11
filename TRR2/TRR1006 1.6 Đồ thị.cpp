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

void adj(vector<vector<int>> &A, int n, int total)
{
    vector<vector<int>> temp(n, vector<int>(total, 0));

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] == 1)
            {
                A[j][i] = 0;
                temp[i][count] = 1; temp[j][count] = 1;
                count++;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < total; j++)
        {
            cout << temp[i][j] << " ";
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
        cout << n << " " << k << endl;
        adj(A, n, k);
    }
    
}

int main()
{
    submit();
    return 0;
}