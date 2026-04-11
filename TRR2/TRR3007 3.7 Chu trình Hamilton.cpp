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

void recursion(vector<vector<int>> &A, vector<bool> &visited, int n, int k, int index, vector<int> &ans, int &count, int step)
{
    if (step == n)
    {
        for (auto &&i : A[index])
        {
            if (i == k)
            {
                ans.push_back(k);
                out(ans);
                count++;
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
            recursion(A, visited, n, k, i, ans, count, step+1);
            ans.pop_back();
            visited[i] = false;
        }
    }
}

void submit()
{
    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);

    int n;
    cin >> n;
    int k;
    cin >> k;
    
    vector<vector<int>> A(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int hasEdge;
            cin >> hasEdge;
            if (hasEdge) A[i].push_back(j);
        }
    }
    
    vector<bool> visited(n, false);
    visited[k-1] = true;
    
    int count = 0;
    vector<int> ans = {k-1};
    recursion(A, visited, n, k-1, k-1, ans, count, 1);
    cout << count;
}

int main()
{
    submit();
    return 0;
}