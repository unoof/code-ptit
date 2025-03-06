#include <bits/stdc++.h>
using namespace std;

void divisor_prime(long num)
{
    if (num == 1 || num ==0)
    {
        cout << num;
    }

    for (int i = 2; i <= sqrt(num); i++)
    {
        while (num%i == 0)
        {
            cout << i << "  ";
            num /= i;
        }
        
    }
    
    if (num != 1)
    {
        cout << num;
    }
    
}

void submit()
{
    long num;
    cin >> num;
    

    divisor_prime(num);
    cout << "\n";
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