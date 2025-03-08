#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int n, m;
    cin >> n >> m;

    vector<vector<bool>> A(n, vector<bool>(m));
    vector<pair<int,int>> store;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int temp;
            cin >> temp;
            A[i][j] = temp;

            if (A[i][j] == 1)
            {
                store.push_back({i, j});
            }
        }
    }


    for (auto [row, col] : store)
    {
        for (int j = 0; j < m; j++) A[row][j] = 1;
        for (int i = 0; i < n; i++) A[i][col] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << A[i][j] << " ";            
        }
        cout << endl;
    }
    
    
    

    return;
}


int main()
{
    ios::sync_with_stdio(false);                                    // Speed up input/output
    cin.tie(nullptr);
    cout.tie(nullptr);

    int so_bo_test;
    cin >> so_bo_test;


    while (so_bo_test--)
    {
        submit();
    }

    return 0;
}