#include <bits/stdc++.h>
using namespace std;

void submit()
{
    long long n, k;
    cin >> n >> k;
    vector<long long> A(n);
    for (auto &&i : A)
    {
        cin >> i;
    }

    if (k < A[0])
    {
        cout << -1;
    }
    else
    {
        int save = upper_bound(A.begin(), A.end(), k) - A.begin();
        cout << save;
    }
    
    

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