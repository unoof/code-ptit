#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int u, v, w;
};

void option1(vector<edge> &edges, int n, int k)
{
    vector<pair<int,int>> A(n, {0,0});
    for (int i = 0; i < k; i++)
    {
        if (edges[i].w != 10000 && edges[i].w != 0)
        {
            A[edges[i].u].first++;
            A[edges[i].v].second++;
        }
    }
    
    
    for (auto &&i : A)
    {
        cout << i.second << " " << i.first << endl;
    }
}

void option2(vector<edge> &edges, int n, int k)
{
    vector<vector<int>> A(n, vector<int>(n, 10000));

    for (int i = 0; i < k; i++)
    {
        A[edges[i].u][edges[i].v] = edges[i].w;
    }

    for (int i = 0; i < n; i++)
    {
        A[i][i] = 0;
    }
    
    cout << n << "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << '\n';
    }
}

void submit()
{
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    
    int n, s;
    cin >> s >> n;
    

    int k;
    cin >> k;
    vector<edge> edges;
    for (int i = 0; i < k; i++)
    {
        int u ,v, w;
        cin >> u >> v >> w;
        edges.push_back({u-1,v-1,w});
    }
    
    
    
    

    if (s == 1)
    {
        option1(edges, n, k);
    }
    else
    {
        option2(edges, n, k);
    }
}

int main()
{
    submit();
    return 0;
}