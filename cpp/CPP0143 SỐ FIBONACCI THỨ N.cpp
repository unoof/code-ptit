#include <bits/stdc++.h>
using namespace std;

long long fibo(int num)
{
    long long a {0};
    long long b {1};

    for (int i = 0; i < num; i++)
    {
        long long x = a;
        a += b;
        b = x;
    }

    return a;
}

void submit()
{
    int num;
    cin >> num;

    cout << fibo(num);
    
    
    
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