#include <bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>> &A, vector<bool> &visited, int n, int start, int locked)
{
    stack<int> save;
    
    save.push(start);
    visited[start] = true;
    
    while (save.size() != 0)
    {
        int temp = save.top();
        bool check = false;
        
        for (int i = 0; i < n; i++)
        {
            if (A[temp][i] == 1 && !visited[i] && i != locked)
            {
                save.push(i);
                visited[i] = true;
                check = true;
                break;
            }
        }
        if (!check)
        {
            save.pop();
        }
    }
}

int interconnected(vector<vector<int>> &A, int n, int locked)
{
    vector<bool> visited(n, false);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && i != locked)
        {
            DFS(A, visited, n, i, locked);
            count++;
        }
    }
    return count;
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

    vector<int> ans;
    int first = interconnected(A, n, -1);

    for (int i = 0; i < n; i++)
    {
        if (interconnected(A, n, i) > first)
        {
            ans.push_back(i+1);
        }
    }
    


    cout << ans.size() << '\n';
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
}

int main()
{
    submit();
    return 0;
}