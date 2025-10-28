#include <bits/stdc++.h>
using namespace std;


void submit()
{
    int n, k;
    cin >> n >> k;
    vector<int> A(n), B(k);
    for (auto &&i : A) cin >> i;
    for (auto &&i : B) cin >> i;
    
    vector<pair<bool, bool>> check(max(A[n-1]+1, B[k-1]+1), {false, false});

    for (auto &&i : A)
    {
        check[i].first = true;
    }
    for (auto &&i : B)
    {
        check[i].second = true;
    }
    
    for (int i = 0; i < check.size(); i++)
    {
        if (check[i].first || check[i].second)
        {
            cout << i << " ";
        }
    }
    cout << endl;
    for (int i = 0; i < check.size(); i++)
    {
        if (check[i].first && check[i].second)
        {
            cout << i << " ";
        }
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