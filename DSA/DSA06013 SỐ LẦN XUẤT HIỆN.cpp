#include <bits/stdc++.h>
using namespace std;



void submit()
{
    int n, k, count = 0;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if (temp == k) count++;
    }
    
    count != 0 ? cout << count : cout << -1;
    

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