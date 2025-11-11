#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto &&i : A) cin >> i;
    
    sort(A.begin(), A.end());

    int mini = INT32_MAX;

    for (int i = 0; i < n-1; i++)
    {
        if (mini > A[i+1] - A[i])
        {
            mini = A[i+1] - A[i];
        }
    }
    
    cout << mini;

    cout << endl;
}


int main()
{
    ios::sync_with_stdio(false);                                    // Speed down input/output
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