#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto &&i : A) cin >> i;
    vector<vector<int>> res;
    vector<int> ans;
    
    for (int i = 0; i < n; i++)
    {
        ans.push_back(A[i]);
        for (int j = 0; j < ans.size(); j++)
        {
            if (ans[j] > A[i])
            {
                swap(ans[j], ans[ans.size()-1]);
            }
        }

        res.push_back(ans);
    }
    
    for (int i = res.size()-1; i >= 0; i--)
    {
        
        cout << "Buoc " << i << ": ";
        for (auto &&k : res[i]) cout << k << " ";
        cout << endl;
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