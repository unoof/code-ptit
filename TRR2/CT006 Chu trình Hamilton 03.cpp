#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool check(vector<bool> &visited)
{
    for (auto &&i : visited)
    {
        if (!i) return false;
    }
    return true;
}

void recursion(vector<vector<pair<int,int>>> &edges, vector<bool> &visited, int n, int k, int index, pair<int,vector<int>> &ans, pair<int,vector<int>> &total, int step, bool &check)
{
    if (step == n)
    {
        for (auto &&i : edges[index])
        {
            if (i.first == k)
            {
                ans.second.push_back(k);
                ans.first += i.second;

                if (ans.first < total.first)
                {
                    total = ans;
                    check = true;
                }

                ans.second.pop_back();
                ans.first -= i.second;
                return;
            }
        }
        return;
    }
    

    for (auto &&i : edges[index])
    {
        if (!visited[i.first])
        {
            ans.second.push_back(i.first);
            ans.first += i.second;
            visited[i.first] = true;

            recursion(edges, visited, n, k, i.first, ans, total, step+1, check);

            ans.second.pop_back();
            ans.first -= i.second;
            visited[i.first] = false;
        }
    }
}

void submit()
{
    // freopen("CT.INP", "r", stdin);
    // freopen("CT.OUT", "w", stdout);

    int n;
    cin >> n;
    int k;
    cin >> k;
    
    vector<vector<int>> A(n, vector<int>(n));
    vector<vector<pair<int,int>>> edges(n, vector<pair<int,int>>());
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];

            if (A[i][j] != 10000 && A[i][j] != 0)
            {
                edges[i].push_back({j, A[i][j]});
            }
        }   
    }
    
    vector<bool> visited(n, false);
    visited[k-1] = true;
    
    bool check = false;
    pair<int,vector<int>> maxi = {1000000000, {0}};
    pair<int,vector<int>> ans = {0, {k-1}};
    recursion(edges, visited, n, k-1, k-1, ans, maxi, 1, check);

    
    if (!check)
    {
        cout << 0;
        return;
    }
    
    cout << maxi.first << '\n';
    for (auto &&i : maxi.second)
    {
        cout << i+1 << " ";
    }
}

int main()
{
    submit();
    return 0;
}