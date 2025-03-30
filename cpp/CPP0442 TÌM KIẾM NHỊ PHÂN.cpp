#include <bits/stdc++.h>
using namespace std;


void submit()
{
    int n, k;
    cin >> n >> k;
    bool check = false;

    vector<int> A(n);

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    
    for (int i = 0; i < n; i++)
    {
        if (A[i] == k)
        {
            check = true;
            cout << 1;
            break;
        }
        
    }
    
    if (!check)
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
    cin.ignore();

    while (so_bo_test--)
    {
        submit();
    }

    return 0;
}