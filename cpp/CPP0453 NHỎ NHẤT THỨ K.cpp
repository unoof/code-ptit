#include <bits/stdc++.h>
using namespace std;


void submit()
{
    int n, k;
    cin >> n >> k;
    vector<long long> A(n);

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    
    sort(A.begin(), A.end());
    cout << A[k-1];
    
    
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