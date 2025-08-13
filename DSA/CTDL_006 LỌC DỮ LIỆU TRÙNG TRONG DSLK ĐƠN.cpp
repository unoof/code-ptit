#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int n;
    cin >> n;
    unordered_set<int> A;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        A.insert(temp);
    }

    vector<int> temp(A.begin(), A.end());
    reverse(temp.begin(), temp.end());
    for (auto &&i : temp)
    {
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