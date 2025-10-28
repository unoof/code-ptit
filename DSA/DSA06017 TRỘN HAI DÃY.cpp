#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int n, m;
    cin >> n >> m;
    vector<long long> A(n);
    vector<long long> B(m);
    for (auto &&i : A) cin >> i;
    for (auto &&i : B) cin >> i;

    vector<long long> C(A.begin(), A.end());

    for (auto &&i : B) C.push_back(i);

    sort(C.begin(), C.end());
    
    for (auto &&i : C) cout << i << " ";
    
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