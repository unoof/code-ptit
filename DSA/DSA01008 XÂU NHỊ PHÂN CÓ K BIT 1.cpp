#include <bits/stdc++.h>
using namespace std;

long long c(int k, int n)
{
    if (k > n)
    {
        return 0;
    }
    
    long long total = 1;
    for (int i = 1; i <= k; i++)
    {
        total *= (n-i+1);
        total /= i;
    }
    
    return total;
}

void update(vector<int> &A, int n)
{
    int i = n-2;
    while (A[i] >= A[i+1])
    {
        i--;
    }
    
    if (i < 0)
    {
        return;
    }
    
    int k = n-1;
    while (A[k] <= A[i])
    {
        k--;
    }
    
    swap(A[i], A[k]);
    reverse(A.begin() + i+1, A.end());
}

void submit()
{
    int n, k;
    cin >> n >> k;
    vector<int> A(n, 0);

    for (int i = k; i > 0; i--)
    {
        A[n-i] = 1;
    }
    
    for (int i = 0; i < c(k, n); i++)
    {
        for (auto &&i : A)
        {
            cout << i;
        }
        cout << endl;
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