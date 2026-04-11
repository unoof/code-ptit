#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct edge
{
    int w, u, v;
};

class cmp
{
public:
    bool operator()(edge a, edge b)
    {
        if (a.w == b.w)
        {
            if (a.u == b.u)
            {
                return a.v > b.v;
            }
            return a.u > b.u;
        }
        return a.w > b.w;
    }
};

void prim_algo(vector<vector<int>> &A, int n, int start)
{
    priority_queue<edge, vector<edge>, cmp> pq;

    pq.push({0, start, start});
    int cost = 0, edges_count = 0;
    vector<bool> visited(n, false);
    vector<pair<int,int>> ans;

    while (!pq.empty())
    {
        int w = pq.top().w;
        int u = pq.top().u;
        int v = pq.top().v;
        pq.pop();

        if (visited[v])
        {
            continue;
        }
        else
        {
            if (v != u) ans.push_back({u, v});
            visited[v] = true;
            cost += w;
    
            for (int i = 0; i < n; i++)
            {
                if (A[v][i] != 0 && !visited[i])
                {
                    pq.push({A[v][i], v, i});
                }
            }
        }
    }

    cout << cost << endl;
    for (auto &&i : ans)
    {
        cout << min(i.first, i.second)+1 << " " << max(i.first ,i.second)+1 << " " << A[i.first][i.second] << endl;
    }
    
}

void submit()
{
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);

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

    prim_algo(A, n, k-1);
}

int main()
{
    submit();
    return 0;
}