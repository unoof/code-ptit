#include <bits/stdc++.h>
using namespace std;

set<int> BFS(vector<vector<int>> &A, vector<bool> &visited, int n, int start)
{
    queue<int> save;
    save.push(start);
    visited[start] = true;
    set<int> ans;
    ans.insert(start);
    
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
                ans.insert(i);
            }
        }
    }
    return ans;
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
    
    int count = 0;
    vector<set<int>> ans;
    vector<bool> visited(n, false);
    
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            count++;
            ans.push_back(BFS(A, visited, n, i));
        }
    }

    cout << count << '\n';
    for (auto &&i : ans)
    {
        for (auto &&j : i)
        {
            cout << j+1 << " ";
        }
        cout << '\n';
    }
}

int main()
{
    submit();
    return 0;
}