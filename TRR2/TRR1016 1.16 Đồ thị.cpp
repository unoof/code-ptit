#include <bits/stdc++.h>
using namespace std;

void option1(vector<pair<int,int>> &edges, int n)
{
    vector<pair<int,int>> A(n, {0,0});
    for (auto &&i : edges)
    {
        A[i.first].first++;
        A[i.second].second++;
    }
    
    for (auto &&i : A)
    {
        cout << i.second << " " << i.first << endl;
    }
}

void option2(vector<pair<int,int>> &edges, int n)
{
    vector<vector<int>> A(n, vector<int>());

    for (auto &&i : edges)
    {
        A[i.first].push_back(i.second);
    }
    
    cout << n << endl;
    for (int i = 0; i < n; i++)
    {
        cout << A[i].size() << " ";
        for (auto &&j : A[i])
        {
            cout << j+1 << " ";
        }
        cout << endl;
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
    vector<pair<int,int>> edges;
    for (int i = 0; i < k; i++)
    {
        int u, v;
        cin >> u >> v;
        edges.push_back({u-1,v-1});
    }
    
    
    
    

    if (s == 1)
    {
        option1(edges, n);
    }
    else
    {
        option2(edges, n);
    }
}

int main()
{
    submit();
    return 0;
}