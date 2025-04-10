#include <bits/stdc++.h>
using namespace std;

vector<bool> prime_num()
{
    vector<bool> is_prime(100000, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i*2 <= 100000; i++)
    {
        for (int j = i*2; j <= 100000; j+=i)
        {
            is_prime[j] = false;
        }
        
    }
    return is_prime;
}

bool GCD(int num, int x)
{
    while (x != 0)
    {
        int r = num%x;
        num = x;
        x = r;
    }
    
    if (num == 1)
    {
        return true;
    }
    return false;
}

void submit()
{
    vector<bool> prime = prime_num();
    int num, count = 0;
    cin >> num;

    for (int i = 1; i <= num; i++)
    {
        if (GCD(num, i))
        {
            count++;
        }
        
    }
    
    if (prime[count])
    {
        cout << 1;
    }
    else
    {
        cout << 0;
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