#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> A, vector<int> temp, int n, int k)
{
    long long total = 0;
    for (int i = 0; i < n; i++)
    {
        if (temp[i] == 1)
        {
            total += A[i];
        }
    }
    return total == k;
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
    int n, k, count = 0;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    
    vector<int> temp(n, 0);

    for (int i = 0; i <= max(n); i++)
    {
        if (check(A, temp, n, k))
        {
            for (int i = 0; i < n; i++)
            {
                if (temp[i] == 1)
                {
                    cout << A[i] << " ";
                }
            }
            cout << endl;
            count++;
        }
        update(temp, n);
    }
    
    cout << count;
}   

int main()
{
    ios::sync_with_stdio(false);                                    // Speed up input/output
    cin.tie(nullptr);
    cout.tie(nullptr);

    submit();

    return 0;
}