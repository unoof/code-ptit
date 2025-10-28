#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int n, count = 0;
    cin >> n;
    vector<int> A(n);
    for (auto &&i : A) cin >> i;

    sort(A.begin(), A.end());
    vector<bool> C(A[n-1]+1, false);

    for (int i = 0; i < n; i++)
    {
        C[A[i]] = true;
    }
    
    bool start = false;
    for (int i = 0; i < A[n-1]+1; i++)
    {
        if (!start && C[i])
        {
            start = true;
        }
        else if (start && !C[i])
        {
            count++;
        }
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