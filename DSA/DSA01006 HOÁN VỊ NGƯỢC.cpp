#include <bits/stdc++.h>
using namespace std;

void update(vector<int> &A, int n)
{
    int i = n-2;
    while (A[i] < A[i+1])
    {
        i--;
    }

    if (i < 0)
    {
        return;
    }
    
    int k = n-1;
    while (A[i] < A[k])
    {
        k--;
    }
    
    swap(A[i], A[k]);
    sort(A.begin()+i+1, A.end(), greater<int>());
}

long long p(int n)
{
    long long total = 1;
    for (int i = 1; i <= n; i++)
    {
        total *= i;
    }
    return total;
}

void submit()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        A[i] = n-i;
    }
    
    int total = p(n);
    for (int i = 0; i < total; i++)
    {
        for (auto &&j : A)
        {
            cout << j;
        }
        cout << " ";
        update(A, n);
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