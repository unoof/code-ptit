#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int a, m;
    cin >> a >> m;
    bool check = false;

    for (int i = 0; i < m; i++)
    {
        if ((a*i)%m == 1)
        {
            cout << i;
            check = true;
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


    while (so_bo_test--)
    {
        submit();
    }

    return 0;
}