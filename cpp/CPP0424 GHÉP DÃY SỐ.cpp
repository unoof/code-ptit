#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int n, k;
    cin >> k >> n;
    
    vector<long long> A(k*n);
    for (int i = 0; i < n*k; i++)
    {
        cin >> A[i];        
    }

    sort(A.begin(), A.end());

    for (long long num : A)
    {
        cout << num << " ";
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