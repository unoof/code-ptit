#include <bits/stdc++.h>
using namespace std;

void option1(vector<vector<int>> &A, int n, int start, int end, int &count)
{
    for (int i = 0; i < n; i++)
    {
        if (A[start][i] && A[i][end])
        {
            count++;
        }
    }
}

vector<int> BFS(vector<vector<int>> &A, int n, int start, int end)
{
    queue<vector<int>> save;
    vector<int> visited(n, false);
    save.push({start});
    visited[start] = true;
    
    while (save.size() != 0)
    {
        vector<int> temp = save.front();
        save.pop();
        
        if (A[temp[temp.size()-1]][end] == 1)
        {
            temp.push_back(end);
            return temp;
        }
        
        for (int i = 0; i < n; i++)
        {
            if (A[temp[temp.size()-1]][i] == 1 && !visited[i])
            {
                temp.push_back(i);
                save.push(temp);
                temp.pop_back();
                visited[i] = true;
            }
        }
    }
    return {-1};
}


void submit()
{
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    
    int n, s;
    cin >> s >> n;
    

    int start, end;
    cin >> start >> end;
    vector<vector<int>> A(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    }
    
    




    vector<int> ans = {start-1};
    vector<bool> visited(n, false);
    visited[start-1] = true;
    if (s == 1)
    {
        int count = 0;
        option1(A, n, start-1, end-1, count);
        cout << count;
    }
    else
    {
        vector<int> ans = BFS(A, n, start-1, end-1);
        
        for (auto &&i : ans)
        {
            cout << i+1 << " ";
        }
    }
}

int main()
{
    submit();
    return 0;
}