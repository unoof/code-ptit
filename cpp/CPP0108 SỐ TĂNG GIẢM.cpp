#include <bits/stdc++.h>
using namespace std;

bool upnum(int num)
{
    int last = 0;
    while (num > 0)
    {
        if (num%10 > last)
        {
            last = num%10;
        }
        else
        {
            return false;
        }
        num /= 10;
    }
    return true;
}

bool downnum(int num)
{
    int last = 10;
    while (num > 0)
    {
        if (num%10 < last)
        {
            last = num%10;
        }
        else
        {
            return false;
        }
        num /= 10;
    }
    return true;
}

bool prime_num(int num)
{
    if (num < 2)
    {
        return false;
    }
    
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num%i == 0)
        {
            return false;
        }
        
    }
    return true;
}

void submit()
{
    int n, count = 0;
    cin >> n;
    
    for (int i = pow(10, n-1); i < pow(10, n); i++)
    {
        if (upnum(i) || downnum(i))
        {
            if (prime_num(i))
            {
                count++;
            }
        }
        
    }
    
    cout << count;
    
    
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