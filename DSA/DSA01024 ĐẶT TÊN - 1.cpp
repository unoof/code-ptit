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

void update(vector<int> &A, int n, int k)
{
    int i = k-1;
    while (A[i] == n-k+i+1)
    {
        i--;
    }

    A[i]++;

    if (i == -1)
    {
        return;
    }

    for (int j = i+1; j < k; j++)
    {
        A[j] = A[i]+j-i;
    }
}

void submit()
{
    int n, k;
    cin >> n >> k;
    set<string> A;
    
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        A.insert(temp);
    }
    n = A.size();
    vector<string> B(A.begin(), A.end());
    vector<int> temp(k);

    for (auto &&i : temp)
    {
        i = i+1;
    }
    
    
    for (int i = 0; i < c(k, n); i++)
    {
        update(temp, n, k);
        for (auto &&i : temp)
        {
            cout << B[i-1] << " ";
        }
        cout << endl;
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