#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void out(vector<int> &ans)
{
    for (auto &&i : ans)
    {
        cout << i+1 << " "; 
    }
    cout << '\n';
}

bool check(vector<bool> &visited)
{
    for (auto &&i : visited)
    {
        if (!i) return false;
    }
    return true;
}

void recursion(vector<vector<int>> &A, vector<bool> &visited, int n, int k, int index, vector<int> &ans, vector<vector<int>> &total, int step)
{
    if (step == n)
    {
        for (auto &&i : A[index])
        {
            if (i == k)
            {
                ans.push_back(k);
                total.push_back(ans);
                ans.pop_back();
                return;
            }
        }
        return;
    }
    

    for (auto &&i : A[index])
    {
        if (!visited[i])
        {
            ans.push_back(i);
            visited[i] = true;
            recursion(A, visited, n, k, i, ans, total, step+1);
            ans.pop_back();
            visited[i] = false;
        }
    }
}

void submit()
{
    // freopen("CT.INP", "r", stdin);
    // freopen("CT.OUT", "w", stdout);

    int n, m;
    cin >> n >> m;
    int k;
    cin >> k;
    
    vector<vector<int>> A(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        A[u-1].push_back(v-1);
        A[v-1].push_back(u-1);
    }
    
    vector<bool> visited(n, false);
    visited[k-1] = true;
    
    vector<vector<int>> total;
    vector<int> ans = {k-1};
    recursion(A, visited, n, k-1, k-1, ans, total, 1);

    cout << total.size() << '\n';
    for (auto &&i : total)
    {
        out(i);
    }
    
}

int main()
{
    submit();
    return 0;
}