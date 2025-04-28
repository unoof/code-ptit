#include <bits/stdc++.h>
using namespace std;


void submit()
{
    int n, k, x;
    cin >> n;
    
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    
    cin >> x >> k;

    sort(A.begin(), A.end());

    auto index = lower_bound(A.begin(), A.end(), k);

    int start = -(x/2);
    int end = x/2;

    for (int i = start; i <= end; i++)
    {
        if (i != 0)
        {
            cout << A[index - A.begin() + i] << " ";
        }
    }
    
    
    
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