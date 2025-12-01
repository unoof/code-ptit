#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int n;
    cin >> n;
    vector<int> node(n);
    for (auto &&i : node) cin >> i;

    sort(node.begin(), node.end());


    cout << node[(n-1)/2];

    

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