#include <bits/stdc++.h>
using namespace std;

void option1(vector<vector<int>> &edges, int n)
{
    vector<pair<int,int>> A(n, {0,0});
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (edges[i][j] != 10000 && edges[i][j] != 0)
            {
                A[i].first++;
                A[j].second++;
            }
        }
    }
    
    
    for (auto &&i : A)
    {
        cout << i.second << " " << i.first << endl;
    }
}

void option2(vector<vector<int>> &edges, int n, int count)
{
    vector<pair<int,int>> A(count);

    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (edges[i][j] != 10000 && edges[i][j] != 0)
            {
                A[k].first = i;
                A[k].second = j;
                k++;
            }
        }
    }

    cout << n << " " << count << endl;
    for (auto &&i : A)
    {
        cout << i.first+1 << " " << i.second+1 << " " << edges[i.first][i.second] << endl;
    }
    
}

void submit()
{
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    int n, s;
    cin >> s >> n;
    

    int count = 0;
    vector<vector<int>> edges(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> edges[i][j];

            if (edges[i][j] != 10000 && edges[i][j] != 0) count++;
        }
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