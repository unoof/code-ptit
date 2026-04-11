#include <bits/stdc++.h>
using namespace std;

void BFS(vector<vector<int>> &A, vector<bool> &visited, int n, int start)
{
    queue<int> save;
    
    save.push(start);
    visited[start] = true;
    
    while (save.size() != 0)
    {
        int temp = save.front();
        save.pop();
        
        for (int i = 0; i < n; i++)
        {
            if (A[temp][i] == 1 && !visited[i])
            {
                save.push(i);
                visited[i] = true;
            }
        }
    }
}

int interconnected(vector<vector<int>> &A, int n, int u, int v)
{
    vector<bool> visited(n, false);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        A[u][v] = A[v][u] = 0;
        if (!visited[i])
        {
            BFS(A, visited, n, i);
            count++;
        }
        A[u][v] = A[v][u] = 1;
    }
    return count;
}

void submit()
{
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);

    int n;
    cin >> n;
    
    vector<vector<int>> A(n+1, vector<int>(n+1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    }

    vector<pair<int,int>> ans;
    int first = interconnected(A, n, n, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (A[i][j] == 1 && interconnected(A, n, i, j) > first)
            {
                ans.push_back({i+1, j+1});
            }
        }
    }
    


    cout << ans.size() << '\n';
    for (auto &&i : ans)
    {
        cout << i.first << " " << i.second << '\n';
    }
}

int main()
{
    submit();
    return 0;
}