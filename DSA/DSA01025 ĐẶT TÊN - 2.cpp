#include <bits/stdc++.h>
using namespace std;

void update(vector<int> &A, int n, int k)
{
    int i = k-1;
    while (A[i] == n-k+i+1)
    {
        i--;
    }
    
    if (i == -1)
    {
        return;
    }
    
    A[i]++;
    for (int j = i+1; j < k; j++)
    {
        A[j] = A[i]+j-i;
    }
}

long long max(int n, int k)
{
    long long total = 1;
    for (int i = 1; i <= k; i++)
    {
        total *= n-i+1;
        total /= i;
    }
    return total;
}

void submit()
{
    int n, k;
    cin >> n >> k;

    vector<int> A(k);
    for (int i = 0; i < k; i++)
    {
        A[i] = i+1;
    }
    
    for (int i = 0; i < max(n, k); i++)
    {
        for (auto &&i : A)
        {
            cout << char(i+'A'-1);
        }
        cout << endl;
        update(A, n, k);
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