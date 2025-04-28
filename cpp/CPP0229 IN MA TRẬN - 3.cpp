#include <bits/stdc++.h>
using namespace std;

vector<int> ans(vector<vector<int>> A, int row_start, int row_end, int col_start, int col_end)
{
    vector<int> ans;
    
    ans.push_back(A[row_start][col_start]);

    while (row_start != row_end || col_start != col_end)
    {        
        if (row_start == 0 && col_start != col_end)
        {
            col_start++;
            ans.push_back(A[row_start][col_start]);

            while (col_start != 0 && row_start != row_end)
            {
                row_start++;
                col_start--;
                ans.push_back(A[row_start][col_start]);
            }
        
        }
        
        if (col_start == 0 && row_start != row_end)
        {
            row_start++;
            ans.push_back(A[row_start][col_start]);

            while (row_start != 0 && col_start != col_end)
            {
                row_start--;
                col_start++;
                ans.push_back(A[row_start][col_start]);
            }
        
        }
        
        if (row_start == row_end && col_start != col_end)
        {
            col_start++;
            ans.push_back(A[row_start][col_start]);

            while (row_start != 0 && col_start != col_end)
            {
                row_start--;
                col_start++;
                ans.push_back(A[row_start][col_start]);
            }
        
        }
        
        if (row_start != row_end && col_start == col_end)
        {
            row_start++;
            ans.push_back(A[row_start][col_start]);

            while (col_start != 0 && row_start != row_end)
            {
                row_start++;
                col_start--;
                ans.push_back(A[row_start][col_start]);
            }
        
        }
    }

    
    return ans;
}

void submit()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> A(n, vector<int> (m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> A[i][j];
        }
    }
    
    int row_start = 0, row_end = n-1;
    int col_start = 0, col_end = m-1;

    vector<int> out = ans(A, row_start, row_end, col_start, col_end);

    for (auto &&i : out)
    {
        cout << i << " ";
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