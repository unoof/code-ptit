#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int n, total {0};
    cin >> n;

    vector<int> A(n);
    vector<int> check(1000000, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        check[A[i]]++;
    }
    
    for (int i = 0; i < n; i++)
    {
        if (check[A[i]] > 1)
        {
            total += check[A[i]];
            check[A[i]] = 0;
        }
        
    }
    
    cout << total << endl;
    return;
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