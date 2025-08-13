#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> A, int n)
{
    for (int i = 0; i <= n/2; i++)
    {
        if (A[i] != A[n-i-1])
        {
            return false;
        }
    }
    return true;
}

void update(vector<int> &A, int n)
{
    for (int i = n-1; i >= 0; i--)
    {
        if (A[i] == 0)
        {
            A[i] = 1;
            break;
        }
        else
        {
            A[i] = 0;
        }
    }
}

long long max(int n)
{
    long long total = 0;
    for (int i = 1; i <= n; i++)
    {
        total = total*2+1;
    }
    return total;
}

void submit()
{
    int n;
    cin >> n;

    vector<int> A(n, 0);

    for (int i = 0; i <= max(n); i++)
    {
        if (check(A, n))
        {
            for (auto &&i : A)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        update(A, n);
    }
    
}   

int main()
{
    ios::sync_with_stdio(false);                                    // Speed up input/output
    cin.tie(nullptr);
    cout.tie(nullptr);

    submit();

    return 0;
}