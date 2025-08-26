#include <bits/stdc++.h>
using namespace std;

void recursion(vector<int> &A, int &n)
{
    if (A.size() == 1)
    {
        return;
    }
    
    for (int i = 0; i < n-1; i++)
    {
        A[i] = A[i]+A[i+1];
    }
    A.erase(A.end()-1);
    n = A.size();

    cout << "[" << A[0];
    for (int i = 1; i < n; i++)
    {
        cout << " " << A[i];
    }
    cout << "]" << endl;
    recursion(A, n);
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
    
    cout << "[" << A[0];
    for (int i = 1; i < n; i++)
    {
        cout << " " << A[i];
    }
    cout << "]" << endl;

    recursion(A, n);
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