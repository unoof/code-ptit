#include <bits/stdc++.h>
using namespace std;

int BS_index(vector<int> &A, int left, int right, int target)
{
    int mid = left + (right-left)/2;
    if (A[mid] == 0 && A[mid+1] == 0)
    {
        left = mid;
        return BS_index(A, left, right, target);
    }
    else if (A[mid] == 1 && A[mid-1] == 1)
    {
        right = mid-1;
        return BS_index(A, left, right, target);
    }
    else
    {
        if (A[mid] == 0 && A[mid+1] == 1)
        {
            return mid+1;
        }
        else
        {
            return mid;
        }
    }
}

void submit()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto &&i : A)
    {
        cin >> i;
    }
    
    if (A[n-1] != 1)
    {
        cout << n;
    }
    else if (A[0] == 1)
    {
        cout << 0;
    }
    else
    {
        cout << BS_index(A, 0, n-1, 1);
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