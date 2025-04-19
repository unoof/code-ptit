#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int n, count = 0;
    cin >> n;

    int A[n][n];
    vector<int> B(n*n);

    for (int i = 0; i < n*n; i++)
    {
        cin >> B[i];
    }
    
    sort(B.begin(), B.end());

    int row_start = 0, row_end = n-1;
    int col_start = 0, col_end = n-1;

    while (row_start <= row_end && col_start <= col_end)
    {
        for (int i = col_start; i <= col_end; i++)
        {
            A[row_start][i] = B[count];
            count++;
        }
        row_start++;

        for (int i = row_start; i <= row_end; i++)
        {
            A[i][col_end] = B[count];
            count++;
        }
        col_end--;

        if (row_start <= row_end)
        {
            for (int i = col_end; i >= col_start; i--)
            {
                A[row_end][i] = B[count];
                count++;
            }
            row_end--;
        }
        
        if (col_start <= col_end)
        {
            for (int i = row_end; i >= row_start; i--)
            {
                A[i][col_start] = B[count];
                count++;
            }
            col_start++;
        }
        
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl << endl;
    }
    
}


int main()
{
    ios::sync_with_stdio(false);                                    // Speed up input/output
    cin.tie(nullptr);
    cout.tie(nullptr);

    submit();

    return 0;
}