#include <bits/stdc++.h>
using namespace std;

long long c(int n, int k)
{
    int total = 1;
    for (int i = 1; i <= k; i++)
    {
        total *= n-i+1;
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
    if (i < 0)
    {
        return;
    }
    
    A[i]++;
    for (int j = i+1; j < k; j++)
    {
        A[j] = A[i]+j-i;
    }
    
}

void submit()
{
    int n, k;
    cin >> n >> k;
    set<int> A;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        A.insert(temp);
    }
    vector<int> B(A.begin(), A.end());
    vector<int> C(k);

    for (int i = 0; i < k; i++)
    {
        C[i] = i+1;
    }
    
    n = A.size();
    int total = c(n, k);

    for (int i = 0; i < total; i++)
    {
        for (auto &&i : C)
        {
            cout << B[i-1] << " ";
        }
        cout << endl;
        update(C, n, k);
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