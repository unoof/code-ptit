#include <bits/stdc++.h>
using namespace std;

bool recursion(vector<int> A, int n)
{
    if (A.size() == 1)
    {
        return false;
    }
    
    for (int i = 0; i < n-1; i++)
    {
        A[i] = A[i]+A[i+1];
    }
    A.erase(A.end()-1);
    n = A.size();
    
    if (!recursion(A, n))
    {
        cout << "[" << A[0];
        for (int i = 1; i < n; i++)
        {
            cout << " " << A[i];
        }
        cout << "] ";
        return false;
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
    
    recursion(A, n);
    cout << "[" << A[0];
    for (int i = 1; i < n; i++)
    {
        cout << " " << A[i];
    }
    cout << "]" << endl;
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