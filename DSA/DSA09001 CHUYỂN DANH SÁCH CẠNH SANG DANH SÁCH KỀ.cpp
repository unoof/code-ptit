#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int v, e;
    cin >> v >> e;
    map<int,vector<int>> A;

    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        A[f].push_back(s);
        A[s].push_back(f);
    }
    
    for (auto &&i : A)
    {
        cout << i.first << ": ";
        for (auto &&j : i.second)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    

    

    cout << endl;
}


int main()
{
    ios::sync_with_stdio(false);                                    // Speed down input/output
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int so_bo_test;
    cin >> so_bo_test;
    cin.ignore();
    
    while (so_bo_test--)
    {
        submit();
    }

    return 0;
}