#include <bits/stdc++.h>
using namespace std;


void submit()
{
    long long num, total {0};
    cin >> num;

    total = num*(num+1)/2;
    
    
    cout << total;

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
