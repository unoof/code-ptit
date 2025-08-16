#include <bits/stdc++.h>
using namespace std;

void update(vector<int> &A, int n)
{
    int i = n-2;
    while (A[i] > A[i+1])
    {
        i--;
    }
    
    if (i != -1)
    {
        int k = n-1;
        while (A[k] < A[i])
        {
            k--;
        }
        
        swap(A[i], A[k]);
        sort(A.begin() + i+1, A.end());
    }
    else
    {
        reverse(A.begin(), A.end());
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
    
    update(A, n);
    for (auto &&i : A)
    {
        cout << i << " ";
    }
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
        submit();
    }

    return 0;
}