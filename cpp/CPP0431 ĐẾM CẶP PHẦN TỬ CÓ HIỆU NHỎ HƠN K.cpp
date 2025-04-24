#include <bits/stdc++.h>
using namespace std;


void submit()
{
    long long n, k;
    cin >> n >> k;

    vector<long long> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    
    sort(A.begin(), A.end());
    long long count = 0;

    int j = 0;

    for (int i = 0; i < n; i++)
    {
        if (j <= i)
        { 
            j = i + 1;
        }

        while (j < n && A[j] < A[i] + k) 
        {
            j++;
        }

        count += (j - i - 1);
    }
    
    cout << count;
    
    
    
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