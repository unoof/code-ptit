#include <bits/stdc++.h>
using namespace std;

void submit()
{
    long long b;
    int p;
    cin >> b >> p;
    if (p == 1)
    {
        cout << b << endl;
    }
    
    else
    {
        long long count = 0;
        for (int r = 1; r < p; r++)
        {
            if ((long long)r * r % p == 1) 
            {
                if (r <= b)
                {
                    count += (b - r) / p + 1;
                }
            }
        }
        cout << count;
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