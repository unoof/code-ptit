#include <bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>> &A, vector<bool> visited, int n, int start)
{
    stack<int> save;
    save.push(start);
    visited[start] = true;
    vector<pair<int,int>> ans;
    
    while (save.size() > 0)
    {
        int temp = save.top();
        save.pop();
        
        for (int i = 0; i < n; i++)
        {
            if (A[temp][i] == 1 && !visited[i])
            {
                ans.push_back({min(i, temp)+1, max(i, temp)+1});
                save.push(temp);
                save.push(i);
                visited[i] = true;
                break;
            }
        }
    }

    cout << ans.size() << '\n';
    for (auto &&i : ans)
    {
        cout << i.first << " " << i.second << '\n';
    }
}

void BFS(vector<vector<int>> &A, vector<bool> &visited, int n, int start)
{
    queue<int> save;
    save.push(start);
    visited[start] = true;
    vector<pair<int,int>> ans;
    
    while (save.size() != 0)
    {
        int temp = save.front();
        save.pop();
        
        for (int i = 0; i < n; i++)
        {
            if (A[temp][i] == 1 && !visited[i])
            {
                ans.push_back({min(i, temp)+1, max(i, temp)+1});
                save.push(i);
                visited[i] = true;
            }
        }
    }

    cout << ans.size() << '\n';
    for (auto &&i : ans)
    {
        cout << i.first << " " << i.second << '\n';
    }

}

void submit()
{
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);

    int option;
    cin >> option;

    int n;
    cin >> n;
    int k;
    cin >> k;
    
    vector<vector<int>> A(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    }
    
    vector<bool> visited(n, false);
    
    if (option == 1)
    {
        DFS(A, visited, n, k-1);
    }
    else
    {
        BFS(A, visited, n, k-1);
    }
}

int main()
{
    submit();
    return 0;
}