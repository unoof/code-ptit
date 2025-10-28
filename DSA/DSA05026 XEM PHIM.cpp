#include <bits/stdc++.h>
using namespace std;

int check(vector<int> &A, int n, int k)
{
    vector<bool> temp(k+1, false);
    temp[0] = true;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = k; j >= A[i]; j--)
        {
            if (temp[j-A[i]])
            {
                temp[j] = true;
            }
        }
    }
    
    for (int i = k - 1; i >= 0; i--)
    {
        if (temp[i])
        {
            return i;
        }
    }
}

void submit()
{
    int k, n;
    cin >> k >> n;
    vector<int> A(n);
    for (auto &&i : A)
    {
        cin >> i;
    }
    
    cout << check(A, n, k);
}

int main()
{
    ios::sync_with_stdio(false);                                    // Speed up input/output
    cin.tie(nullptr);
    cout.tie(nullptr);

    submit();

    return 0;
}