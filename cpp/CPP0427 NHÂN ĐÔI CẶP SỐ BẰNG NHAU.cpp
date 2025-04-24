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
    

    for (int i = 1; i < n; i++)
    {
        if (A[i] == A[i-1])
        {
            A[i-1] += A[i];
            A[i] = 0;
        }
        
    }
    
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] != 0)
        {
            cout << A[i] << " ";
        }
        else
        {
            count++;
        }
    }
    
    for (int i = 0; i < count; i++)
    {
        cout << 0 << " ";
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