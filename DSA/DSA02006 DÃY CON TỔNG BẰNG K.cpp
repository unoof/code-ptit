#include <bits/stdc++.h>
using namespace std;

bool found = false;

void recursion(vector<int> A, int n, int k, int start, int total, vector<int> ans)
{
    for (int i = start; i < n; i++)
    {
        total += A[i];
        ans.push_back(A[i]);

        if (total > k)
        {
            return;
        }
        if (total == k)
        {
            cout << "[" << ans[0];
            for (int j = 1; j < ans.size(); j++)
            {
                cout << " " << ans[j];
            }
            cout << "] ";
            found = true;
            return;
        }
        recursion(A, n, k, i+1, total, ans);
        total -= A[i];
        ans.erase(ans.end()-1);
    }
}

void submit()
{
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (auto &&i : A)
    {
        cin >> i;
    }
    sort(A.begin(), A.end());
    vector<int> ans;

    recursion(A, n, k, 0, 0, ans);
    if (!found)
    {
        cout << -1;
    }
    
    cout << endl;
    found = false;
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