#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int n, k;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    cin >> k;
    
    for (auto &&i : A)
    {
        if (i == k)
        {
            continue;
        }
        cout << i << " ";
    }
}   

int main()
{
    ios::sync_with_stdio(false);                                    // Speed up input/output
    cin.tie(nullptr);
    cout.tie(nullptr);

    submit();

    return 0;
}