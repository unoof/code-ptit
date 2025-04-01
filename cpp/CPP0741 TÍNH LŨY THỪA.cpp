#include <bits/stdc++.h>
using namespace std;


void submit()
{
    int x, y , p;
    long long total = 1;
    cin >> x >> y >> p;

    for (int i = 0; i < y; i++)
    {
        total *= x%p;
        total %= p;
    }
    

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
    cin.ignore();

    while (so_bo_test--)
    {
        submit();
    }

    return 0;
}