#include <bits/stdc++.h>
using namespace std;


vector<int> DFS(vector<vector<int>> &A, int n, int index)
{
    stack<int> save;
    vector<int> ans;

    save.push(index);
    
    
    while (save.size() != 0)
    {
        int temp = save.top();
        bool check = false;
        
        for (int i = 0; i < n; i++)
        {
            if (A[temp][i] == 1)
            {
                save.push(i);
                A[temp][i] = 0;
                check = true;
                break;
            }
        }
        if (!check)
        {
            save.pop();
            ans.push_back(temp);
        }
    }
    return ans;
}

void recursion(vector<vector<int>> &idk, vector<bool> &visited, int n, int temp)
{
    visited[temp] = true;
    for (int i = 0; i < n; i++)
    {
        if (idk[temp][i] == 1 && !visited[i])
        {
            recursion(idk, visited, n, i);
        }
    }
}

void submit()
{
    // freopen("CT.INP", "r", stdin);
    // freopen("CT.OUT", "w", stdout);

    int option;
    cin >> option;
    int n;
    cin >> n;
    int k;
    if (option == 2) cin >> k;
    
    vector<vector<int>> A(n, vector<int>(n, 0));
    vector<pair<int,int>> deg(n, {0,0});
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        for (int j = 0; j < temp; j++)
        {
            int v;
            cin >> v;
            A[i][v-1] = 1;
        }
    }
    
    
    vector<int> ans;
    
    if (option == 1)
    {
        vector<vector<int>> idk(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (A[i][j] == 1)
                {
                    idk[i][j] = idk[j][i] = 1;
                    deg[i].first++;
                    deg[j].second++;
                }
            }
        }
        vector<bool> visited(n, false);
        recursion(idk, visited, n, 0);
        for (auto &&i : visited)
        {
            if (!i)
            {
                cout << 0;
                return;
            }
        }
        

        int deg_1 = 0, deg_2 = 0;
        bool check = true;

        for (int i = 0; i < n; i++)
        {
            if (deg[i].first != deg[i].second)
            {
                if (deg[i].first - deg[i].second == 1)
                {
                    deg_1++;
                }
                else if (deg[i].second - deg[i].first == 1)
                {
                    deg_2++;
                }
                else
                {
                    check = false;
                    break;
                }
            }
        }

        if (!check)
        {
            cout << 0;
        }
        else if (deg_1 == 0 && deg_2 == 0)
        {
            cout << 1;
        }
        else if (deg_1 == 1 && deg_2 == 1)
        {
            cout << 2;
        }
        else
        {
            cout << 0;
        }
    }
    else
    {
        ans = DFS(A, n, k-1);
        
        for (int i = (int)ans.size() - 1; i >= 0; i--)
        {
            cout << ans[i]+1 << " ";
        }
    }
}

int main()
{
    submit();
    return 0;
}