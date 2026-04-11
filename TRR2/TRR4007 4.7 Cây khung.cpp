#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge
{
    int u, v, w;
};

class DSU
{
    vector<int> parent;

public: 
    DSU(int n)
    {
        parent.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = -1;
        }
    }
    
    int find(int i)
    {
        if (parent[i] < 0) return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int x, int y)
    {
        int root1 = find(x), root2 = find(y);
        if (root1 != root2)
        {
            if (-parent[root1] > -parent[root2])
            {
                parent[root1] += parent[root2];
                parent[root2] = root1;
            }
            else
            {
                parent[root2] += parent[root1];
                parent[root1] = root2;
            }
        }
    }
};

bool cmp(edge &A, edge &B)
{
    if (A.w == B.w)
    {
        if (A.u == B.u)
        {
            return A.v < B.v;
        }
        return A.u < B.u;
    }
    return A.w < B.w;
}

void kruskal_algo(vector<edge> &edges, int n, vector<vector<int>> &A)
{
    sort(edges.begin(), edges.end(), cmp);

    DSU dsu(n);

    int cost = 0, count = 0;
    vector<pair<int, int>> ans;
    for (auto &&i : edges)
    {
        if (dsu.find(i.u) != dsu.find(i.v))
        {
            dsu.unite(i.u, i.v);
            cost += i.w;
            ans.push_back({i.u, i.v});
            if (++count == n-1) break;
        }
    }
    cout << cost << endl;
    for (auto &&i : ans)
    {
        cout << i.first+1 << " " << i.second+1 << " " << A[i.first][i.second] << endl;
    }
}

void submit()
{
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);

    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> A(n, vector<int>(n));
    vector<edge> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        A[u-1][v-1] = A[v-1][u-1] = w;
        edges.push_back({u-1, v-1, w});
    }
    

    kruskal_algo(edges, n, A);
}

int main()
{
    submit();
    return 0;
}