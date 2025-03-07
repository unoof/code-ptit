#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int num;
    long k;
    cin >> num >> k;
    long long total {0};

    for (int i = 1; i <= num; i++)
    {
        total += i%k;
        
    }
    
    if (total == k)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
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