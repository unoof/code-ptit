#include <bits/stdc++.h>
using namespace std;

void submit()
{
    long long n, k, target;
    cin >> n >> k >> target;
    vector<long long> A(n);
    vector<long long> B(k);
    for (auto &&i : A)
    {
        cin >> i;
    }
    for (auto &&i : B)
    {
        cin >> i;
    }
    
    int pointA = 0, pointB = 0;
    while (pointA < n && pointB < k)
    {
        if (A[pointA] > B[pointB])
        {
            if (target == 1)
            {
                cout << B[pointB];
                break;
            }
            pointB++;
        }
        else if (A[pointA] < B[pointB])
        {
            if (target == 1)
            {
                cout << A[pointA];
                break;
            }
            pointA++;
        }
        else
        {
            if (target == 1)
            {
                cout << A[pointA];
                break;
            }
            pointA++;
            pointB++;
            target--;
        }
        target--;
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