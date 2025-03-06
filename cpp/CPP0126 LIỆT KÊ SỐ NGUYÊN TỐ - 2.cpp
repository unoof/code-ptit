#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000000;

vector<bool> prime_num(int max)                                 //Using sieve of eratosthenes to have numbers check if prime or not
{
    vector<bool> is_prime(max + 1, true);

    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i*i <= max; i++)
    {
        if (is_prime[i])
        {
            for (int j = i*i; j <= max; j+=i)
            {
                is_prime[j] = false;
            }
            
        }
        
    }
    return is_prime;
}

void submit(vector<bool> prime)
{
    int a, b;
    cin >> a >> b;

    if (a > b)
    {
        swap(a, b);
    }
    
    for (int i = a; i <= b; i++)
    {
        if (prime[i])
        {
            cout << i << "  ";
        }
        
    }
    

    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);                                    // Speed up input/output
    cin.tie(nullptr);
    cout.tie(nullptr);

    int so_bo_test;
    cin >> so_bo_test;

    vector<bool> prime = prime_num(MAX);

    while (so_bo_test--)
    {
        submit(prime);
    }

    return 0;
}