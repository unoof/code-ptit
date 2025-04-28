#include <bits/stdc++.h>
using namespace std;

stack<int> spiral(vector<vector<int>> &A, int row_start, int row_end, int col_start, int col_end)
{
    stack<int> ans;

    while (row_start <= row_end && col_start <= col_end)
    {
        for (int i = row_start; i <= row_end; i++)
        {
            ans.push(A[i][col_start]);
        }
        col_start++;
        row_start++;

        for (int i = col_start; i <= col_end; i++)
        {
            ans.push(A[row_end][i]);
        }
        row_end--;
        col_start++;
        
        if (col_start <= col_end)
        {
            for (int i = row_end; i >= row_start; i--)
            {
                ans.push(A[i][col_end]);
            }
            col_end--;
            row_end--;
        }

        if (row_start <= row_end)
        {
            for (int i = col_end; i >= col_start; i--)
            {
                ans.push(A[row_start][i]);
            }
            row_start++;
            col_end--;
        }
    }

    return ans;
}

stack<int> rev_spiral(vector<vector<int>> &A, int row_start, int row_end, int col_start, int col_end)
{
    stack<int> ans;

    while (row_start <= row_end && col_start <= col_end)
    {
        for (int i = row_end; i >= row_start; i--)
        {
            ans.push(A[i][col_end]);
        }
        col_end--;
        row_end--;

        for (int i = col_end; i >= col_start; i--)
        {
            ans.push(A[row_start][i]);
        }
        row_start++;
        col_end--;
    
        if (col_start <= col_end)
        {
            for (int i = row_start; i <= row_end; i++)
            {
                ans.push(A[i][col_start]);
            }
            row_start++;
            col_start++;
        }

        if (row_start <= row_end)
        {
            for (int i = col_start; i <= col_end; i++)
            {
                ans.push(A[row_end][i]);
            }
            col_start++;
            row_end--;
        }
    }

    return ans;
}


void submit()
{
    int n;
    cin >> n;
    int temp = n*4, count = 1;

    vector<vector<int>> A(temp, vector<int> (temp));

    for (int i = 0; i < temp; i++)
    {
        for (int j = 0; j < temp; j++)
        {
            A[i][j] = count;
            count++;
        }
        
    }

    stack<int> ans_1;
    stack<int> ans_2;
    
    ans_1 = spiral(A, 0, temp-1, 0, temp-2);
    ans_2 = rev_spiral(A, 0, temp-1, 1, temp-1);

    while (!ans_2.empty())
    {
        cout << ans_2.top() << " ";
        ans_2.pop();
    }

    cout << endl;

    while (!ans_1.empty())
    {
        cout << ans_1.top() << " ";
        ans_1.pop();
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