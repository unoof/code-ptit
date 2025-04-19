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
    int prev, save;

    while (row_start <= row_end && col_start <= col_end)
    {
        int layer_row_start = row_start;
        int layer_col_start = col_start;
        prev = A[row_start][col_start];

        for (int i = col_start; i <= col_end; i++)
        {
            save = A[row_start][i];
            A[row_start][i] = prev;
            prev = save;
        }
        row_start++;

        for (int i = row_start; i <= row_end; i++)
        {
            save = A[i][col_end];
            A[i][col_end] = prev;
            prev = save;
        }
        col_end--;

        if (row_start <= row_end)
        {
            for (int i = col_end; i >= col_start; i--)
            {
                save = A[row_end][i];
                A[row_end][i] = prev;
                prev = save;
            }
            row_end--;
        }
        
        if (col_start <= col_end)
        {
            for (int i = row_end; i >= row_start; i--)
            {
                save = A[i][col_start];
                A[i][col_start] = prev;
                prev = save;
            }
            col_start++;
        }

        A[layer_row_start][layer_col_start] = prev;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << A[i][j] << " ";
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

    while (so_bo_test--)
    {
        submit();
    }

    return 0;
}