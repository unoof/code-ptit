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

void submit(const vector<bool>& prime)
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
            cout << i << " ";
        }
        
    }
    
}


int main()
{
    ios::sync_with_stdio(false);  // Speed up input/output
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<bool> prime = prime_num(MAX);

    submit(prime);

    return 0;
}