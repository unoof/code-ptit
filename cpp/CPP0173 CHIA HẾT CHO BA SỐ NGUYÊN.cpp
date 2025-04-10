#include <bits/stdc++.h>
using namespace std;

int GCD(int num, int x)
{
    while (x != 0)
    {
        int r = num%x;
        num = x;
        x = r;
    }
    
    return num;
}

long long LCM(long long a, long long b)
{
    return (a / GCD(a, b)) * b;
}

void submit()
{
    int x, y, z, n;
    cin >> x >> y >> z >> n;
    long long start = 1;
    long long end = 1;

    long long L = LCM(x, LCM(y, z));

    for (int i = 0; i < n; i++)
    {
        start *= 10;
        end *= 10;
    }
    start /= 10;

    long long temp1 = start%L;
    long long temp2;

    if (temp1 == 0)
    {
        temp2 = start;
    }
    else
    {
        temp2 = start + (L - temp1);
    }
    
    if (temp2 < end)
    {
        cout << temp2;
    }
    else
    {
        cout << -1;
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