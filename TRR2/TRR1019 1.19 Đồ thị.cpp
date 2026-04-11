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

void option2(vector<pair<int,int>> &edges, int n, int count)
{
    cout << n << " " << count << endl;
    for (auto &&i : edges)
    {
        cout << i.first+1 << " " << i.second+1 << endl;
    }
}

void submit()
{
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    int n, s;
    cin >> s >> n;
    

    int count = 0;
    vector<pair<int,int>> edges;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int v;
            cin >> v;
            edges.push_back({i, v-1});
        }
        count += k;
    }
    
    
    
    

    if (s == 1)
    {
        option1(edges, n);
    }
    else
    {
        option2(edges, n, count);
    }
}

int main()
{
    submit();
    return 0;
}