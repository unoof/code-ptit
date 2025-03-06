#include <bits/stdc++.h>
using namespace std;

int divisor_prime(int num, int a)
{
    if (num == 1 || num == 0)
    {
        return -1;
    }

    for (int i = 2; i <= sqrt(num); i++)
    {
        while (num%i == 0)
        {
            num /= i;
            a--;
            if (a == 0)
            {
                return i;
            }
        }
    }

    if (num > 1 && a == 1)
    {
        return num;
    }
    return -1;
    
}

void submit()
{
    int num;
    int a;
    cin >> num >> a;
    
    cout << divisor_prime(num, a);
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