#include <bits/stdc++.h>
using namespace std;

void update(vector<int> &A, int n, int k)
{
    int i = k-1;
    while (A[i] == n-k+i+1)
    {
        i--;
    }

    A[i]++;

    if (i == -1)
    {
        for (int j = i+1; j < k; j++)
        {
            A[j] = j-i;
        }
    }
    else
    {
        for (int j = i+1; j < k; j++)
        {
            A[j] = A[i]+j-i;
        }
    }
}

void submit()
{
    int n, k;
    cin >> n >> k;
    vector<int> A(k);
    for (int i = 0; i < k; i++)
    {
        cin >> A[i];
    }
    update(A, n, k);
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