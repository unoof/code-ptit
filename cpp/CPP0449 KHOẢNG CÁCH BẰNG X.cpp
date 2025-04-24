#include <bits/stdc++.h>
using namespace std;


void submit()
{
    int n, x;
    cin >> n >> x;
    
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    
    unordered_set<int> past;
    bool check = false;
    
    for (auto &&i : A)
    {
        if (past.count(i - x))
        {
            check = true;
            cout << 1;
            break;
        }
        past.insert(i);
    }
    
    if (!check)
    {
        cout << -1;
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