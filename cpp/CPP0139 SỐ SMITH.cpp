#include <bits/stdc++.h>
using namespace std;

vector<bool> is_prime()
{
    vector<bool> prime(100001, true);
    prime[0] = prime[1] = false;

    for (long long  i = 2; i*i <= 100000; i++)
    {
        for (long long j = i*i; j <= 100000; j += i)
        {
            prime[j] = false;
        }
        
    }
    return prime;
}

long long sum_num(int n)
{
    long long total = 0;

    while (n > 0)
    {
        total += n%10;
        n /= 10;
    }
    return total;
}

long long sum_prime(int n)
{
    long long total = 0;

    for (int i = 2; i <= sqrt(n); i++)
    {
        while (n%i == 0)
        {
            n /= i;
            total += sum_num(i);
        }
    }

    if (n != 1)
    {
        total += sum_num(n);
    }
    
    return total;
}


void submit(vector<bool> prime)
{
    int n;
    cin >> n;
    bool check = false;
    
    if (!prime[n])
    {
        if (sum_num(n) == sum_prime(n))
        {
            cout << "YES";
            check = true;
        }
    }

    if (!check)
    {
        cout << "NO";
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

    vector<bool> prime = is_prime();

    while (so_bo_test--)
    {
        submit(prime);
    }

    return 0;
}