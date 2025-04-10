#include <bits/stdc++.h>
using namespace std;


void submit()
{
    int n, m;
    cin >> n >> m;

    int A[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> A[i][j];
        }
        
    }
    
    int row_start = 0, row_end = n-1;
    int col_start = 0, col_end = m-1;

    while (row_start <= row_end && col_start <= col_end)
    {
        for (int i = col_start; i <= col_end; i++)
        {
            cout << A[row_start][i] << " ";
        }
        row_start++;

        for (int i = row_start; i <= row_end; i++)
        {
            cout << A[i][col_end] << " ";
        }
        col_end--;

        if (row_start <= row_end)
        {
            for (int i = col_end; i >= col_start; i--)
            {
                cout << A[row_end][i] << " ";
            }
            row_end--;
        }
        
        if (col_start <= col_end)
        {
            for (int i = row_end; i >= row_start; i--)
            {
                cout << A[i][col_start] << " ";
            }
            col_start++;
        }
        
    }
    

    
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