#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct vertex
{
    int w, u, p;
};

struct cmp
{
    bool operator()(vertex &A, vertex &B)
    {
        if (A.w == B.w)
        {
            return A.u > B.u;
        }
        return A.w > B.w;
    }
};

void dijkstra_algo(vector<vector<int>> &A, int n, int start, int end)
{
    vector<vertex> explored(n);
    priority_queue<vertex, vector<vertex>, cmp> unexplored;
    vector<int> d(n, 10000);

    unexplored.push({0, start, start});
    d[start] = 0;
    
    while (!unexplored.empty())
    {
        vertex temp = unexplored.top();
        unexplored.pop();
        int w = temp.w;
        int u = temp.u;

        if (w > d[u]) continue;
        explored[u] = temp;

        for (int i = 0; i < n; i++)
        {
            if (A[u][i] != 0 && d[i] > w + A[u][i])
            {
                d[i] = w + A[u][i];
                unexplored.push({d[i], i, u});
            }
        }
        
    }

    if (d[end] == 10000)
    {
        cout << 0 << endl;
        return;
    }
    else
    {
        cout << d[end] << "\n";
    }
    vector<int> ans;
    int f = end;
    do
    {
        ans.push_back(explored[f].u+1);
        f = explored[f].p;
    }
    while (explored[f].p != explored[f].u);
    ans.push_back(explored[f].u+1);

    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i] << " ";
    }
}

void submit()
{
    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);

    int n;
    cin >> n;

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

    dijkstra_algo(A, n, start-1, end-1);
}

int main()
{
    submit();
    return 0;
}