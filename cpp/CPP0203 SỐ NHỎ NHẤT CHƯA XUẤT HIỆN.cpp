#include <bits/stdc++.h>
using namespace std;

void submit()
{
    long num, a;
    cin >> num;

    vector<bool> arr(1000000, true);

    for (int i = 0; i < num; i++)
    {
        cin >> a;

        if (a >= 0)
        {
            arr[a] = false;
        }
        
    }
    
    for (int i = 1; i < 1000000; i++)
    {
        if (arr[i])
        {
            cout << i;
            break;
        }
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