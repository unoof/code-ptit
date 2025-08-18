#include <bits/stdc++.h>
using namespace std;

void update(string &A)
{
    for (int i = A.size() - 1; i >= 0; i--)
    {
        if (A[i] == 'A')
        {
            A[i] = 'B';
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
        for (auto &&j : A)
        {
            cout << j;
        }
        cout << " ";
        update(A);
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