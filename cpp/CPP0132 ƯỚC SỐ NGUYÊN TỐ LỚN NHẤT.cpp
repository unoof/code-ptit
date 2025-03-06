#include <bits/stdc++.h>
using namespace std;

void divisor_prime(long long num)
{
    if (num == 1)
    {
        cout << num;
    }
    long max = 0;

    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num%i == 0)
        {
            if (max < i)
            {
                max = i;
            }
            while (num%i == 0)
            {
                num /= i;
            }
        }
        
    }
    
    if (max < num)
    {
        cout << num;
    }
    else
    {
        cout << max;
    }
    
}

void submit()
{
    long long num;
    cin >> num;
    
    divisor_prime(num);
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