#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int n;
    cin >> n;

    vector<long long> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    
    long long max_now = A[0];

    for (int i = 0; i < n; i++)
    {
        long long temp = 1;
        for (int j = i; j < n; j++)
        {
            temp *= A[j];
            max_now = max(temp, max_now);
        }
        
    }
    
    cout << max_now;
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