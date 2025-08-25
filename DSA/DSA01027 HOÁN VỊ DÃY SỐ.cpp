#include <bits/stdc++.h>
using namespace std;

void update(vector<int> &A, int n)
{
    int i = n-2;
    while (A[i] > A[i+1])
    {
        i--;
    }
    
    if (i >= 0)
    {
        int k = n-1;
        while (A[k] < A[i])
        {
            k--;
        }
        swap(A[i], A[k]);
        reverse(A.begin()+i+1, A.end());
    }
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
    for (auto &&i : A)
    {
        cin >> i;
    }
    sort(A.begin(), A.end());

    for (int i = 0; i < p(n); i++)
    {
        for (auto &&i : A)
        {
            cout << i << " ";
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

    submit();

    return 0;
}