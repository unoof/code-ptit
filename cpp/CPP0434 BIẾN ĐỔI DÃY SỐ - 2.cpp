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

    vector<long long> out(n);
    
    out[0] = A[1]*A[0];
    out[n-1] = A[n-2]*A[n-1];

    for (int i = 1; i < n-1; i++)
    {
        out[i] = A[i-1]*A[i+1];
    }
    
    for (auto &&i : out)
    {
        cout << i << " ";
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