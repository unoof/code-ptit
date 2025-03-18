#include <bits/stdc++.h>
using namespace std;


void submit()
{
    int n;
    cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    
    sort(A.begin(), A.end());

    if (n%2 == 0)
    {
        for (int i = 0; i < n/2; i++)
        {
            if (i != n-i-1)
            {
                cout << A[n-i-1] << " " << A[i] << " ";
            }
            else
            {
                cout << A[i] << " ";
            }
        }
    }
    else
    {
        for (int i = 0; i <= n/2; i++)
        {
            if (i != n-i-1)
            {
                cout << A[n-i-1] << " " << A[i] << " ";
            }
            else
            {
                cout << A[i] << " ";
            }
        }
    }
    
    
    
    cout << endl;
    return;
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