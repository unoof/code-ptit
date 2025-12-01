#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int n;
    cin >> n;
    vector<int> node(n);
    for (auto &&i : node) cin >> i;
    bool check = true;
    
    for (int i = 0; i < n-1; i++)
    {
        if (node[i] >= node[i+1])
        {
            check = false;
            break;
        }
    }
    
    check ? cout << 1 : cout << 0;

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