#include <bits/stdc++.h>
using namespace std;


void submit()
{
    int n, save;
    cin >> n;
    bool check = false;

    vector<bool> A(1000000, false);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (!A[x])
        {
            A[x] = true;
        }
        else if (A[x] && !check)
        {
            save = x;
            check = true;
        }
    }
    
    if (!check)
    {
        cout << -1;
    }
    else
    {
        cout << save;
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