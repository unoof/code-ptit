#include <bits/stdc++.h>
using namespace std;


void submit()
{
    int n;
    cin >> n;
    
    set<long long> store;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        while (a > 0)
        {
            store.insert(a%10);
            a /= 10;
        }
    }
    
    for (int index : store)
    {
        cout << index << " ";
    }
    
    
    
    
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