#include <bits/stdc++.h>
using namespace std;

void solution(vector<bool> &cols, vector<bool> &diagonal_main, vector<bool> &diagonal_rev, int &n, int &times, int row)
{
    if (row == n)
    {
        times++;
        return;
    }
    
    for (int col = 0; col < n; col++)
    {
        if (!cols[col] && !diagonal_main[col-row+n-1] && !diagonal_rev[col+row])
        {
            cols[col] = diagonal_main[col-row+n-1] = diagonal_rev[col+row] = true;

            solution(cols, diagonal_main, diagonal_rev, n, times, row+1);
            cols[col] = diagonal_main[col-row+n-1] = diagonal_rev[col+row] = false;
        }
    }
}

void submit()
{
    int n, times = 0;
    cin >> n;
    
    vector<bool> cols(n, false);
    vector<bool> diagonal_main(2*n-1, false);
    vector<bool> diagonal_rev(2*n-1, false);
    
    solution(cols, diagonal_main, diagonal_rev, n, times, 0);
    
    cout << times << endl;
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