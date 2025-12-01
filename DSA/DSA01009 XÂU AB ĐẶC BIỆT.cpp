#include <bits/stdc++.h>
using namespace std;

void next(vector<char> &A, int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        if (A[i] == 'A')
        {
            A[i] = 'B';
            break;
        }
        A[i] = 'A';
    }
}

long long maximum(int n)
{
    long long total = 1;
    for (int i = 1; i <= n; i++)
    {
        total *= 2;
    }
    return total;
}

void submit()
{
    int n, k;
    cin >> n >> k;

    vector<char> A(n, 'A');
    vector<vector<char>> ans;

    for (int i = 0; i < maximum(n); i++)
    {
        bool check = false;
        int count = 0;
        for (auto &&j : A)
        {
            if (j == 'A')
            {
                count++;
                check = true;
            }
            else if (j == 'B' && check)
            {
                if (count == k)
                {
                    break;
                }
                else if (count != k)
                {
                    count = 0;
                    check = false;
                }
            }
        }
        
        if (count == k)
        {
            ans.push_back(A);
        }
        next(A, n);
    }
    
    cout << ans.size() << endl;
    for (auto &&i : ans)
    {
        for (auto &&j : i)
        {
            cout << j;
        }
        cout << endl;
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