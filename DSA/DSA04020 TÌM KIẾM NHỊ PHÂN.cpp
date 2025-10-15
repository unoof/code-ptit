#include <bits/stdc++.h>
using namespace std;

void BS_index(vector<int> &A, int left, int right, int target)
{
    if (left > right)
    {
        cout << "NO";
        return;
    }
    
    int mid = left + (right-left)/2;
    if (A[mid] < target)
    {
        return BS_index(A, mid+1, right, target);
    }
    else if (A[mid] > target)
    {
        return BS_index(A, left, mid-1, target);
    }
    else
    {
        cout << mid+1;
    }
}

void submit()
{
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (auto &&i : A)
    {
        cin >> i;
    }
    
    BS_index(A, 0, n-1, k);
    

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