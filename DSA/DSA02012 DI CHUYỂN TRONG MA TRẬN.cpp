#include <bits/stdc++.h>
using namespace std;

int n, m;
void go_right(vector<vector<int>> &A, int i, int j, int &count);

void go_down(vector<vector<int>> &A, int i, int j, int &count)
{
    if (i+j == n+m-2)
    {
        count++;
        return;
    }

    if (i+1 == n)
    {
        return;
    }
    
    i++;
    go_down(A, i, j, count);
    go_right(A, i, j, count);
}

void go_right(vector<vector<int>> &A, int i, int j, int &count)
{
    if (j+1 == m)
    {
        return;
    }

    j++;
    go_down(A, i, j, count);
    go_right(A, i, j, count);
}

void submit()
{
    int count = 0;
    cin >> n >> m;
    vector<vector<int>> A(n, vector<int> (m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> A[i][j];
        }
    }
    
    go_down(A, 0, 0, count);
    go_right(A, 0, 0, count);
    cout << count << endl;
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