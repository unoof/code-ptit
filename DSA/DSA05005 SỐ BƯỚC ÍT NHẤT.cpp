#include <bits/stdc++.h>
using namespace std;


void check(vector<int> &A, int n)
{
    vector<int> temp(n, 1);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (A[j] <= A[i])
            {
                temp[i] = max(temp[i], temp[j]+1);
            }
        }
    }

    cout << n - *max_element(temp.begin(), temp.end()) << endl;
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
    
    check(A, n);
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