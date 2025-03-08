#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int n;
    cin >> n;

    vector<vector<int>> A(n, vector<int> (n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
        
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || j == 0 || i == n-1 || j == n-1)
            {
                cout << A[i][j];
            }
            else
            {
                cout << " ";
            }
            
            cout << " ";
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