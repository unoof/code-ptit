#include <bits/stdc++.h>
using namespace std;


void submit()
{
    int n, start = -1, end = -1;
    cin >> n;
    vector<int> A(n);
    for (auto &&i : A) cin >> i;
    vector<int> B(A.begin(), A.end());

    sort(A.begin(), A.end());

    for (int i = 0, j = n-1; i < n, j >= 0; i++, j--)
    {
        if (A[i] != B[i] && start == -1)
        {
            start = i;
        }
        if (A[j] != B[j] && end == -1)
        {
            end = j;
        }
    }
    
    cout << start+1 << " " << end+1;
    
    


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