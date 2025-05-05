#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int n, count = 0;
    cin >> n;

    vector<vector<int>> A(n, vector<int> (n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
        
    }
    
    vector<int> check(100000, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (check[A[i][j]] == i)
            {
                check[A[i][j]]++;
            }
        }
    }
    
    for (int i = 0; i < 100000; i++)
    {
        if (check[i] == n)
        {
            count++;
        }
    }
    
    cout << count;

    cout << endl;
}



int main()
{
    ios::sync_with_stdio(false);                                    // Speed up input/output
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