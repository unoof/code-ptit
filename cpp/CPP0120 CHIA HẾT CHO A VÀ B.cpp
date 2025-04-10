#include <bits/stdc++.h>
using namespace std;

int GCD(int a, int b)
{
    while (b != 0)
    {
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}


void submit()
{
    int m, n, a, b;
    cin >> m >> n >> a >> b;

    int min_a = (m-1)/a, min_b = (m-1)/b;
    int max_a = n/a, max_b = n/b;

    long LCM = (a*b)/GCD(a, b);
    int same = n/LCM - (m-1)/LCM;
    
    cout << (max_a-min_a) + (max_b-min_b) - same;

    
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