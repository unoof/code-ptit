#include <bits/stdc++.h>
using namespace std;

void update(string &A, int n)
{
    for (int i = n-1; i >= 0; i--)
    {
        if (A[i] == 'A')
        {
            A[i] = 'H';
            return;
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

bool check(string A, int n)
{
    if (A[0] == 'A' || A[n-1] == 'H')
    {
        return false;
    }
    
    bool alr_H = true;

    for (int i = 1; i < n; i++)
    {
        if (A[i] == 'H')
        {
            if (alr_H)
            {
                return false;
            }
            alr_H = true;
        }
        else
        {
            alr_H = false;
        }
    }
    return true;
}

void submit()
{
    int n;
    cin >> n;
    string A;
    for (int i = 0; i < n; i++)
    {
        A += 'A';
    }
    
    int total = maximum(n);
    for (int i = 0; i < total; i++)
    {
        if (check(A, n))
        {
            for (auto &&j : A)
            {
                cout << j;
            }
            cout << endl;
        }
        update(A, n);
    }
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