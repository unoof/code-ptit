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
    
    int i = n-2;
    while (A[i] < A[i+1])
    {
        i--;
    }

    if (i >= 0)
    {
        int k = n-1;
        while (A[i] < A[k])
        {
            k--;
        }
        swap(A[i], A[k]);
        
        for (int j = i+1, m = n-1; j < m; j++, m--)
        {
            swap(A[j], A[m]);
        }
    }
    else
    {
        for (int i = n; i > 0; i--)
        {
            A[n-i] = i;
        }
        
    }
    

    for (auto &&i : A)
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