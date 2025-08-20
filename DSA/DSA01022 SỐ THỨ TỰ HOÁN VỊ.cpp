#include <bits/stdc++.h>
using namespace std;

long long factorial(int n)
{
    long long total = 1;
    for (int i = 1; i <= n; i++)
    {
        total *= i;
    }
    return total;
}

int check(vector<bool> A, int n)
{
    int count = 0;
    for (int i = n-1; i >= 0; i--)
    {
        if (A[i] == false)
        {
            count++;
        }
    }
    return count;
}

void submit()
{
    int n;
    long long total = 0;
    cin >> n;
    vector<bool> A(n, true);
    
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        
        total += factorial(n-i-1)*(temp-1-check(A, temp));
        A[temp-1] = false;
    }
    
    cout << total+1 << endl;

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