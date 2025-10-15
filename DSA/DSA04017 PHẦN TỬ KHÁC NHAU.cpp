#include <bits/stdc++.h>
using namespace std;

void submit()
{
    long long n;
    cin >> n;
    vector<long long> A(n);
    vector<long long> B(n-1);
    for (auto &&i : A)
    {
        cin >> i;
    }
    for (auto &&i : B)
    {
        cin >> i;
    }
    
    for (int i = 0; i < n; i++)
    {
        if (A[i] != B[i])
        {
            cout << i+1;
            break;
        }
    }
    
    
    
    

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