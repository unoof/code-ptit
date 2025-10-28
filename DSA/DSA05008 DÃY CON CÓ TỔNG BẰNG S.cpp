#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &A, int n, int k)
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
    return temp[k];
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
    
    check(A, n, k) ? (cout << "YES") : (cout << "NO");



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