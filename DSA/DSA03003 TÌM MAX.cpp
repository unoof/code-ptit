#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

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
    long long total = 0;

    for (int i = 0; i < n; i++)
    {
        total += (A[i]*i)%MOD;
    }
    
    cout << total%MOD;



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