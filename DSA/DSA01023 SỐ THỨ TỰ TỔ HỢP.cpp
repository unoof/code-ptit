#include <bits/stdc++.h>
using namespace std;

long long c(int k, int n)
{
    if (k > n)
    {
        return 0;
    }
    
    long long total = 1;
    for (int i = 1; i <= k; i++)
    {
        total *= (n-i+1);
        total /= i;
    }
    
    return total;
}

void submit()
{
    int n, k, last = 0;
    long long total = 1;
    cin >> n >> k;
    
    for (int i = 0; i < k; i++)
    {
        int temp;
        cin >> temp;
        
        for (int j = last+1; j < temp; j++)
        {
            total += c(k-i-1, n-j);
        }
        last = temp;
    }
    
    cout << total << endl;

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