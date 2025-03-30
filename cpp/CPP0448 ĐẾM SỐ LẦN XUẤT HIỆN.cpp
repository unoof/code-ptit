#include <bits/stdc++.h>
using namespace std;


void submit()
{
    int n, k, count = 0;
    cin >> n >> k;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];

        if (arr[i] == k)
        {
            count++;
        }
        
    }

    if (count == 0)
    {
        cout << -1;
    }
    else
    {
        cout << count;
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