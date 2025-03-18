#include <bits/stdc++.h>
using namespace std;


void submit()
{
    int n, m;
    cin >> n >> m;

    long min = INT32_MAX, max = INT32_MIN;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        if (a > max)
        {
            max = a;
        }
        
    }
    
    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;

        if (a < min)
        {
            min = a;
        }
        
    }
    
    cout << max*min;
    
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