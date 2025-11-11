#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto &&i : A) cin >> i;

    unordered_set<int> check;
    int ans = n;

    for (int i = n-1; i >= 0; i--)
    {
        if (check.count(A[i]))
        {
            if (ans > i) ans = i;
        }
        check.insert(A[i]);
    }
    
    ans != n ? cout << A[ans] : cout << "NO";


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