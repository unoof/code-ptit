#include <bits/stdc++.h>
using namespace std;

long total_double = 0;
long total_increament = 0;

void check(int n)
{
    long temp = 0;
    while (n > 1)
    {
        if (n%2 == 1)
        {
            total_increament++;
        }
        n /= 2;
        temp++;
    }

    if (n == 1)
    {
        total_increament++;
    }
    
    if (temp > total_double)
    {
        total_double = temp;
    }
    
}

void submit()
{
    int n;
    cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    
    for (auto &&i : A)
    {
        check(i);
    }
    
    cout << total_double + total_increament;
    
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
        total_double = total_increament = 0;
        submit();
    }

    return 0;
}