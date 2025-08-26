#include <bits/stdc++.h>
using namespace std;

int n;
bool found = false;
void go_right(vector<vector<int>> &A, int i, int j, string s);

void go_down(vector<vector<int>> &A, int i, int j, string s)
{
    if (i+j == n*2-2)
    {
        cout << s << " ";
        found = true;
        return;
    }

    if (i+1 == n || A[i+1][j] == 0)
    {
        return;
    }
    
    s += "D";
    i++;
    go_down(A, i, j, s);
    go_right(A, i, j, s);
}

void go_right(vector<vector<int>> &A, int i, int j, string s)
{
    if (j+1 == n || A[i][j+1] == 0)
    {
        return;
    }

    s += "R";
    j++;
    go_down(A, i, j, s);
    go_right(A, i, j, s);
}

void submit()
{
    cin >> n;
    vector<vector<int>> A(n, vector<int> (n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    }

    if (A[0][0] != 0)
    {
        int i = 0, j = 0;
        string s;
        go_down(A, i, j, s);
        go_right(A, i, j, s);
        cout << endl;
    }

    if (!found)
    {
        cout << -1 << endl;
    }
    found = false;
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