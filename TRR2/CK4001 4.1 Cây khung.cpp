#include <bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>> &A, vector<bool> &visited, int n, int start)
{
    vector<pair<int,int>> ans;
    stack<int> save;
    save.push(start);
    visited[start] = true;
    
    while (save.size() > 0)
    {
        int temp = save.top();
        bool check = false;

        for (int i = 0; i < n; i++)
        {
            if (A[temp][i] == 1 && !visited[i])
            {
                ans.push_back({temp+1, i+1});

                save.push(i);
                visited[i] = true;
                check = true;
                break;
            }
        }
        if (!check) save.pop();
    }
    if (ans.size() == n-1)
    {
        cout << n-1 << endl;
        for (auto &&i : ans)
        {
            cout << i.first << " " << i.second << endl;
        }
    }
    else
    {
        cout << 0;
    }
    
}

void BFS(vector<vector<int>> &A, vector<bool> &visited, int n, int start)
{
    vector<pair<int,int>> ans;
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
                ans.push_back({temp+1, i+1});
                
                save.push(i);
                visited[i] = true;
            }
        }
    }
    if (ans.size() == n-1)
    {
        cout << n-1 << endl;
        for (auto &&i : ans)
        {
            cout << i.first << " " << i.second << endl;
        }
    }
    else
    {
        cout << 0 << endl;
    }

}

void submit()
{
    int temp;
    cin >> temp;
    int n, k;
    cin >> n >> k;
    
    vector<vector<int>> A(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    }
    
    vector<bool> visited(n, false);
    
    if (temp == 1)
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