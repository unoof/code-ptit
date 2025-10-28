#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (auto &&i : A) cin >> i;

    find(A.begin(), A.end(), k) != A.end() ? cout << 1 : cout << -1;
    
    

    
    
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