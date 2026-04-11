#include <bits/stdc++.h>
using namespace std;

struct vertex
{
    int w, u, v;
};


void bellman_ford_algo(vector<vertex> &edges, int n, int start, int end, ofstream &f2)
{
    vector<int> d(n, 10000);
    vector<int> p(n, -1);
    d[start] = 0;
    p[start] = start;

    for (int i = 0; i < n-1; i++)
    {
        bool check = false;
        for (auto &&j : edges)
        {
            if (d[j.u] != 10000 && d[j.v] > j.w + d[j.u])
            {
                d[j.v] = j.w + d[j.u];
                p[j.v] = j.u;
                check = true;
            }
        }
        
        if (!check) break;
    }

    bool check = false;
    for (auto &&j : edges)
    {
        if (d[j.u] != 10000 && d[j.v] > j.w + d[j.u])
        {
            d[j.v] = j.w + d[j.u];
            p[j.v] = j.u;
            check = true;
        }
    }

    if (!check)
    {
        if (d[end] != 10000)
        {
            f2 << d[end] << endl;
            vector<int> s;
            int temp = end;
            do 
            {
                s.push_back(end+1);
                end = p[end];
            } while (p[end] != end);
            s.push_back(p[end]+1);
            for (int i = s.size() - 1; i >= 0; i--)
            {
                f2 << s[i] << " ";
            }
            
        }
        else
        {
            f2 << 0;
        }
    }
    else
    {
        f2 << -1;
    }
}

void submit()
{
    ifstream f1("BN.INP");
    ofstream f2("BN.OUT");
    if (!f1) return;
    int n;
    f1 >> n;

    int start, end;
    f1 >> start >> end;
    
    vector<vector<int>> A(n, vector<int>(n));
    vector<vertex> edges;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            f1 >> A[i][j];
            if (A[i][j] != 0)
            {
                edges.push_back({A[i][j], i, j});
            }
        }
    }

    bellman_ford_algo(edges, n, start-1, end-1, f2);
    f1.close(); f2.close();
}

int main()
{
    submit();
    return 0;
}