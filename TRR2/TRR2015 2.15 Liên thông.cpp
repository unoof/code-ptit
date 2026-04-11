#include <bits/stdc++.h>
using namespace std;

bool check(vector<bool> &visited)
{
    for (auto &&i : visited)
    {
        if (!i) return false;
    }
    return true;
}

bool DFS(vector<vector<int>> &A, int n)
{
    vector<bool> visited(n, false);
    stack<int> save;
    
    save.push(0);
    visited[0] = true;
    
    while (save.size() != 0)
    {
        int temp = save.top();
        save.pop();
        
        for (int i = n-1; i >= 0; i--)
        {
            if (A[temp][i] == 1 && !visited[i])
            {
                save.push(i);
                save.push(temp);
                visited[i] = true;
                break;
            }
        }
    }
    return check(visited);
}

void transposition_matrix(vector<vector<int>> &A, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            swap(A[i][j], A[j][i]);
        }
    }
}

void undirection_graph(vector<vector<int>> &A, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] == 1 || A[j][i] == 1)
            {
                A[i][j] = A[j][i] = 1;
            }
        }
    }
}

void submit()
{
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    
    int n;
    cin >> n;
    
    
    vector<vector<int>> A(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    }
    
    bool ans1 = DFS(A, n);
    transposition_matrix(A, n);
    bool ans2 = DFS(A, n);
    undirection_graph(A, n);
    bool ans3 = DFS(A, n);
    
    if (ans1 && ans2)
    {
        cout << 1;
    }
    else if (ans3)
    {
        cout << 2;
    }
    else
    {
        cout << 0;
    }
    
}

int main()
{
    submit();
    return 0;
}