#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int n;
    cin >> n;
    int A[n];

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    
    vector<int> B;
    int highest = -1;
    
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j >= 0; j--)
        {
            if (A[i] - A[j] > highest)
            {
                highest = A[i] - A[j];
            }
            
        }
        B.push_back(highest);
    }
    
    highest = -1;
    
    for (int i : B)
    {
        if (i > highest)
        {
            highest = i;
        }
        
    }
    
    if (highest > 0)
    {
        cout << highest;
    }
    else
    {
        cout << -1;
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

    while (so_bo_test--)
    {
        submit();
    }

    return 0;
}