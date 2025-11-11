#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int n, m, p;
    cin >> n >> m >> p;
    vector<int> A(n);
    for (auto &&i : A) cin >> i;
    vector<int> B(n);
    for (auto &&i : B) cin >> i;
    vector<int> C(n);
    for (auto &&i : C) cin >> i;

    int i = 0, j = 0, k = 0;

    vector<int> ans;
    bool check = false;

    while (i < n && j < m && k < p)
    {
        if (A[i] == B[j] && B[j] == C[k])
        {
            check = true;
            ans.push_back(A[i]);
            i++, j++, k++;
        }
        else if (A[i] < B[j])
        {
            i++;
        }
        else if (B[j] < C[k])
        {
            j++;
        }
        else
        {
            k++;
        }
    }
    
    if (check)
    {
        for (auto &&i : ans)
        {
            cout << i << " ";
        }
    }
    else
    {
        cout << -1;
    }
    
    


    cout << endl;
}


int main()
{
    ios::sync_with_stdio(false);                                    // Speed down input/output
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