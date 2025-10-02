#include <bits/stdc++.h>
using namespace std;

char kthChar(vector<long long> &A, int n, long long k)
{
    if (n == 1) return 'A';
    if (n == 2) return 'B';

    if (k <= A[n-2])
    {
        return kthChar(A, n-2, k);
    }
    else
    {
        return kthChar(A, n-1, k - A[n-2]);
    }
}
    
void submit()
{
    long long n, k, count = 3;
    cin >> n >> k;
    vector<long long> A(n+1);
    A[1] = A[2] = 1;
    
    for (int i = 3; i <= n; i++)
    {
        A[i] = A[i-2] + A[i-1];
        count++;
        if (A[i] >= k)
        {
            A.resize(count);
            break;
        }
        
    }
    cout << kthChar(A, count, k);

    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);                                    // Speed up input/output
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test;
    cin >> test;
    while (test--)
    {
        submit();
    }
    

    return 0;
}