#include <bits/stdc++.h>
using namespace std;


void submit()
{
    int n, x;
    cin >> n >> x;

    vector<int> arr;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            cout << i+1;
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
    cin.ignore();

    while (so_bo_test--)
    {
        submit();
    }

    return 0;
}