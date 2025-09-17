#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (auto &&i : A)
    {
        cin >> i;
    }
    
    sort(A.begin(), A.end());

    long long first = 0, second = 0;
    k = min(k, n-k);

    for (int i = 0; i < n; i++)
    {
        if (i < k)
        {
            first += A[i];
        }
        else
        {
            second += A[i];
        }
    }
    
    cout << second-first;

    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);                                    // Speed up input/output
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test;
    cin >> test;
    while (test--)
    {
        submit();
    }
    

    return 0;
}