#include <bits/stdc++.h>
using namespace std;

void check_prime(long long num)
{
    if (num < 2)
    {
        cout << num;
    }
    
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num%i == 0)
        {
            cout << i << " ";
            int count {0};

            while (num%i == 0)
            {
                count ++;
                num /= i;
            }

            cout << count << " ";
        }
    }

    if (num != 1)
    {
        cout << num << " " << 1;
    }
    
}

void submit()
{
    long long num;
    cin >> num;

    check_prime(num);

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