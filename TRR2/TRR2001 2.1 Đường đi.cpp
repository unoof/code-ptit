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

bool option2(vector<vector<int>> &edges, int n, int start, int end, vector<int> &ans, vector<bool> &visited)
{
    if (start == end)
    {
        return true;
    }
    
    for (auto &&i : edges[start])
    {
        if (!visited[i])
        {
            visited[i] = true;
            ans.push_back(i);

            bool check = option2(edges, n, i, end, ans, visited);
            if (check) return true;

            visited[i] = false;
            ans.pop_back();
        }
    }
    return false;
}


void submit()
{
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    
    int n, s;
    cin >> s >> n;
    

    int start, end;
    cin >> start >> end;
    vector<vector<int>> edges(n, vector<int>());
    vector<vector<int>> A(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
            if (A[i][j] == 1) edges[i].push_back(j);
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
        bool check = option2(edges, n, start-1, end-1, ans, visited);
        
        if (check)
        {
            for (auto &&i : ans)
            {
                cout << i+1 << " ";
            }
        }
        else
        {
            cout << 0;
        }
    }
}

int main()
{
    submit();
    return 0;
}