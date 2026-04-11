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
    cout << n << " " << edges.size() << endl;
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
    

    vector<pair<int,int>> edges;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int temp;
            cin >> temp;
            if (temp == 1)
            {
                edges.push_back({i, j});
            }
        }
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